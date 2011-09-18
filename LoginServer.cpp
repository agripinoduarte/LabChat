/*
 * LoginServer.cpp
 *
 *  Created on: 07/09/2011
 *      Author: agripino
 */

#include "LoginServer.h"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <cstring>

using namespace std;

#define MAXFILESIZE 4096

/**
 * Construtor
 */
LoginServer::LoginServer() {
	// TODO Auto-generated constructor stub

	//fluxo de arquivo de entrada
	ifstream is;

	//strings
	char str[MAXFILESIZE], *token, *key, *value;

	//vetor de strings com tokens
	char* strTokens[100];


	int i = 0;

	pair<char*, char*> data;			// par chave => valor a ser inserido no mapa

	//tenta abrir o arquivo com dados de usuários
	is.open("users.bp", ifstream::in);

	//itera o fluxo e obtem os dados
	while(is.good()) {
		//lê uma linha do arquivo
		is.getline(str,MAXFILESIZE);
		//separa os tokens de "usuario:senha" delimitados por ";"
		token = strtok (str, ";");
		while (token != NULL) {
			//adiciona um par "usuario:senha" num vetor de strings
			strTokens[i] = new char[strlen(token) + 1];
			strcpy(strTokens[i], token);
			token = strtok (NULL, ";");
			i++;
		}
	}

	int size = i;
	i = 0;

	//percorre o vetor de pares "usuario:senha"
	while(i < size) {
		//separa o par "usuario:senha" delimitados por ":"
		key = strtok (strTokens[i], ":");
		while (key != NULL) {
			value = strtok (NULL, ":");
			//adiciona o par no atributo userList (mapa principal de usuarios e senhas)
			this->userList.insert(pair<char*, char*>(key, value));
			key = strtok (NULL, ":");
		}
		i++;
	}

	is.close();
}

LoginServer::~LoginServer() {
	// TODO Auto-generated destructor stub
}

void
LoginServer::printUserList() {
	map<char*,char*>::iterator it;		// iterador para o mapa

	for (it = this->userList.begin() ; it != this->userList.end(); it++ )
			cout << (*it).first << endl;
}

bool
LoginServer::login(char* username, char* password) {
	map<char*, char*>::iterator it;

	printUserList();
	it = this->userList.find(username);

	if(it != this->userList.end())
	{
		return strcmp(this->userList.find(username)->second, password);
	}
	else
	{
		return false;
	}
}

bool
LoginServer::loginScreen()
{
	char username[50];
	char password[40];

	cout << "LOGIN " << endl;
	cout << "Username: ";
	cin >> username;

	cout << "Password:";
	cin >> password;

	return this->login(username, password);
}

bool
LoginServer::signUpScreen() {

	char username[30], password[40];
	cout << "Enter your username  (30 characters at most) " << endl;
	cin >> username;

	cout << "Enter your password(40 characters at most) " << endl;
	cin >> password;

	return this->signUp(username, password);
}

bool
LoginServer::signUp(char* username, char* password) {

	ofstream of;

	of.open("users.bp", ofstream::app);

	if(!of)
		return false;

	this->userList[username] = password;

	strcat(username, ":");
	strcat(username, password);
	strcat(username, ";");

	of.write(username, strlen(username));

	of.close();
	return true;
}
