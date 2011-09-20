/*
 * ChatServer.h
 *
 *  Created on: 07/09/2011
 *  Author: agripino
 */

#ifndef CHATSERVER_H_
#define CHATSERVER_H_

#define MAXCONNECTIONS 30

class ChatServer
{
	public:
		int server[MAXCONNECTIONS];
		int client[MAXCONNECTIONS];
		struct sockaddr_in server_addr;
		struct sockaddr_in client_addr; 
		int port;
		int csize;
		
		ChatServer();
		virtual ~ChatServer();
		
		void dispatcher(); //despacha pedidos externos para as ações correspondentes
		
		

};

#endif /* CHATSERVER_H_ */
