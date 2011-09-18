//============================================================================
// Name        : LabChat.cpp
// Author      : José Agripino Duarte da Silva
// Version     : 0.1
// Copyright   : Your copyright notice
// Description : Servidor simples de bate papo.
//============================================================================

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fstream>
#include <map>
#include "LoginServer.cpp"

using namespace std;

#define BUFFER 576
#define SERVERPORT 4444
#define MAXFILESIZE 4096

int main(int argc, char* argv[])
{
	LoginServer* ls = new LoginServer();
	char opt[5];

	while(strcmp(opt,"q") != 0)
	{
		cout << "Insert option\n\t"
				"[l]Login\n\t"
				"[s]Sign Up\n\t"
				"[p]List Users\n\t"
				"[q]Quit"
			<< endl;

		cin >> opt;

		if(strcmp(opt,"l") == 0) {
			if(ls->loginScreen()) {
				cout << "LOGIN SUCCEEDED" << endl;
				break;
			}
			else {
				cout << "LOGIN FAILED" << endl;
			}
		}
		else if(strcmp(opt,"s") == 0) {
			if(ls->signUpScreen()){
				cout << "Username saved!" << endl;
				ls->printUserList();
			}
			else {
				cout << "Cannot save your username" << endl;
			}
		}
		else if(strcmp(opt,"p") == 0) {
			cout << "Current users" << endl;
			ls->printUserList();
			cout << endl;
		}
		else if (strcmp(opt,"q") == 0) {
			cout << "Bye" << endl;
			exit(0);
		}
	}

	/*int iNumBytes;
	char sBuffer[BUFFER], cmd[4];
	int new_fd;
	int iSock, iFileDescriptor;
	struct sockaddr_in my_addr;
	struct sockaddr_in client_addr;
	socklen_t addr_len;

	if((iSock = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
	{
		perror("socket");
		exit(1);
	}

	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(SERVERPORT);
	my_addr.sin_addr.s_addr = INADDR_ANY;
	bzero(&(my_addr.sin_zero), 8);

	if(bind(iSock, (struct sockaddr *)&my_addr, sizeof(struct sockaddr)) < 0)
	{
		perror("bind");
		exit(1);
	}

	//loop infinito recebendo dados
	while(1)
	{
		puts("Esperando conexão...");
		addr_len = sizeof(struct sockaddr);

		if((iNumBytes = recvfrom(iSock, sBuffer, BUFFER, 0, (struct sockaddr *)&client_addr, &addr_len)) < 0)
		{
			perror("recvfroM");
			exit(1);
		}

		new_fd = accept(iFileDescriptor, (struct sockaddr *) &client_addr, &addr_len);

		puts(sBuffer);
		puts("pedido recebido");
	}*/

	return 0;
}
