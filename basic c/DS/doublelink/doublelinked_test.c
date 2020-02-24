#include "mu_test.h"/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: doublelinked testing
* 						DATE: 02-07-2019 16:18:05
*******************************************************************************/

#include <assert.h>
#include "doublelinked.h"


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

#include "doublelinked.h"

UNIT(List_Create)
	List* l=ListCreate();
	ListPushHead(l,1);
	ListPushHead(l,2);
	PrintList(l);
	printf("\n");
END_UNIT

UNIT(List_Push_Head)
	List* l=ListCreate();
	ListPushHead(l,1);
	ListPushTail(l,0);
	PrintList(l);
	printf("\n");
END_UNIT

UNIT(List_Pop_Head)
	int x;
	List* l=ListCreate();
	ListPushHead(l,1);
	ListPushHead(l,2);
	ListPushHead(l,3);
	printf("\n");
	printf("before pop number of items = %lu\n",ListCountItems(l));
	ListPopHead(l,&x);
	printf("x out = %d\n",x);
	printf("after pop number of items = %lu\n",ListCountItems(l));
	PrintList(l);
		PrintList(l);
	printf("\n\n");
END_UNIT

UNIT(List_Pop_Tail)
	int y;
	List* l=ListCreate();
	ListPushHead(l,1);
	ListPushHead(l,2);
	ListPushHead(l,3);
	ListPushHead(l,4);
	ListPushHead(l,5);
	ListPushHead(l,6);
	ListPushHead(l,7);
	printf("before pop number of items = %lu\n",ListCountItems(l));
	printf("\n");
	ListPopTail(l,&y);
	printf("y out = %d\n",y);
	printf("after pop number of items = %lu\n",ListCountItems(l));
	PrintList(l);
	printf("\n\n");
END_UNIT

TEST_SUITE(Dynamic Vector Module Unit Test)
	TEST(List_Create)
	TEST(List_Push_Head)
	TEST(List_Pop_Head)
	TEST(List_Pop_Tail)
	/*TEST(add_small_ints)
	TEST(add_large_numbers_will_fail)

	TEST(accessing_null_pointer_will_fail)
	IGNORE_TEST(work_in_progress)
	TEST(say_hello)

	TEST(test_c_strings)*/
END_SUITE




