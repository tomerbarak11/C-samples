/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: myTime code
* 						DATE: 01-08-2019 16:11:20
*******************************************************************************/

#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc */
#include <string.h>        /* strcat, strlen, strcpy                           */
#include "myTime.h"
#include "PeriodicTaskExecutor.h"


void printHour(struct timespec tp)
{
	long hour,minute,second;	
	second=tp.tv_sec%60;
	minute=(tp.tv_sec%3600)/60;
	hour=(((tp.tv_sec/3600)%24)+3)%24;
	printf("The time now is %lu:%lu:%lu\n",hour,minute,second);
}
