#include "stdafx.h"
#include "windows.h"

#include <semaphore>
#include <thread>
#include <vector>

std::vector<int> myVec{};


std::counting_semaphore<1> prepareSignal(0);              

void prepareWork() {

	using namespace std::literals::chrono_literals;

	myVec.insert(myVec.end(), { 0, 1, 0, 3 });
	std::this_thread::sleep_for(3s);
	std::cout << "Sender: Data prepared." << '\n';
	prepareSignal.release();                              
}

void completeWork() {

	std::cout << "Waiter: Waiting for data." << '\n';
	prepareSignal.acquire();                              
	myVec[2] = 2;
	std::cout << "Waiter: Complete the work." << '\n';
	for (auto i : myVec) std::cout << i << " ";
	std::cout << '\n';

}

int main() {

	std::cout << '\n';

	std::thread t1(prepareWork);
	std::thread t2(completeWork);

	t1.join();
	t2.join();

	std::cout << '\n';

}


/*
*** Vyukovy program pro laboratore z predmetu Operacni systemy, Petr Frantis, UO Brno, K-209 ***


BOOL STOP_THREAD_SIGNAL = FALSE; // globalni promena, jestlize TRUE tak chceme ukoncit beh vlakna
HANDLE semafor; // globalni promena mutex, bude pouzita pro synchronizaci vlaken

DWORD WINAPI ThreadFunc(LPVOID lpParam)
{
	int i = 0;
	DWORD parametr;

	parametr = *(DWORD*)lpParam; // zkopirujeme hodnotu na adrese lpParam do lokalni promenne
	delete (DWORD*)lpParam; // uvolnime pamet parametru

	printf("Parameter = %d. \n", parametr);
	do {
		if (WaitForSingleObject(semafor, INFINITE) == WAIT_OBJECT_0) { // Pockame az bude semafor volny
			printf("%d\r", i);
			ReleaseSemaphore(semafor, 1, NULL); // Signalizujeme ze jsme uvolnili semafor
		}
		i++;
		//Sleep(200);
	} while (STOP_THREAD_SIGNAL == FALSE);

	if (WaitForSingleObject(semafor, INFINITE) == WAIT_OBJECT_0) { // Pockame az bude semafor volny
		printf("Dosazen signal ukonceni vlakna cislo 1 ...\n");
		ReleaseSemaphore(semafor, 1, NULL); // Signalizujeme ze jsme uvolnili semafor
	}

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
		if (WaitForSingleObject(semafor, INFINITE) == WAIT_OBJECT_0) { // Pockame az bude semafor volny
			printf("\t%d\r", i);
			ReleaseSemaphore(semafor, 1, NULL); // Signalizujeme ze jsme uvolnili semafor
		}
		i++;
		//Sleep(200);
	} while (STOP_THREAD_SIGNAL == FALSE);

	if (WaitForSingleObject(semafor, INFINITE) == WAIT_OBJECT_0) { // Pockame az bude semafor volny
		printf("Dosazen signal ukonceni vlakna cislo 2 ...\n");
		ReleaseSemaphore(semafor, 1, NULL); // Signalizujeme ze jsme uvolnili semafor
	}

	return 0;
}




int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hThread; // Handle na vytvorene vlakno
	HANDLE hThread2; // Handle na druhe vytvorene vlakno
	DWORD* parametr; // lokalni parametr pro vlakno 

	semafor = CreateSemaphore(
		NULL,                       // no security attributes
		1,
		1,                      // vytvoren jako volny
		"MujSemafor");  // jmeno semaforu - kdyz ho chceme najit z jineho procesu



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

	CloseHandle(hThread); // UVolnime systemove prostredky
	CloseHandle(hThread2); // UVolnime systemove prostredky

	CloseHandle(semafor);

	return 0;
}
*/