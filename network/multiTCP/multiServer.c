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
#include "list.h"
#include "list_itr.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#define SIZE 100
int serverInit(struct sockaddr_in* sin);
int checkNewClient(int sock,struct sockaddr_in* sin,int* addr_len,List* l);
void checkCurrClient(List* _clients);
int main()
{
	struct sockaddr_in sin;
	int sock=0;
	int addr_len=sizeof(sin);
	List* l=NULL;
	l=ListCreate();	
	sock=serverInit(&sin);
		
	while(1)
	{
		checkNewClient(sock,&sin,&addr_len,l);
		checkCurrClient(l);			
	}
	
	/*7 close*/
	/*itr=ListItr_Begin(l);
	while(itr!=ListItr_Next(itr))
	{
		client_sock=*(int*)ListItr_Get(itr);
		close(client_sock);
		itr=ListItr_Next(itr);
	}*/
	close(sock);
	return 0;
}

int serverInit(struct sockaddr_in* sin)
{
	int sock;
	int optval=1;
	int server_port=1025;
	int back_log=1000;
	int flags=0;
	/*1 socket*/
	sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)
	{
		perror("socket failed\n");
		return -1;
	}

	if((flags=fcntl(sock,F_GETFL)==-1))
	{
		perror("error at fcntl failed\n");
		return -1;
	}

	if((flags=fcntl(sock,F_SETFL,flags|O_NONBLOCK)==-1))
	{
		perror("error at fcntl failed\n");
		return -1;
	}
	
	if(setsockopt(sock,SOL_SOCKET,SO_REUSEADDR,&optval,sizeof(optval))<0)
	{
		perror("reuse failed\n");
		return -1;
	}
	
	/*2 bind*/	
	memset(sin,0,sizeof(*sin));
	sin->sin_family=AF_INET;
	sin->sin_addr.s_addr=INADDR_ANY;
	sin->sin_port=htons(server_port);
	
	if(bind(sock,(struct sockaddr*)sin,sizeof(*sin))<0)
	{
		perror("bind failed\n");
		return -1;
	}
	
	/*3 listen*/	
	if(listen(sock,back_log)<0)
	{
		perror("listen failed\n");
		return -1;
	}
	
	return sock;
}

int checkNewClient(int sock,struct sockaddr_in* sin,int* addr_len,List *l)
{
	int* client_sockToAdd;
	int client_sock;
	int flags;
	/*4 accept*/
	client_sock=accept(sock,(struct sockaddr*)sin,(socklen_t*)addr_len);
	
	if(client_sock<0)
	{
		if(errno!=EAGAIN&&errno!=EWOULDBLOCK)
		{
			perror("accept failed\n");
			return -1;
		}
	}
	else 
	{
		if((flags=fcntl(client_sock,F_GETFL)==-1))
		{
			perror("error at fcntl failed\n");
			return -1;
		}

		if((flags=fcntl(client_sock,F_SETFL,flags|O_NONBLOCK)==-1))
		{
			perror("error at fcntl failed\n");
			return -1;		
		}
		client_sockToAdd=(int*)malloc(1*sizeof(int));
		if(NULL==client_sockToAdd)
		{
			return -1;
		}
		*client_sockToAdd=client_sock;
		ListPushHead(l,client_sockToAdd);
	}	
	return client_sock;
}
	
void checkCurrClient(List* clients)
{
	char buffer[4096];
	char data[]="Hello I am server";
	ListItr ItrClient, ItrEnd,temp;
	int client_sock,read_bytes, sent_bytes;
	
	ItrClient = ListItr_Begin(clients);
	ItrEnd = ListItr_End(clients);
	
	while(!ListItr_Equals(ItrClient,ItrEnd))
	{
		client_sock =*(int*)ListItr_Get(ItrClient);
		
		read_bytes= recv(client_sock,(void*)buffer, sizeof(buffer)-1, 0);
	   	if (read_bytes == 0) 
		{ 
			close(client_sock);
			
			temp=ItrClient;
			ItrClient=ListItr_Prev(ItrClient);			
			ListItr_Remove(temp);
			ItrClient = ListItr_Next(ItrClient);
			continue ;
		} 
		
		else if(read_bytes < 0) 
		{ 
			if(errno !=EAGAIN && errno !=EWOULDBLOCK)
			{
				perror("\n read error \n");
				close(client_sock);
				temp=ItrClient;
				ItrClient=ListItr_Prev(ItrClient);			
				ListItr_Remove(temp);
				
			}  
			ItrClient = ListItr_Next(ItrClient);
			continue ;
		} 
		
		else 
		{
			buffer[read_bytes]= '\0';
			printf("%s\n",buffer);
		}
		
		sent_bytes = send(client_sock,data, strlen(data),0);
		if(sent_bytes < 0) 
		{ 
			if(errno !=EAGAIN && errno !=EWOULDBLOCK)
			{
				perror("\n send error \n");
				close(client_sock);
				temp=ItrClient;
				ItrClient=ListItr_Prev(ItrClient);			
				ListItr_Remove(temp);
			}  

		} 
		ItrClient = ListItr_Next(ItrClient);
	}
	return;
}
