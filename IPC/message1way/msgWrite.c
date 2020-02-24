#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msgbuf
{
	long m_type;
	char m_text[200];
};

int main()
{
	struct my_msgbuf buf;
	int msqid;
	key_t key;
	int len;
	if ((key=ftok("msgWrite.c", 'B'))==-1)
	{
		printf("ftok write");
		exit(1);
	}

	if ((msqid = msgget(key, 0644 | IPC_CREAT))==-1)
	{
		printf("msgget write");
		exit(1);
	}
	printf("Enter lines of text, ^D to quit:\n");
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
		}
	}
	if (msgctl(msqid, IPC_RMID, NULL)==-1)
	{
		perror("msgctl");
		exit(1);
	}
	return 0;
}
