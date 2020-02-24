#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define SIZE 200

struct my_msgbuf
{
	long m_type;
	char m_text[SIZE];
};

int main()
{
	struct my_msgbuf buf,buf2;
	int msqid;
	key_t key;
	int len;
	if ((key=ftok("msgWrite.c", 'B'))==-1)
	{
		printf("ftok write");
		return -1;
	}

	if ((msqid = msgget(key, 0644 | IPC_CREAT))==-1)
	{
		printf("msgget write");
		return -1;
	}
	printf("Enter something\n");
	buf.m_type = 1;

	while(fgets(buf.m_text,sizeof buf.m_text,stdin)!= NULL)
	{
		len=strlen(buf.m_text);
		if(buf.m_text[len-1]=='\n')
		{
			buf.m_text[len-1]='\0';
		}
		if(msgsnd(msqid,&buf,len+1,0) == -1)
		{
			perror("msgsnd");
			return -1;			
		}
		
		
		
	/*TODO*/	
		if (msgrcv(msqid,&buf2,sizeof buf2.m_text, 2, 0) == -1)
		{
			perror("msgrcv");
			return -1;
		}
		printf("%s\n",buf2.m_text);
		
		
		
	}
	if (msgctl(msqid, IPC_RMID, NULL)==-1)
	{
		perror("msgctl");
		exit(1);
	}
	return 0;
}
