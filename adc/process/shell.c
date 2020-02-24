#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "unistd.h"
#include "sys/types.h"
#include <sys/wait.h>
#define ROW 20
#define COL 20 
void type_prompt(); 
void read_command( char command[] , char params[ROW][COL] );

int main ()
{
	char command[COL] , params[ROW][COL];
	int i,pid,status;
    for(i=0;i<ROW;i++)
    {
    	params[i][0]='\0';
    }
	while(1)
	{
		type_prompt();
		read_command(command,params);
		pid = fork();
		if (pid < 0 )
		{
			printf("Unable to fork");
			continue;
		}

		if(pid != 0)
		{
			waitpid(-1,&status,0);
		}
		if(pid == 0)
		{	printf("params[0] = %s",params[0]);
			execvp(params[0] ,(char**) params);
		}
	}
	return 0 ;
}
void type_prompt()
	{
		printf("\n$ ");
	}

void read_command( char command[] , char params[ROW][COL] )
{
    char* token;
    int i=0;
    printf("enter command\n");
    fgets(command,200,stdin);
    token= strtok(command," "); 
    while (token != NULL)
    { 
    	strcpy(params[i],token);
    	params[i][strlen(token)+1]='\0';
		i++;
        token = strtok(NULL, " \n"); 
    }
    for(i=0;params[i][0]!='\0';i++)
    {
    	printf("token %s\n",params[i]);
    }
}
