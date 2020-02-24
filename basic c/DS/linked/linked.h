/**************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: linked header
* 						DATE: 01-07-2019 15:11:38
*******************************************************************************/

#ifndef __LINKED_H__
#define __LINKED_H__
#include <assert.h> 	    /* assert                                       */
#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc */

#include <string.h>        /* strcat, strlen, strcpy                           */
/**@Description:
 * Average time complexity :
 * Worst : 
 * @params _x :
 * @returns:
 */

typedef struct Person person;
struct Person{
	int m_id;
	char m_name[128];
	int m_age;
	person* m_next;
};

person* ListInsertHead(person* _head,person* _p);
person* ListRemoveHead(person* _head,person** _item);

person* ListInsertByKey(person* _head,int _key,person* _p);
person* ListInsertByKeyRec(person* _head,int _key,person* _p);

person* ListRemoveByKey(person* _head,int _key,person** _p);
person* ListRemoveByKeyRec(person* _head,int _key,person** _p);

void PrintList(person* _head);
void PrintLastRec(person* _head);

#endif          /* linked s*/




