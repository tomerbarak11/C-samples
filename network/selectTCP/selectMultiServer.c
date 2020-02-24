/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: socket testing
* 						DATE: 08-08-2019 13:43:05
*******************************************************************************/
#include <stdio.h>
#include <assert.h>
#include "sys/socket.h"
#include "netinet/in.h"
#include "stdlib.h"
#include "string.h"
#include "arpa/inet.h"
#include "list.h"
#include "list_itr.h"
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/select.h> 
#define SIZE 100
int serverInit(struct sockaddr_in* sin);
int checkNewClient(int sock,struct sockaddr_in* sin,int* addr_len,List *l,fd_set* master_socket,fd_set* temp,int* activity);
void checkCurrClient(List* clients,fd_set* master_socket,fd_set* temp,int* activity);
int main()
{
	struct sockaddr_in sin;
	int sock=0;
	int addr_len=sizeof(sin);
	int activity=0;
	List* l=NULL;
	fd_set master_socket,temp;
	l=ListCreate();	
	sock=serverInit(&sin);
	FD_ZERO(&master_socket);
	FD_SET(sock,&master_socket);
	
	while(1)
	{
		temp=master_socket;
		activity=select(1024,&temp,NULL,NULL,NULL);
		checkNewClient(sock,&sin,&addr_len,l,&master_socket,&temp,&activity);	
		checkCurrClient(l,&master_socket,&temp,&activity);			
	}
	close(sock);
	return 0;
}

int serverInit(struct sockaddr_in* sin)
{
	int sock;
	int optval=1;
	int server_port=1025;
	int back_log=1000;
	/*1 socket*/
	sock=socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)
	{
		perror("socket failed\n");
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

int checkNewClient(int sock,struct sockaddr_in* sin,int* addr_len,List *l,fd_set* master_socket,fd_set* temp,int* activity)
{
	int* client_sockToAdd;
	int client_sock;
	/*4 accept*/
	if(FD_ISSET(sock,temp))
	{
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
			client_sockToAdd=(int*)malloc(1*sizeof(int));
			if(NULL==client_sockToAdd)
			{
				return -1;
			}
			FD_SET(client_sock,master_socket);
			*client_sockToAdd=client_sock;
			ListPushHead(l,client_sockToAdd);
		}	
		return client_sock;
	}
	return 0;
}
	
void checkCurrClient(List* clients,fd_set* master_socket,fd_set* temp,int* activity)
{
	char buffer[4096];
	char data[]="Hello I am server";
	ListItr ItrClient, ItrEnd,tempItr;
	int client_sock,read_bytes, sent_bytes;
	
	ItrClient = ListItr_Begin(clients);
	ItrEnd = ListItr_End(clients);
	
	while(!ListItr_Equals(ItrClient,ItrEnd))
	{
		if(*activity!=0)
		{
			client_sock =*(int*)ListItr_Get(ItrClient);
			if(FD_ISSET(client_sock,temp))
			{
				read_bytes= recv(client_sock,(void*)buffer, sizeof(buffer)-1, 0);
			   	if (read_bytes == 0) 
				{ 
					close(client_sock);				
					tempItr=ItrClient;
					ItrClient=ListItr_Prev(ItrClient);	
				
					FD_CLR(client_sock,master_socket);	
					ListItr_Remove(tempItr);
					(*activity)--;
					ItrClient = ListItr_Next(ItrClient);
					continue ;
				} 
				
				else if(read_bytes < 0) 
				{ 
					if(errno !=EAGAIN && errno !=EWOULDBLOCK)
					{
						perror("read error\n");
						close(client_sock);
						tempItr=ItrClient;
						ItrClient=ListItr_Prev(ItrClient);
						FD_CLR(client_sock,master_socket);	
						ListItr_Remove(tempItr);
						(*activity)--;
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
						perror("send error\n");
						close(client_sock);
						tempItr=ItrClient;
						ItrClient=ListItr_Prev(ItrClient);
						FD_CLR(client_sock,master_socket);
						ListItr_Remove(tempItr);
						(*activity)--;		
					}
				}
			}
			ItrClient = ListItr_Next(ItrClient);
		}
		else
		{
			break;
		}
	}
	return;
}
