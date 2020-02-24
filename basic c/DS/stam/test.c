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

#include "mu_test.h"
#include "funcs.h"

UNIT(cr)
	int a = 100;
	int b = 200;
	int mx = MAX(a, b);
	int mn = MIN(a, b);
	ASSERT_THAT(queueCreate(30));
	ASSERT_THAT(mx > mn);

	ASSERT_THAT( MAX(a,b) > MIN(a,b) );

	TRACE_LOG("%d", MAX(3, 12));

END_UNIT

UNIT(des)
	int a = 42;
	int b = 100;
	int r = add(a, b);

	ASSERT_THAT( r == 142);
	ASSERT_EQUAL_INT(142, r);
END_UNIT

UNIT(empty)
	int large = (int)(~0U>>1);
	int larger;


	TRACE_LOG("a = -~0 == : %d ", large);
	ASSERT_THAT(large > 0);

	larger = add(large, 1);
	TRACE_LOG("large + 1 == %d ", larger);

	ASSERT_NOT_EQUAL_INT(larger, large);
	ASSERT_EQUAL_INT(larger - large, 1);
	ASSERT_THAT( larger > large);
END_UNIT

UNIT(full)
	int *p = 0;

	ASSERT_THAT(p == 0);
	ASSERT_EQUAL_PTR(p, NULL);

	/* DANGER */
	*p = 42;

	/* Will not reach next statement */
	ASSERT_THAT(1!=0);
END_UNIT

UNIT(say_hello)
	const char* msg = say();

	ASSERT_NOT_EQUAL_PTR(msg, NULL);
	ASSERT_EQUAL_STR(msg, "Join Linux Haters club!");
END_UNIT


UNIT(work_in_progress)
	ASSERT_THAT(say() != 0);
END_UNIT

UNIT(test_c_strings)
	const char* snull = 0;
	const char* msg = "hello";

	ASSERT_EQUAL_STR(msg, "hello");
	ASSERT_EQUAL_STR(snull, "");
	ASSERT_NOT_EQUAL_STR(snull, "");


END_UNIT

TEST_SUITE(Dynamic Vector Module Unit Test)
	TEST(cr)
	TEST(des)
	TEST(empty)

	TEST(full)
	IGNORE_TEST(work_in_progress)
	TEST(say_hello)

	TEST(test_c_strings)
END_SUITE

