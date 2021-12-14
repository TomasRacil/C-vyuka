#include <iostream>
#include <WS2tcpip.h>

// Include the Winsock library (lib) file
#pragma comment (lib, "ws2_32.lib")

// Saves us from typing std::cout << etc. etc. etc.
using namespace std;

void main(int argc, char* argv[]) // We can pass in a command line option!! 
{
	////////////////////////////////////////////////////////////
	// INITIALIZE WINSOCK
	////////////////////////////////////////////////////////////

	// Structure to store the WinSock version. This is filled in
	// on the call to WSAStartup()
	WSADATA data;

	// To start WinSock, the required version must be passed to
	// WSAStartup(). This server is going to use WinSock version
	// 2 so I create a word that will store 2 and 2 in hex i.e.
	// 0x0202
	WORD version = MAKEWORD(2, 2);

	// Start WinSock
	int wsOk = WSAStartup(version, &data);
	if (wsOk != 0)
	{
		// Not ok! Get out quickly
		cout << "Can't start Winsock! " << wsOk;
		return;
	}

	////////////////////////////////////////////////////////////
	// CONNECT TO THE SERVER
	////////////////////////////////////////////////////////////

	// Create a hint structure for the server
	sockaddr_in server;
	server.sin_family = AF_INET; // AF_INET = IPv4 addresses
	server.sin_port = htons(54000); // Little to big endian conversion
	inet_pton(AF_INET, "127.0.0.1", &server.sin_addr); // Convert from string to byte array

	// Socket creation, note that the socket type is datagram
	SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);

	// Write out to that socket
	string s(argv[1]);
	int sendOk = sendto(out, s.c_str(), s.size() + 1, 0, (sockaddr*)&server, sizeof(server));

	if (sendOk == SOCKET_ERROR)
	{
		cout << "That didn't work! " << WSAGetLastError() << endl;
	}

	// Close the socket
	closesocket(out);

	// Close down Winsock
	WSACleanup();
}


/*

*** Vyukovy program pro laboratore z predmetu Operacni systemy, Petr Frantis, UO Brno, K-209 **


#include "stdafx.h"
#include "winsock2.h"
#include "conio.h"

SOCKET sConnection;

int ConnectClient(char* server_name, int server_port) {

	SOCKADDR_IN server;
	int err;
	struct hostent* hp;
	unsigned int addr;

	printf("Pripojuji se na: %s, port: %d\n", server_name, server_port);


	sConnection = socket(AF_INET, SOCK_DGRAM, 0);
	if (sConnection == INVALID_SOCKET) {

		return FALSE;
	}


	// jestli je adresa slovne tak ji zkusime prevest na ciselnou

	if (isalpha(server_name[0])) {   // serverova adresa je jmeno
		hp = gethostbyname(server_name);
	}
	else { // Konvertujeme nnn.nnn addresu na pouzitelnou
		addr = inet_addr(server_name);
		hp = gethostbyaddr((char*)&addr, 4, AF_INET);
	}
	if (hp == NULL) {
		printf("Client: Nemuzu prelozit adresu [%s]: Error %d\n", server_name, WSAGetLastError());
		return(-1);
	}

	//
	// Zkopirujeme prelozenou adresu do sockaddr_in struktury
	//
	memset(&server, 0, sizeof(server));
	memcpy(&(server.sin_addr), hp->h_addr, hp->h_length);

	server.sin_port = htons(server_port);
	server.sin_family = AF_INET;

	err = connect(sConnection, (const struct sockaddr*)&server, sizeof(server));
	if (err != 0) {
		printf("Nepodarilo se pripojit.\n");
		return(-1);
	}

	printf("Pripojeno ... \n");

	return(0);
} // ConnectClient


int SendStr(SOCKET Sok, char* str) {
	int err;

	err = send(Sok, (char*)str, strlen(str) + 1, 0); //*** send it
	if (err == SOCKET_ERROR) {
		closesocket(Sok);
		return(-1);
	}

	return(0);
}




int _tmain(int argc, _TCHAR* argv[])
{
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;

	// Inicializujeme WinSock DLL	
	wVersionRequested = MAKEWORD(2, 2);
	err = WSAStartup(wVersionRequested, &wsaData);


	ConnectClient("localhost", 1000);

	SendStr(sConnection, "Ahoj, toto je nase prvni preneseny text pres WinSock!\n");

	while (!_kbhit());

	shutdown(sConnection, SD_SEND);
	closesocket(sConnection);

	WSACleanup();
	return 0;
}
*/