/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: socket testing
* 						DATE: 08-08-2019 13:43:05
*******************************************************************************/
#include <stdio.h>
#include <assert.h>
#include "sys/socket.h"
#include "netinet/in.h"
#include "sys/types.h"
#include "stdlib.h"
#include "string.h"
#include "arpa/inet.h"
#include <unistd.h>
int main()
{
	int server_port=1025;
	struct sockaddr_in sin;
	int sock;
	char buffer[4096];
	int read_bytes;
	int send_bytes;
	char data[]="Hello I am client";
	int data_len=strlen(data);
		
	/*1 socket*/
	sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)
	{
		perror("socket failed\n");
		abort();
	}
	
	/*2 connect*/
	memset(&sin,0,sizeof(sin));
	sin.sin_family=AF_INET;
	sin.sin_addr.s_addr=inet_addr("192.168.0.218");
	sin.sin_port=htons(server_port);
	
	if(connect(sock,(struct sockaddr*)&sin,sizeof(sin))<0)
	{
		perror("connection failed\n");
		abort();
	}

	/*3 send*/	
	memset(&sin,0,sizeof(sin));
	sin.sin_family=AF_INET;
	sin.sin_addr.s_addr=inet_addr("192.168.0.218");
	sin.sin_port=htons(server_port);
	send_bytes=send(sock,data,data_len,0);
	if(send_bytes<0)
	{
		perror("sendto failed\n");
		abort();	
	}
	/*4 recv*/		
	read_bytes=recv(sock,buffer,sizeof(buffer)-1,0);
	if(read_bytes<0)
	{
		perror("recvfrom failed\n");
		abort();
	}	
	printf("string = %s\n",buffer);
	
	/*5 close*/	
	close(sock);	
	return 0;
}
