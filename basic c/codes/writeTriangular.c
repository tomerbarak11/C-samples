#include <stdio.h>
#include <math.h>

printCharInDesendingSeries(int numOfLines,char ch)
{
	int j;

	for(j=numOfLines;j>0;j--)
		{
			printf("%c",ch);
		}	
	printf("\n");
}

printCharInAsendintSeries(int numOfLines,char ch)
{
	int j;

	for(j=0;j<numOfLines;j++)
		{
			printf("%c",ch);
		}	
		printf("\n");
}


int writeTriangular(int numOfLine,char ch)
{
	int i,j;

	for(i=0;i<(numOfLine+2)/2+1;i++)
	{
		printCharInAsendintSeries(i,ch);	
	}

	for(i=((numOfLine+2)/2+1);i>0; i--)	
	{
		printCharInDesendingSeries(i,ch);
	}

	printf("\n");
}	
	        
int main (void){

	int numOfLine;
	char ch;
	
	printf("\n enter the number of lines \n");
	scanf("%d",&numOfLine);
	getchar();

	printf("\n enter the char \n");
	scanf("%c",&ch);
	getchar();
    
	writeTriangular(numOfLine,ch);
	
	        
return 0;
}
