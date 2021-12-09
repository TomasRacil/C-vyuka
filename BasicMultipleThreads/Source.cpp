#include <thread>
//#include <future>
#include <windows.h>
#include "stdafx.h"

static bool STOP_THREAD_SIGNAL = false;

int ThreadFunc(int lpParam)
{
	using namespace std::literals::chrono_literals;

	int i = lpParam;

	std::cout << "Parameter = " << lpParam << ". \n";
	do {
		std::cout << i << '\r' << std::flush;
		i++;
		std::this_thread::sleep_for(0.5s);
	} while (!STOP_THREAD_SIGNAL);
	std::cout << "Dosazen signal ukonceni vlakna...\n";

	return 0;
}

int main()
{
	int parametr = 10;
	std::cout<<"Vytvorime vlakno 1 ... \n";

	//std::future<int> task = std::async(&ThreadFunc,parametr);
	std::thread th1(ThreadFunc,parametr);

	if (!th1.joinable())
	{
		std::cout<<"Nepodarilo se vytvorit vlakno!\n";
	}


	Sleep(6000);

	std::cout<<"Vytvorime vlakno 2 ... \n";

	parametr = 100;

	std::thread th2(ThreadFunc, parametr);

	if (!th2.joinable())
	{
		std::cout<<"Nepodarilo se vytvorit vlakno 2!\n";
	}



	Sleep(10000);
	std::cout<<"\nSignalizujeme ukonceni vlakna...\n";
	STOP_THREAD_SIGNAL = true;
	
	th1.join(); // cekame na signal ze vlakno je ukonceno
	th2.join(); // cekame na signal ze vlakno je ukonceno

	//std::cout<<"\nVlakno ukonceno s navratovou hodnotou : %d...\n"<<task.get();


	return 0;
}

/*
*** Vyukovy program pro laboratore z predmetu Operacni systemy, Petr Frantis, UO Brno, K-209 ***
#include "stdafx.h"
#include "windows.h"



BOOL STOP_THREAD_SIGNAL = FALSE; // globalni promena, jestlize TRUE tak chceme ukoncit beh vlakna


DWORD WINAPI ThreadFunc(LPVOID lpParam)
{
	int i = 0;
	DWORD parametr;

	parametr = *(DWORD*)lpParam; // zkopirujeme hodnotu na adrese lpParam do lokalni promenne
	delete (DWORD*)lpParam; // uvolnime pamet parametru

	printf("Parameter = %d. \n", parametr);
	do {
		printf("%d\r", i);
		i++;
		//Sleep(200);
	} while (STOP_THREAD_SIGNAL == FALSE);

	printf("Dosazen signal ukonceni vlakna...\n");
	return 0;
}



DWORD WINAPI ThreadFunc2(LPVOID lpParam)
{
	int i = 0;
	DWORD parametr;

	parametr = *(DWORD*)lpParam; // zkopirujeme hodnotu na adrese lpParam do lokalni promenne
	delete (DWORD*)lpParam; // uvolnime pamet parametru

	printf("Parameter = %d. \n", parametr);
	do {
		printf("%d\r", i);
		i++;
		//Sleep(200);
	} while (STOP_THREAD_SIGNAL == FALSE);

	printf("Dosazen signal ukonceni vlakna...\n");
	return 0;
}




int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hThread; // Handle na vytvorene vlakno
	HANDLE hThread2; // Handle na druhe vytvorene vlakno
	DWORD* parametr; // lokalni parametr pro vlakno 

	printf("Vytvorime vlakno 1 ... \n");

	parametr = new DWORD;
	*parametr = 10;

	hThread = CreateThread(
		NULL,                        // default security attributes 
		0,                           // default velikost zasobniku  
		ThreadFunc,                  // obsluzna funkce vlakna - pocatecni bod
		parametr,                // parametr predany funkci vlakna
		0,                           // pouzij default creation flags - vlakno bude spusteno hned po vytvoreni 
		NULL);                // promena kde bude vracen identifikator vlakna thread (muze byt NULL kdyz zadny nepotrebujeme)

   // Zkontrolujeme jestli jsme uspeli, od tohoto bodu uz nas program pracuje paralelne

	if (hThread == NULL)
	{
		printf("Nepodarilo se vytvorit vlakno!\n");
	}


	Sleep(2000);

	printf("Vytvorime vlakno 2 ... \n");

	parametr = new DWORD;
	*parametr = 20;

	hThread2 = CreateThread(
		NULL,                        // default security attributes 
		0,                           // default velikost zasobniku  
		ThreadFunc2,                  // obsluzna funkce vlakna - pocatecni bod
		parametr,                // parametr predany funkci vlakna
		0,                           // pouzij default creation flags - vlakno bude spusteno hned po vytvoreni 
		NULL);                // promena kde bude vracen identifikator vlakna thread (muze byt NULL kdyz zadny nepotrebujeme)

   // Zkontrolujeme jestli jsme uspeli, od tohoto bodu uz nas program pracuje paralelne

	if (hThread2 == NULL)
	{
		printf("Nepodarilo se vytvorit vlakno 2!\n");
	}


	Sleep(2000);



	
	   SuspendThread(hThread);
	   printf("\nVlakno pozastaveno ... \n");

	   Sleep(2000);
	   ResumeThread(hThread);
	   printf("\nVlakno znovu obnoveno .... \n");

	   Sleep(2000);
	
	SetThreadPriority(hThread, THREAD_PRIORITY_IDLE); // POZOR pri zadavani prilis vysoke priority, muzete zpusobit problemy OS
	printf("\nSnizena priorita ...\n");

	Sleep(2000);
	printf("\nSignalizujeme ukonceni vlakna...\n");
	STOP_THREAD_SIGNAL = TRUE;

	WaitForSingleObject(hThread, INFINITE); // cekame na signal ze vlakno je ukonceno
	WaitForSingleObject(hThread2, INFINITE); // cekame na signal ze vlakno je ukonceno

	DWORD exitcode;
	GetExitCodeThread(hThread, &exitcode);
	Sleep(2000);
	printf("\nVlakno ukonceno s navratovou hodnotou : %d...\n", exitcode);

	CloseHandle(hThread);
	CloseHandle(hThread2);// UVolnime systemove prostredky

	return 0;
}
*/