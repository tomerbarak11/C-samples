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
#include <sys/time.h>
#include <sys/select.h> 
#define SIZE3 10
static char* createTLV();

int sockAndConnect(struct sockaddr_in* sin);
void sendAndRecv(int* sock);
void onlySend(int* sock,fd_set* master_socket,fd_set* temp);
void onlyRecv(int* sock,fd_set* master_socket,fd_set* temp);

void disconnect(int* sock);
/*static void printTLV(char* tlv,unsigned char N1,unsigned char N2);*/
static char* createTLV();

static char* createTLV()
{
	char* tlv;
	char* extractTLV;
	char* name="TomerBarak1234";
	unsigned char N1;
	char *msg="This is my msg\n";
	int a;
	unsigned char N2;
	int i;
	int j;
	int startOfData;
	printf("Enter the message\n");
	scanf("%d",&a);
	getchar();
	N1=strlen(name);
	N2=strlen(msg);
	tlv=(char*)malloc((6+strlen(name)+strlen(msg)+1)*sizeof(char));

	if(NULL==tlv)
	{
		printf("allocation failed\n");
		exit(1);
	}
	extractTLV=(char*)malloc((N2+1)*sizeof(char));
	if(NULL==extractTLV)
	{
		printf("allocation failed\n");
		exit(1);
	}
	
	strcpy(tlv,"01");
	tlv[2]=N1;
	strcat(tlv,name);
	
	for(i=0;i<2;i++)
	{
		/*printf("%c",tlv[i]);*/
	}
	/*printf("%d",tlv[2]);*/
	for(i=3,j=0;j<N1;j++,i++)
	{
		/*printf("%c",tlv[i]);*/
	}
	startOfData=i;
	strcat(tlv,"02");	
	i=i+2;
	tlv[i]=N2;
	strcat(tlv,msg);
	i=startOfData;
	for(j=0;j<2;j++,i++)
	{
		/*printf("%c",tlv[i]);*/
	}	
	/*printf("%d",tlv[i]);*/
	for(j=0;j<=N2;j++,i++)
	{
		extractTLV[j]=tlv[i];
		/*printf("%c",tlv[i]);*/
	}
	extractTLV[j]='\0';
	return extractTLV;
}

/*static void printTLV(char* tlv,unsigned char N1,unsigned char N2)
{
	int i,j,startOfData;

	for(j=N2+4;j<=strlen(tlv);j++)
	{
		printf("%c",tlv[j]);
	}printf("\n");
}*/


int main()
{
	struct sockaddr_in sin;
	int sock;
	fd_set master_socket,temp;
	FD_ZERO(&master_socket);
	FD_SET(0,&master_socket);
	FD_SET(sock,&master_socket);
	sock=sockAndConnect(&sin);
	while(1)
	{
		temp=master_socket;
		select(1024,&temp,NULL,NULL,NULL);
		onlyRecv(&sock,&master_socket,&temp);
		onlySend(&sock,&master_socket,&temp);

	}
	disconnect(&sock);
	return 0;
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

void onlySend(int* sock,fd_set* master_socket,fd_set* temp)
{
	char* extractTLV;
	int send_bytes;
	
	extractTLV=createTLV();
	if(FD_ISSET(0,temp))
	{
		send_bytes=send(*sock,extractTLV,strlen(extractTLV),0);
		if(send_bytes<0)
		{
			perror("sendto failed\n");
			return;	
		}
	}
}
void onlyRecv(int* sock,fd_set* master_socket,fd_set* temp)
{
	char buffer[4096];
	int read_bytes;
	if(FD_ISSET(*sock,temp))
	{
			printf("%s22222222222222222222222222\n",buffer);	
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
		printf("%s11111111111111111111111111111\n",buffer);	
	}
	return;
}

void disconnect(int* sock)
{
	close(*sock);	
}
