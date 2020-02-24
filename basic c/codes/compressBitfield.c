#include <stdio.h>
#include <string.h>

typedef struct statusReg{
	unsigned int l :4;
	unsigned int r :4;
}statusReg;

int move4bits(char ch);
void compress(char *c);
char get4bits(char ch);
void print(statusReg st);

int main()
{
	char c[]="abcdefghijkolmno";
	compress(c);
}
void compress(char *c)
{
	statusReg st;
	int i,j=0;
	for(i=0;i<strlen(c);i=i+2,j++)
	{
		printf("i = %d\n",i);
		c[i]=get4bits(c[i]);
		
		st.l=c[i];
		
		c[i+1]=get4bits(c[i+1]);
		
		st.r=c[i+1];
		c[j]=st.l|st.r;
		
		print(st);
		printf("\n");
	}
}

void print(statusReg st)
{
	int i;

	for(i=0;i<4;i++)
	{
		printf("%d",(st.l>>3-i)&1);
	}
	printf("\n");
	
	for(i=0;i<4;i++)
	{
		printf("%d",(st.r>>3-i)&1);
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
