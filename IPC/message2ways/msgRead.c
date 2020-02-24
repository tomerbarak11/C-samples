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
	
	if ((key=ftok("msgWrite.c",'B'))==-1)
	{
		printf("ftok read");
		return -1;
	}

	if ((msqid = msgget(key,0644))==-1)
	{
		printf("msgget read");
		return -1;
	}
	buf2.m_type=2;

	printf("Enter your message\n");
	while(1)
	{
		if (msgrcv(msqid,&buf,sizeof buf.m_text, 1, 0) == -1)
		{
			perror("msgrcv");
			return -1;
		}
		printf("%s\n",buf.m_text);
		
		
		/*TODO*/
		printf("Enter message to writer\n");
		fgets(buf2.m_text,sizeof buf2.m_text,stdin);
		len=strlen(buf2.m_text);
		if(buf2.m_text[len-1]=='\n')
		{
			buf2.m_text[len-1]='\0';
		}
		if(msgsnd(msqid,&buf2,len+1,0) == -1)
		{
			perror("msgsnd");
			return -1;
		}
		
	}
	return 0;
}
