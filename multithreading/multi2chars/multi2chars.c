#define _XOPEN_SOURCE 500
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
static void* printChar(void* a_char);
#define SIZE 2
int main()
{
    pthread_t t[SIZE];
    void* voidArrOfChars[SIZE];
    char arrOfChars[SIZE];
    arrOfChars[0]='*';
    arrOfChars[1]='#';
    int i;

    for(i=0;i<SIZE;++i)
    {
         voidArrOfChars[i]=&arrOfChars[i];   
    }

    for(i=0;i<SIZE;++i)
    {
        pthread_create(&t[i],NULL,printChar,voidArrOfChars[i]);
    }

    for(i=0;i<SIZE;i++)
	{
		pthread_join(t[i], NULL);
	}
}

static void* printChar(void* a_char)
{
    int i;
    for(i=0;i<30;i++)
    {
        usleep(1000000);
        printf("%c",*(char*)a_char);
    }
}
