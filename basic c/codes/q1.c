#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void printDecToBinary(int n);
int invert(unsigned char n);

int main()
{
	unsigned char c='0';	
	invert(c);
}

int invert(unsigned char n)
{
	unsigned char y=~n;
	printf("%u\n",y);
	printDecToBinary(y);
}

void printDecToBinary(int n) 
{ 
	int i; 

	for (i=0; i<8 ; i++) 
	{
		printf("%d",(n>>(8-i-1))&1);
	}
	printf("\n"); 
} 
