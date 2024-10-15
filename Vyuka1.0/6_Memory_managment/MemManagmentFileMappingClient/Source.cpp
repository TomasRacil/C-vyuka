#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#pragma comment(lib, "user32.lib")

#define BUF_SIZE 256
TCHAR szName[] = TEXT("Global\\MyFileMappingObject");

int _tmain()
{
    HANDLE hMapFile;
    LPCTSTR pBuf;

    hMapFile = OpenFileMapping(
        FILE_MAP_ALL_ACCESS,   // read/write access
        FALSE,                 // do not inherit the name
        szName);               // name of mapping object

    if (hMapFile == NULL)
    {
        _tprintf(TEXT("Could not open file mapping object (%d).\n"),
            GetLastError());
        return 1;
    }

    pBuf = (LPTSTR)MapViewOfFile(hMapFile, // handle to map object
        FILE_MAP_ALL_ACCESS,  // read/write permission
        0,
        0,
        BUF_SIZE);

    if (pBuf == NULL)
    {
        _tprintf(TEXT("Could not map view of file (%d).\n"),
            GetLastError());

        CloseHandle(hMapFile);

        return 1;
    }

    //MessageBox(NULL, pBuf, TEXT("Process2"), MB_OK);

	std::wstring w;
	w = pBuf;
	std::string s = std::string(w.begin(), w.end());

	std::cout << s;
	//std::cout<<"\nRetezec preneseny, sdilena pamet je totiz koherentni, co zapise jeden proces to hned vidi ten druhy \n";

	//while (!_kbhit());
	//std::cout<<"\nObsah vypsan. Stiskni cokoliv pro ukonceni.\n";

	bool run = true;
	while (run) {
		std::cout << "\nChces prijmout nebo poslat zpravu? (1 - prijmout, 2 - poslat, any key - ukoncit program)\n";
		char option;
		std::string msg;
		std::wstring wmsg;
		const wchar_t* wcstrmsg;
		std::string top;
		std::getline(std::cin, top);
		option = top[0];
		switch (option)
		{
		case '1':
			w = pBuf;
			s = std::string(w.begin(), w.end());
			std::cout << s;
			break;
		case '2':
			std::cout << "Zadej zpravu: ";
			//std::cin >> msg;
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

	printf("Otevreme sdilenou pamet z druheho procesu pres file mapping a zapiseme do ni retezec.\n\n");

	HANDLE hMapFile;
	LPVOID lpMapAddress;

	hMapFile = OpenFileMapping(FILE_MAP_ALL_ACCESS, // read/write opravneni
		FALSE,                             // Do not inherit the name
		"MyFileMappingObject");            // jmeno sdileneho file mapping objektu

	if (hMapFile == NULL)
	{
		printf("Nemohu otevrit file mapping objekt, je druhy proces spusten?\n.");
		return(-1);
	}

	//*** namapujeme jej do pameti
	lpMapAddress = MapViewOfFile(hMapFile, // handle na mapping object
		FILE_MAP_ALL_ACCESS,               // read/write opravneni
		0,                                 // high int
		0,                                 // low int offsetu od zacatku .....pozor na granuralitu velikosti stranek
		0);                                // mapujeme cely soubor

	if (lpMapAddress == NULL)
	{
		printf("Nemohu namapovat file mapping objekt do pameti.\n");
		return(-1);
	}

	//******

	printf("\nNyni mame oba procesy propojeny pres sdilenou pamet, zadej retez pro preneseni do druheho procesu: ");
	//gets((char *)lpMapAddress);

	printf("Retezec preneseny, sdilena pamet je totiz koherentni, co zapise jeden proces to hned vidi ten druhy \n");

	while (!_kbhit());

	UnmapViewOfFile(lpMapAddress); // *** musime zavolat! jinak system drzi stranku v pameti
	CloseHandle(hMapFile); //*** Uvolnime sdilene prostredky

	return 0;
}

*/