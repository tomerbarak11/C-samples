/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: linked testing
* 						DATE: 01-07-2019 15:11:38
*******************************************************************************/

#include <assert.h> 	    /* assert                                       */
#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc */
#include <string.h>        /* strcat, strlen, strcpy                           */
#include "linked.h"

int main()
{
    person p1,p2,p3,p4;
        
    person* pHead=NULL;
    person* deleted=NULL;

    p1.m_id=10;
    strcpy(p1.m_name,"tomer");
    p1.m_age=27;
    p1.m_next=NULL;
    
    p2.m_id=20;
    strcpy(p2.m_name,"alon");
    p2.m_age=25;
    p2.m_next=NULL;
    
    p3.m_id=30;
    strcpy(p3.m_name,"hadar");
    p3.m_age=19;
    p3.m_next=NULL;
    
    p4.m_id=25;
    strcpy(p4.m_name,"udi");
    p4.m_age=55;
    p4.m_next=NULL;

    pHead=ListInsertHead(pHead,&p1);
    pHead=ListInsertHead(pHead,&p2);
    pHead=ListInsertHead(pHead,&p3);
   
    pHead=ListInsertByKey(pHead,p4.m_id,&p4);
    pHead=ListRemoveByKey(pHead,22,&deleted);
    
    if(NULL!=pHead)
    {
	printf("list is not empty\n");
    	PrintList(pHead);
    }
    else
    {
    	printf("list is empty\n");
    }
    return 0;
 }
