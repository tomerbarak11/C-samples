#include <stdio.h>
void hanoi(int n,int a,int b,int c);
int main()
{
	hanoi(5,'a','b','c');
}

void hanoi(int n,char from,char via,char to)
{
	if(n==0)
	{
		return;
	}

	hanoi(--n,"move from %c to %c\n",a,c);
	printf("move from %c to %c\n",a,b);
	printf("move from %c to %c\n");
	
	hanoi(--n);	
}

