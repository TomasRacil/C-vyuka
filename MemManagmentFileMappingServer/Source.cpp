#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>
#include <string>

#define BUF_SIZE 256
TCHAR szName[] = TEXT("Global\\MyFileMappingObject");
TCHAR szMsg[] = TEXT("Message from first process. Toto je zprava z naseho serveru.");

int _tmain()
{
	std::cout<<"Vytvorime file mapping objekt pro sdileni pameti mezi procesy .... \n\n";
    HANDLE hMapFile;
    LPCTSTR pBuf;

    hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,    // use paging file
        NULL,                    // default security
        PAGE_READWRITE,          // read/write access
        0,                       // minimum object size (high-order DWORD)
        BUF_SIZE,                // maximum object size (low-order DWORD)
        szName);                 // name of mapping object

    if (hMapFile == NULL)
    {
		std::cout << "Nemohu vytvorit file mapping objekt.\n" << GetLastError();
        return 1;
    }
    pBuf = (LPTSTR)MapViewOfFile(hMapFile,   // handle to map object
        FILE_MAP_ALL_ACCESS, // read/write permission
        0,
        0,
        BUF_SIZE);

    if (pBuf == NULL)
    {
		std::cout << "Nemohu namapovat file mapping objekt do pameti.\n" << GetLastError();
        CloseHandle(hMapFile);

        return 1;
    }
	std::cout << "Uspesne jsme vytvorili a namapovali sdilenou oblast, nyni ji muzeme sdilet mezi procesy, stiskni cokoliv pro vypsani obsahu pameti \n";


	CopyMemory((PVOID)pBuf, szMsg, (_tcslen(szMsg) * sizeof(TCHAR)));
	_getch();

	std::wstring w;
	w = pBuf;
	std::string s = std::string(w.begin(), w.end());
	std::cout<< s;
	//std::cout<<"\nObsah vypsan. Stiskni cokoliv pro ukonceni.\n";
    
	bool run = true;
	while (run) {
		std::cout << "\nChces prijmout nebo poslat zpravu? (1 - prijmout, 2 - poslat, any key - ukoncit program)\n";
		char option;
		
		std::string top;
		std::getline(std::cin, top);
		option = top[0];

		std::string msg;
		std::wstring wmsg;
		const wchar_t* wcstrmsg;

		switch (option)
		{
		case '1':
			w = pBuf;
			s = std::string(w.begin(), w.end());
			std::cout << s;
			break;
		case '2':
			std::cout << "Zadej zpravu: ";
			/*std::cin >> msg;*/
			std::getline(std::cin, msg);
			wmsg = std::wstring(msg.begin(), msg.end());
			wcstrmsg = wmsg.c_str();
			//CopyMemory((PVOID)pBuf, wcstrmsg, BUF_SIZE);
			CopyMemory((PVOID)pBuf, wcstrmsg, (_tcslen(wcstrmsg) * sizeof(TCHAR)));
			break;
		default:
			run = false;
			break;
		}
	}


	_getch();
    UnmapViewOfFile(pBuf);

    CloseHandle(hMapFile);

    return 0;
}

/*
*** Vyukovy program pro laboratore z predmetu Operacni systemy, Petr Frantis, UO Brno, K-209 ***

#include "stdafx.h"
#include "windows.h"
#include "conio.h"


int _tmain(int argc, _TCHAR* argv[])
{
	printf("Vytvorime file mapping objekt pro sdileni pameti mezi procesy .... \n\n");

	HANDLE hMapFile;

	hMapFile = CreateFileMapping(INVALID_HANDLE_VALUE,    // chceme vytvorit sdilenou pamet, ne namapovat fyzicky soubor
		NULL,                              // default security
		PAGE_READWRITE,                    // read/write opravneni
		0,                                 // velikost high integer
		1024,                                 // velikost low integer
		"MyFileMappingObject");            // jmeno objektu, bude pouzito v druhem procesu jako identifikator teto sdilene pameti

	if (hMapFile == NULL)
	{
		printf("Nemohu vytvorit file mapping objekt.\n");
		return(-1);
	}

//**** ted si namapujeme sdilenou pamet do fyzicke pameti - a ziskame na ni ukazatel
	LPVOID lpMapAddress;
	lpMapAddress = MapViewOfFile(hMapFile, // handle na mapping object
		FILE_MAP_ALL_ACCESS,               // read/write opravneni
		0,                                 // high integer offsetu v souboru
		0,                                 // low integer offsetu v souboru (pozice od pocatku, musi odpovidat nasobku granuality velikosti stranek)
		0);                                // namapujeme cely soubor

	if (lpMapAddress == NULL)
	{
		printf("Nemohu namapovat file mapping objekt do pameti.\n");
		return(-1);
	}

	printf("Uspesne jsme vytvorili a namapovali sdilenou oblast, nyni ji muzeme sdilet mezi procesy, stiskni cokoliv pro vypsani obsahu pameti \n");

	while (!_kbhit());

	printf("%s",lpMapAddress);
	printf("\nObsah vypsan. Stiskni cokoliv pro ukonceni.\n");
	_getch();

	while (!_kbhit());

	UnmapViewOfFile(lpMapAddress); // *** musime zavolat! jinak system drzi stranku v pameti
	CloseHandle(hMapFile); //*** Uvolnime sdilene prostredky


	return 0;
}
*/