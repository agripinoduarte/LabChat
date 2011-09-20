#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
	perror(msg);
	exit(1);
}
#define MAXCONNECTIONS 30

int main(int argc, char *argv[])
{
	int server[MAXCONNECTIONS];
	int client[MAXCONNECTIONS];
	
	int sockfd, newsockfd, portno;
	socklen_t clilen;
	
	char buffer[256];
	struct sockaddr_in serv_addr, cli_addr;
	int n;
	
	if (argc < 2) 
	{
		fprintf(stderr,"Informe a porta");
		exit(1);
	}
	
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	if (sockfd < 0) 
		error("ERROR opening socket");
        
	bzero((char *) &serv_addr, sizeof(serv_addr));
	     
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
	
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 
		error("Erro: bind");
		
	listen(sockfd,5);
	
	int i = 0;
	
	while (1)
	{
		clilen = sizeof(cli_addr);
		newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
		puts(".");
		i++;
		if (newsockfd < 0) 
			error("ERROR on accept");
		
		if (fork() == 0) 
		{
			while(sizeof(buffer) != 0) 
			{
				bzero(buffer,256);
				
				n = read(newsockfd,buffer,255);

				printf("Message from %d: ", newsockfd);
				printf("Here is the message: %s\n",buffer);
				n = write(newsockfd,"I got your message",18);
			
				if (n < 0) 
					error("ERROR writing to socket");
			}
		}
	}
	
	
	
	close(sockfd);
	close(newsockfd);
	return 0; 
}
