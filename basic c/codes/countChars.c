#include <stdio.h>
#include <string.h>
#define SIZE 52
void countLetters(FILE* f);
int main()
{
	FILE* f;
	countLetters(f);
	
}

void countLetters(FILE* f)
{
	
	char ch;
	int count=0,i,cmp;
	int letters[SIZE]={0};
	if((f=fopen("countLetters.txt","r"))==NULL)
	{
		printf("open error\n");
	}
	
	ch=fgetc(f); 
	while(ch!=EOF) 
	{ 
		printf("%c",ch); 
		if(ch>='a'&&ch<='z')
		{ 
			letters[ch-'a']++;
		}
		else if (ch>='A'&&ch<='Z')
		{
			letters[ch+SIZE/2-'A']++;
		}
		ch=fgetc(f); 
	}
	for(i=0;i<SIZE/2;i++)
	{

		if(letters[i])
		{
		printf("letter %c appears %d times\n",i+'a',letters[i]);
		}
		if(letters[i+26])
		{
		printf("letter %c appears %d times\n",i+'A',letters[i+SIZE/2]);
		}
	}

}

