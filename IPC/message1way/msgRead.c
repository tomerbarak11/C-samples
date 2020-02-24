#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct my_msgbuf
{
	long mtype;
	char m_text[200];
};

int main()
{
	struct my_msgbuf buf;
	int msqid;
	key_t key;

	if ((key=ftok("msgWrite.c",'B'))==-1)
	{
		printf("ftok read");
		exit(1);
	}

	if ((msqid = msgget(key,0644))==-1)
	{
		printf("msgget read");
		exit(1);
	}
	printf("Enter your message\n");
	while(1)
	{
		if (msgrcv(msqid,&buf,sizeof buf.m_text, 0, 0) == -1)
		{
			perror("msgrcv");
			exit(1);
		}
		printf("%s\n",buf.m_text);
	}
	return 0;
}
