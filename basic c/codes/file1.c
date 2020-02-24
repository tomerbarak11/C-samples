#include <stdio.h>
void fr(FILE* f[]);
void build5(FILE* f5);
int main()
{
	FILE* f[6];
	FILE* f5;
	fr(f);
	build5(f5);
}

void fr(FILE* f[])
{
	if((f[0]=fopen("HelloWorld0.txt","r"))==NULL)
	{
		printf("open error\n");
	}
	fclose(f[0]);
	if((f[1]=fopen("HelloWorld1.txt","w"))==NULL)
	{
		printf("open error\n");
	}
	fclose(f[1]);
	if((f[2]=fopen("HelloWorld0.txt","a"))==NULL)
	{
		printf("open error\n");
	}
	fprintf(f[2],"%s","\nTomer");
	fclose(f[2]);
}

void build5(FILE* f5)
{
	char name1[]="tomer",name2[]="alon";
	int age1=27,age2=25;
	if((f5=fopen("HelloWorld3.txt","w"))==NULL)
	{
		printf("open error\n");
	}
	fprintf(f5,"%s %d\n",name1,age1);
	fprintf(f5,"%s %d\n",name2,age2);
}
