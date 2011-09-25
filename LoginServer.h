/*
 * LoginServer.h
 *
 *  Created on: 07/09/2011
 *      Author: agripino
 */

#ifndef LOGINSERVER_H_
#define LOGINSERVER_H_
#include <map>

using namespace std;


class LoginServer {
	private:
		map<std::string, std::string> userList;

	public:
		LoginServer();
		virtual ~LoginServer();
		bool loginScreen();
		void loginWelcome();
		void printUserList();
		bool login(char*, char *);
		bool logout();
		bool signUp(char*, char*);
		bool signUpScreen();
};

#endif /* LOGINSERVER_H_ */
