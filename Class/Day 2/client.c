/*
		GROUP NO : 17
	@authors:	Anubhav Patnaik 13/CS/26
			Arka Prava Basu 13/CS/32
	A UDP client
*/


#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

main()
{
	int sockfd;
	int i;
	struct sockaddr_in serv_addr;
	
	char buf[100];
	
	if((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0){
		printf("socket holo na re\n");
		exit(0);
	}
	
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	serv_addr.sin_port = htons(6000);
	
	
	
	while(1){
		for(i=0;i<100;i++) buf[i] = '\0';
		
		printf("enter msg ");
		fflush(stdin);
		gets(buf);
		if(!strcmp(buf, "-1"))
			break;
		
		sendto( sockfd, buf, strlen(buf) + 1, 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
		
		int size = sizeof(serv_addr);
		recvfrom( sockfd, buf, 100, 0, (struct sockaddr *)&serv_addr, &size);
		printf("Server sent %s\n", buf);
	}
	printf("---------------Closing Client-----------------\n");
	close(sockfd);
}
