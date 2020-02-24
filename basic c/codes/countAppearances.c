#include <stdio.h>
#include <string.h>
void countAppearances(FILE* f,char *input);
int main()
{
	FILE* f;
	countAppearances(f,"Yosi");
	
}

void countAppearances(FILE* f,char *input)
{
	int count=0,cmp;
	char word[256];
	if((f=fopen("count.txt","r"))==NULL)
	{
		printf("open error\n");
	}
	
	while((cmp=fscanf(f,"%s",word))!=EOF)
	{
		if(0==strcmp(word,input))
		{
			count++;
		}
	}
	printf("the word %s appears %d times\n",input,count);
	fclose(f);

}

