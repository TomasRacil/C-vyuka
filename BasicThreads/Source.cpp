#include "stdafx.h"
#include "windows.h"
#include <thread>

static bool s_Finished = false;

int ThreadFunc(int lpParam)
{
	using namespace std::literals::chrono_literals;
	int i = 0;

	std::cout << "Parameter = " << lpParam << ". \n";
	do {
		std::cout << i << '\r' << std::flush;
		i++;
		std::this_thread::sleep_for(0.5s);
	} while (!s_Finished);

	return 0;
}
int main()
{
	//int dwThreadId; // Identifikator vlakna - obvykle nepotrebujeme
	int parametr = 10; // lokalni parametr pro vlakno - POZOR, muze byt problem pokud fuknce ze ktere vlakno vytvarime skonci driv, nez vlakno zpracuje tento parametr (tato lokalni promena zanikne a vlakno se bude odkazovat na neexistujici misto v pameti), resi se to dynamickou alokaci prommene!


	std::cout << "Vytvorime vlakno ... \n";

	std::thread th1(ThreadFunc, parametr);

	// Zkontrolujeme jestli jsme uspeli, od tohoto bodu uz nas program pracuje paralelne

	if (!th1.joinable())
	{
		std::cout << "Nepodarilo se vytvorit vlakno!\n";
	}

	Sleep(6000);
	//thread nám neumožòuje pøerušit, obnovit ani terminovat vlákno
	s_Finished = true;
	th1.join();
	std::cout<<"\nVlakno "<<th1.get_id()<<" ukonceno...\n";

	return 0;
}


/*
*** Vyukovy program pro laboratore z predmetu Operacni systemy, Petr Frantis, UO Brno, K-209 ***
#include "stdafx.h"
#include "windows.h"


DWORD WINAPI ThreadFunc(LPVOID lpParam)
{
	int i = 0;

	printf("Parameter = %d. \n", *(DWORD*)lpParam);
	do {
		printf("%d\r", i);
		i++;
	} while (TRUE);

	return 0;
}



int _tmain(int argc, _TCHAR* argv[])
{
	HANDLE hThread; // Handle na vytvorene vlakno
	DWORD dwThreadId; // Identifikator vlakna - obvykle nepotrebujeme
	int parametr = 10; // lokalni parametr pro vlakno - POZOR, muze byt problem pokud fuknce ze ktere vlakno vytvarime skonci driv, nez vlakno zpracuje tento parametr (tato lokalni promena zanikne a vlakno se bude odkazovat na neexistujici misto v pameti), resi se to dynamickou alokaci prommene!


	printf("Vytvorime vlakno ... \n");

	hThread = CreateThread(
		NULL,                        // default security attributes 
		0,                           // default velikost zasobniku  
		ThreadFunc,                  // obsluzna funkce vlakna - pocatecni bod
		&parametr,                // parametr predany funkci vlakna - POZOR na pouziti lokalnich promennych!
		0,                           // pouzij default creation flags - vlakno bude spusteno hned po vytvoreni 
		&dwThreadId);                // promena kde bude vracen identifikator vlakna thread (muze byt NULL kdyz zadny nepotrebujeme)

   // Zkontrolujeme jestli jsme uspeli, od tohoto bodu uz nas program pracuje paralelne

	if (hThread == NULL)
	{
		printf("Nepodarilo se vytvorit vlakno!\n");
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
	TerminateThread(hThread, 1); // POZOR pouzivat jenom v nouzi! hrozi komplikace pokud terminujeme vlakno kdyz provadi kriticke operace - napriklad kriticke sekce atd....
	printf("\nVlakno zniceno...\n");

	return 0;
}
*/