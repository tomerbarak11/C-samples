#include "a.h"
#include "b.h"
#include <stdio.h>
int main()
{
	f1();
	f2();
	printf("adress of f1 = %p\n",(void*)f1);
	printf("adress of f2 = %p\n",(void*)f2);
	return 0;
}
