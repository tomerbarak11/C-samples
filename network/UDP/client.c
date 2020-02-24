/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: socket testing
* 						DATE: 08-08-2019 13:43:05
*******************************************************************************/
#include <stdio.h>
#include <assert.h>
#include "socket.h"
#include "sys/socket.h"
#include "netinet/in.h"
#include "sys/types.h"
#include "stdlib.h"
#include "string.h"
#include "arpa/inet.h"
int main()
{
	int server_port=1025;
	struct sockaddr_in sin;
	int sock;
	int sin_len=sizeof(sin);
	char buffer[4096];
	int read_bytes;
	int send_bytes;
	char data[]="Hello I am client";
	int data_len=strlen(data);		
	/*1*/
	sock=socket(AF_INET,SOCK_DGRAM,0);
	if(sock<0)
	{
		perror("socket failed\n");
		abort();
	}
	

	/*3*/	
	memset(&sin,0,sizeof(sin));
	sin.sin_family=AF_INET;
	sin.sin_addr.s_addr=inet_addr("127.0.0.1");
	sin.sin_port=htons(server_port);
	send_bytes=sendto(sock,data,data_len,0,(struct sockaddr*)&sin,sizeof(sin));
	if(send_bytes<0)
	{
		perror("sendto failed\n");
		abort();	
	}
	/*4*/		
	read_bytes=recvfrom(sock,buffer,sizeof(buffer)-1,0,(struct sockaddr*)&sin,(socklen_t*)&sin_len);
	if(read_bytes<0)
	{
		perror("recvfrom failed\n");
		abort();
	}	
	printf("string = %s\n",buffer);
	return 0;
}
