#include <stdio.h>
#include <string.h>
int move4bits(char ch);
void compress(char *c);
char get4bits(char ch);
void print(char ch);
int main()
{
	char c[]="abcdefghijkolmno";
	compress(c);
}
void compress(char *c)
{
	int i,j=0;
	for(i=0;i<strlen(c);i=i+2,j++)
	{
		printf("i = %d\n",i);
		c[i]=get4bits(c[i]);
		
		c[i]=move4bits(c[i]);
		c[i+1]=get4bits(c[i+1]);
		c[j]=c[i]|c[i+1];
		print(c[j]);
		printf("\n");
	}
}

void print(char ch)
{
	int i;
	for(i=0;i<8;i++)
	{
		printf("%d",(ch>>7-i)&1);
	}
	printf("\n");
}

char get4bits(char ch)
{
	if(ch=='\0')
	{
		return 0;
	}
	return ch-'a'+1;
}

int move4bits(char ch)
{
		ch=ch<<4;
	return ch;
}
