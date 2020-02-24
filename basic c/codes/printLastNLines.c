#include <stdio.h>
void printLastNLines(FILE* f,int n);

int main()
{
	FILE* f;
	int n=8;
	printLastNLines(f,n);
}

void printLastNLines(FILE* f,int n)
{
	int count =0,i;
	char c;
	char stam[256];
	if((f=fopen("lines.txt","r"))==NULL)
	{
		printf("open error\n");
	}
    for (c = getc(f); c != EOF; c = getc(f))
    {
        if (c == '\n')
        {
            count = count + 1; 
        }
	}
	fseek(f,0,SEEK_SET);
	for(i=0;i<count-n;i++)
	{
		fgets(stam,256,f);
	}
	
	for (c = getc(f); c != EOF; c = getc(f))
   	{
		printf("%c",c);
	}
}
