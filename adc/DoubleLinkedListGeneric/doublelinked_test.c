#include "mu_test.h"/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: doublelinked testing
* 						DATE: 02-07-2019 16:18:05
*******************************************************************************/

#include <assert.h>
#include "list.h"


/*
 @author: Muhammad Zahalqa
 @contact: m@tryfinally.com

 ©2019
 μ_test 0.42 demo.

 the directory conatins:
 mu_test.h 		: mu test framework
 funcs.c/h 		: functions to be tested in demo
 test.c 		: test

 Compile with
	gcc -ansi -pedantic -Wall -Wextra funcs.c test.c -o test

 Run:
 	./test
 	./test -v
 */

#include "list.h"

static int PrintElement(void* _element, size_t _index, void* _context);
static int PrintElement(void* _element, size_t _index, void* _context)
{
	printf("\n");
	if(NULL==_element)
	{
		printf("11111111111111111111\n");
		return 0;
	}
	else
	{
		printf("2222222222222222222\n");
		printf("item number %ld is %d\n",_index,*(int*)_element);
		return 1;
	}

}

UNIT(List_Create)
	List* l=ListCreate();
	int i;
	int *item;
	ASSERT_THAT(l!=NULL);
END_UNIT

UNIT(List_Push_Head)
	List* l=ListCreate();
	int i;
	int *item;
	for(i=0;i<3;i++)
	{
		item=(int*)malloc(1*sizeof(int*));
		*item=i;
		ListPushHead(l,item);	
	}
	ASSERT_THAT(ListCountItems(l)==3);
END_UNIT

UNIT(List_Push_Tail)
	List* l=ListCreate();
	int i;
	int *item;
	void* vp;
	for(i=0;i<3;i++)
	{
		item=(int*)malloc(1*sizeof(int*));
		*item=i;
		ListPushTail(l,item);	
	}
	ASSERT_THAT(ListCountItems(l)==3);
END_UNIT


UNIT(List_Pop_Head)
	List* l=ListCreate();
	int i;
	int *item;
	void* vp;
	_elementDestroy destroyItem=itemDestroy;
	for(i=0;i<1;i++)
	{
		item=(int*)malloc(1*sizeof(int*));
		*item=i;
		ListPushHead(l,item);	
	}
	ASSERT_THAT(ListCountItems(l)==3);
	for(i=0;i<3;i++)
	{
		item=(int*)malloc(1*sizeof(int*));
		*item=i;
		ListPopHead(l,&vp);	
	}
	ListDestroy(&l,destroyItem);
	ASSERT_THAT(ListCountItems(l)==0);
	ASSERT_THAT(l==NULL);
END_UNIT

UNIT(List_Pop_Tail)
	List* l=ListCreate();
	int i;
	int *item;
	void* vp;
	for(i=0;i<1;i++)
	{
		item=(int*)malloc(1*sizeof(int*));
		*item=i;
		ListPushHead(l,item);	
	}
	ASSERT_THAT(ListCountItems(l)==3);
	for(i=0;i<3;i++)
	{
		item=(int*)malloc(1*sizeof(int*));
		*item=i;
		ListPopTail(l,&vp);	
	}
	ASSERT_THAT(ListCountItems(l)==0);
	ASSERT_THAT(l==NULL);
END_UNIT

UNIT(For_Each)
	List* l=ListCreate();
	int i;
	int *item;
	void* vp;
	DLLElementAction action=PrintElement;
	for(i=0;i<3;i++)
	{
		item=(int*)malloc(1*sizeof(int*));
		*item=i+5;
		ListPushHead(l,item);	
	}
	printList(l,action);
	printf("\n\n");
	printf("DLLForEach = %ld\n",DLLForEach(l,action,NULL));
END_UNIT

UNIT(ListItr_Begin_TEST)
	List* l=ListCreate();
	int i;
	int *item;
	void* vp;
	DLLElementAction action=PrintElement;
	Node* temp;
	for(i=0;i<3;i++)
	{
		item=(int*)malloc(1*sizeof(int*));
		*item=i+5;
		ListPushHead(l,item);	
	}
	/*temp=ListItr_Begin(l);*/
	printList(l,action);
	printf("\n\n");
	printf("DLLForEach = %ld\n",DLLForEach(l,action,NULL));
END_UNIT

TEST_SUITE(Dynamic Vector Module Unit Test)
/*	TEST(List_Create)
	TEST(List_Push_Head)
	TEST(List_Push_Tail)
	TEST(List_Pop_Head)
	TEST(List_Pop_Tail)
	TEST(For_Each)*/
	
	TEST(ListItr_Begin_TEST)
	
END_SUITE




