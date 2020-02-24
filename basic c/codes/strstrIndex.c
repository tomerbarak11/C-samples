#include <stdio.h>
#include <string.h>
int strstrIndex(char* s1,char* s2);
int main()
{
	char *s1="Tomer";
	char *s2="mer";
	
	printf("index = %d\n",strstrIndex(s1,s2));
}

int strstrIndex(char* s1,char* s2)
{
	char *p1,*p2;
	int index=0;
	p1=s1;
	p2=s2;
	if(strlen(s2)>strlen(s1))
	{
		return -1;
	}
	if(!s1||!s2)
	{
		return -1;
	}
	while(*p1!='\0'&&*p2!='\0')
	{
		printf("1\n");
		while(*p1==*p2)
		{
			p1++;
			p2++;
			printf("2\n");
			if(*p2=='\0')
			{
				return index;
			}		
		}
		index++;
		p1++;
	}
	printf("not found\n");
	return -1;
}
