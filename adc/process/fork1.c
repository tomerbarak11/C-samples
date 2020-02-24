#include <stdio.h>
#include <unistd.h>
int g_var=0;
int main()
{
	int i,l_var=0;
	int n=fork();
	if(n<0)
	{
		printf("error");
	}
	else if(n>0)
	{
		for(i=0;i<30;i++)
		{
			++g_var;
			++l_var;
			printf("g = %d\n",g_var);
			printf("l = %d\n",l_var);
			sleep(1);	
			printf("number of process = %d\n",getpid());	
		}
	}
	else
	{
		for(i=0;i<30;i++)
		{
			--g_var;
			--l_var;	
			printf("g = %d\n",g_var);	
			printf("l = %d\n",l_var);				
			sleep(1);	
			printf("number of process = %d\n",getpid());		
		}
	}
}
