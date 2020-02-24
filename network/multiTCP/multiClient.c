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
#include "time.h"
#include "arpa/inet.h"
#include <unistd.h>
#define SIZE3 10
int sockAndConnect(struct sockaddr_in* sin);
void sendAndRecv(int* sock);
void disconnect(int* sock);
int main()
{
	int i;
	struct sockaddr_in sin;
	int sockArr[SIZE3]={0};
	int num;
	srand(time(NULL));
	
	while(1)
	{
		for(i=0;i<SIZE3;i++)
		{
			if(sockArr[i]==0)
			{
				num=rand()%100;
				if(num<30)
				{		
					sockArr[i]=sockAndConnect(&sin);
				}
			}
			else if (sockArr[i]>0)
			{
				num=rand()%100;
				if(num<40)
				{
					sendAndRecv(&sockArr[i]);
				}
				else if(num>40&&num<50)
				{
					disconnect(&sockArr[i]);
					sockArr[i]=0;
				}
			}
		}	
	}
return 1;	/*5 close*/	
}

int sockAndConnect(struct sockaddr_in* sin)
{
	int sock;
	int server_port=1025;
	/*1 sock*/
	sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)
	{
		perror("socket failed\n");
		return -1;
	}

	/*2 connect*/
	memset(sin,0,sizeof(*sin));
	sin->sin_family=AF_INET;
	sin->sin_addr.s_addr=inet_addr("127.0.0.1");
	sin->sin_port=htons(server_port);
	
	if(connect(sock,(struct sockaddr*)sin,sizeof(*sin))<0)
	{
		perror("connection failed\n");
		return -1;
	}
	return sock;
}

void sendAndRecv(int* sock)
{
	char data[]="Hello I am client";
	int data_len=strlen(data);
	char buffer[4096];
	int read_bytes;
	int send_bytes;
	/*3 send*/	

	send_bytes=send(*sock,data,data_len,0);
	if(send_bytes<0)
	{
		perror("sendto failed\n");
		return;	
	}
	/*4 recv*/
	read_bytes=recv(*sock,buffer,sizeof(buffer),0);
	if(read_bytes==0)
	{
		*sock=0;
		close(*sock);
		return;
	}		
	if(read_bytes<0)
	{
		perror("recvfrom failed\n");
		return;
	}	
	printf("%s\n",buffer);	
}

void disconnect(int* sock)
{
	close(*sock);	
}
