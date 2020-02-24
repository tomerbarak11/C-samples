#include "mu_test.h"
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

#include "linked.h"

UNIT(List_Insert_Head)
	person* nullHead=NULL;
	person* notNullHead;
	person nullP;
	person notNullP;
	
	person p1,p2;
    p1.m_id=10;
    strcpy(p1.m_name,"tomer");
    p1.m_age=27;
    p1.m_next=NULL;

    p2.m_id=20;
    strcpy(p2.m_name,"alon");
    p2.m_age=25;
    p2.m_next=NULL;

/*test number 1*/
	ASSERT_EQUAL_INT(ListInsertHead(NULL,&p1),&p1);
	ASSERT_THAT(p1.m_next==NULL);

/*test number 2*/
	ASSERT_EQUAL_INT(ListInsertHead(&p2,&p1),&p1);
	ASSERT_THAT(p2.m_next==NULL);


END_UNIT



TEST_SUITE(Dynamic Vector Module Unit Test)
	TEST(List_Insert_Head)
	/*TEST(add_small_ints)
	TEST(add_large_numbers_will_fail)

	TEST(accessing_null_pointer_will_fail)
	IGNORE_TEST(work_in_progress)
	TEST(say_hello)

	TEST(test_c_strings)*/
END_SUITE

