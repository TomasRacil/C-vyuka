#include <iostream>
#include <WS2tcpip.h>

// Include the Winsock library (lib) file
#pragma comment (lib, "ws2_32.lib")

// Saves us from typing std::cout << etc. etc. etc.
using namespace std;

// Main entry point into the server
void main()
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
	// SOCKET CREATION AND BINDING
	////////////////////////////////////////////////////////////

	// Create a socket, notice that it is a user datagram socket (UDP)
	SOCKET in = socket(AF_INET, SOCK_DGRAM, 0);

	// Create a server hint structure for the server
	sockaddr_in serverHint;
	serverHint.sin_addr.S_un.S_addr = ADDR_ANY; // Us any IP address available on the machine
	serverHint.sin_family = AF_INET; // Address format is IPv4
	serverHint.sin_port = htons(54000); // Convert from little to big endian

	// Try and bind the socket to the IP and port
	if (bind(in, (sockaddr*)&serverHint, sizeof(serverHint)) == SOCKET_ERROR)
	{
		cout << "Can't bind socket! " << WSAGetLastError() << endl;
		return;
	}

	////////////////////////////////////////////////////////////
	// MAIN LOOP SETUP AND ENTRY
	////////////////////////////////////////////////////////////

	sockaddr_in client; // Use to hold the client information (port / ip address)
	int clientLength = sizeof(client); // The size of the client information

	char buf[1024];

	// Enter a loop
	while (true)
	{
		ZeroMemory(&client, clientLength); // Clear the client structure
		ZeroMemory(buf, 1024); // Clear the receive buffer

		// Wait for message
		int bytesIn = recvfrom(in, buf, 1024, 0, (sockaddr*)&client, &clientLength);
		if (bytesIn == SOCKET_ERROR)
		{
			cout << "Error receiving from client " << WSAGetLastError() << endl;
			continue;
		}

		// Display message and client info
		char clientIp[256]; // Create enough space to convert the address byte array
		ZeroMemory(clientIp, 256); // to string of characters

		// Convert from byte array to chars
		inet_ntop(AF_INET, &client.sin_addr, clientIp, 256);

		// Display the message / who sent it
		cout << "Message recv from " << clientIp << " : " << buf << endl;
	}

	// Close socket
	closesocket(in);

	// Shutdown winsock
	WSACleanup();
}

/*
** Vyukovy program pro laboratore z predmetu Operacni systemy, Petr Frantis, UO Brno, K-209 **


#include "stdafx.h"
#include "winsock2.h"


SOCKET sListener;


int InicializujServer() {

	SOCKADDR_IN sinn;
	int err;

	printf("Spoustim UDP server ....\n");

	//
	// Listener socket bude pouzit pro naslouchani prichozim pripojenim
	sListener = socket(AF_INET, SOCK_DGRAM, 0); // SOCK_DGRAM = UDP socket
	if (sListener == INVALID_SOCKET) {
		printf("Nemohu vytvorit listener socket\n");
		return(-1);
	}

	//
	// bidneme socket na definovany port
	//

	sinn.sin_family = AF_INET;
	sinn.sin_port = htons(1000);
	sinn.sin_addr.s_addr = INADDR_ANY;

	err = bind(sListener, (SOCKADDR*)&sinn, sizeof(sinn));
	if (err == SOCKET_ERROR) {
		printf("Nemohu bind socket na portu 1000.\n");
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


	InicializujServer();

	SOCKET soket;
	char buf[100];
	SOCKADDR_IN addr;
	int len;


	printf("Cekam na pripojeni ... \n");

	len = sizeof(addr);
	err = recvfrom(sListener, buf, 100, 0, (sockaddr*)&addr, &len);
	printf("%s", buf);

	printf("\nSpojeni ukonceno ...\n");
	closesocket(sListener);

	printf("Ukoncuji server ...\n");
	shutdown(sListener, SD_BOTH);
	closesocket(sListener);

	WSACleanup();

	return 0;
}*/