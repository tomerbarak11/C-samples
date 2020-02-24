#include <stdio.h>
#include <string.h>
void stars(int n,int i);
 void printrow(int i);
 
int main()
{
	stars(5,1);
	
}
void stars(int n,int i)
{	
    if (n == 0) 
        return; 
 	printrow(i);
 	printf("\n");
    stars(--n, ++i); 
}

 void printrow(int i)
 {
 	if (i==0)
 	{
 		return;
 	}
 	printf("*");
 	printrow(--i);
 }
