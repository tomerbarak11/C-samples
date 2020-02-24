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
	int client_sock;
	int back_log=1000;
	int server_port=1025;
	struct sockaddr_in sin;
	int sock;
	char buffer[4096];
	int read_bytes;
	int send_bytes;
	char data[]="Hello I am server";
	int data_len=strlen(data);	
	int addr_len=sizeof(sin);
	int optval=1;
	/*1 socket*/
	sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)
	{
		perror("socket failed\n");
		abort();
	}
	
	if(setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(optval))<0)
	{
		perror("reuse failed\n");
		abort();		
	}
	
	/*2 bind*/	
	memset(&sin,0,sizeof(sin));
	sin.sin_family=AF_INET;
	sin.sin_addr.s_addr=INADDR_ANY;
	sin.sin_port=htons(server_port);
	if(bind(sock,(struct sockaddr*)&sin,sizeof(sin))<0)
	{
		perror("bind failed\n");
		abort();	
	}
	
	/*3 listen*/	
	if(listen(sock,back_log)<0)
	{
		perror("listen failed\n");
		abort();
	}
	
	/*4 accept*/
	client_sock=accept(sock,(struct sockaddr*)&sin,(socklen_t*)&addr_len);	
	if(client_sock<0)
	{
		perror("accept failed\n");
		abort();
	}	
	
	/*5 recv*/		
	read_bytes=recv(client_sock,buffer,sizeof(buffer)-1,0);
	printf("string = %s\n",buffer);
	if(read_bytes==0)
	{
		close(client_sock);
		close(sock);
	}	
	else if(read_bytes<0)
	{
		close(client_sock);
		close(sock);
		perror("recvfrom failed\n");
		abort();
	}	

	/*6 send*/	
	send_bytes=send(client_sock,data,data_len,0);
	if(send_bytes<0)
	{
		close(client_sock);
		close(sock);
		perror("sendto failed\n");
		abort();	
	}
	
	/*7 close*/	
	close(client_sock);
	close(sock);

	return 0;
}
