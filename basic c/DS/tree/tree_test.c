#include "mu_test.h"/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: doublelinked testing
* 						DATE: 02-07-2019 16:18:05
*******************************************************************************/

#include <assert.h>
#include "tree.h"


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

UNIT(Tree_Insert)
	Tree* t=NULL;
	t=TreeCreate();
	ASSERT_THAT(t!=NULL);
	TreeInsert(t,3);
	TreeInsert(t,2);
	TreeInsert(t,6);
	ASSERT_THAT(t!=NULL);
END_UNIT

UNIT(Tree_Destroy)
	Tree* t=NULL;
	t=TreeCreate();
	TreeInsert(t,3);
	TreeInsert(t,2);
	TreeInsert(t,6);
	TreeDestroy(t);
	ASSERT_THAT(t==NULL);
END_UNIT

UNIT(prints)
	Tree* t=NULL;
	t=TreeCreate();
	ASSERT_THAT(t!=NULL);
	TreeInsert(t,3);
	TreeInsert(t,2);
	TreeInsert(t,6);
	TreeInsert(t,1);
	TreeInsert(t,4);
	TreeInsert(t,5);
	
	printf("preorder\n");
	TreePrint(t,PRE_ORDER);
	printf("\n");
	
	printf("inorder\n");
	TreePrint(t,IN_ORDER);
	printf("\n");
	
	printf("postorder\n");
	TreePrint(t,POST_ORDER);
	printf("\n");
END_UNIT

UNIT(find)
	Tree* t=NULL;
	t=TreeCreate();
	TreeInsert(t,2);
	TreeInsert(t,1);
	ASSERT_THAT(1==TreeIsDataFound(t,2));
	ASSERT_THAT(0==TreeIsDataFound(t,3));
END_UNIT

UNIT(is_FullTree)
	Tree* t=NULL;
	int full=0;
	t=TreeCreate();
	TreeInsert(t,40);
	TreeInsert(t,50);
	TreeInsert(t,30);
	TreeInsert(t,20);
	TreeInsert(t,60);
	TreeInsert(t,35);
	TreeInsert(t,45);
	full=isFullTree(t);
	ASSERT_THAT(full==1);
	TreeDestroy(t);
END_UNIT

UNIT(is_SimilarTree)
	Tree* t1=NULL;
	Tree* t2=NULL;	
	int full=0;
	t1=TreeCreate();
	t2=TreeCreate();
	TreeInsert(t1,20);
	TreeInsert(t1,10);
	TreeInsert(t1,30);
	TreeInsert(t1,1);
	
	TreeInsert(t2,50);
	TreeInsert(t2,40);
	TreeInsert(t2,60);
	TreeInsert(t2,1);
	full=isSimilarTree(t1,t2);
	ASSERT_THAT(full==1);
	TreeDestroy(t1);
	TreeDestroy(t2);
END_UNIT

UNIT(is_PerfectTree)
	Tree* t=NULL;
	int full=0;
	t=TreeCreate();
	TreeInsert(t,20);
	TreeInsert(t,10);
	TreeInsert(t,30);
	full=isPerfectTree(t);
	ASSERT_THAT(full==1);
	TreeDestroy(t);
END_UNIT

UNIT(is_MirrorTree)
	Tree* t=NULL;
	int full=0;
	t=TreeCreate();
	TreeInsert(t,2);
	TreeInsert(t,1);
	TreeInsert(t,3);
	TreeInsert(t,4);
	TreeInsert(t,0);
	TreePrint(t,IN_ORDER);
	printf("\n");
	MirrorTree(t);
	TreePrint(t,IN_ORDER);
	printf("\n");
	TreeDestroy(t);
END_UNIT

TEST_SUITE(Dynamic Vector Module Unit Test)
	/*TEST(Tree_Insert)
	TEST(Tree_Destroy)
	TEST(prints)
	TEST(find)
	TEST(is_FullTree)
	TEST(is_SimilarTree)
	TEST(is_PerfectTree)*/
	TEST(is_MirrorTree)
END_SUITE
