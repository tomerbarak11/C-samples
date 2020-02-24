#include "mu_test.h"/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: vectorGeneric testing
* 						DATE: 22-07-2019 12:07:23
*******************************************************************************/

#include <assert.h>
#include "vectorGeneric.h"


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
 
 typedef struct Person Person;
 struct Person{
	int m_id;
	char m_name[128];
	int m_age;
};
static void destroyOneElement(void* _item);
static int PrintElement(void* _element, size_t _index, void* _context);
static int PrintElement(void* _element, size_t _index, void* _context)
{
	printf("item number %ld is %d\n",_index,*(int*)_element);
return 1;
}

static void destroyOneElement(void* _item)
{	
	if(NULL==_item)
	{
		return;
	}
	free(_item);
}

UNIT(Vector_Create_AND_Destroy)
	Vector* v=NULL;
	VectorItem fp;
	int choice=1;
	void* num1,*num2;
	int arr[]={1,2,3};
	int *n1,*n2;
	n1=(int*)malloc(1*sizeof(int));
	n2=(int*)malloc(1*sizeof(int));
	*n1=4;
	*n2=5;
	/*printf("Enter 1 for ints vector or 2 for persons vector);
	scanf("%d",&choice);*/
	if(choice==1)
	{
		v=VectorCreate(50,100);
	}
	fp=destroyOneElement;
	VectorDestroy(&v,fp);
END_UNIT

UNIT(Print_Int)
	Vector* v=NULL;
	VectorItem fp;
	print printPointer;
	int choice=1;
	void* num1,*num2;
	int arr[]={1,2,3};
	int *n1,*n2;
	n1=(int*)malloc(1*sizeof(int));
	n2=(int*)malloc(1*sizeof(int));
	*n1=4;
	*n2=5;
	/*printf("Enter 1 for ints vector or 2 for persons vector);
	scanf("%d",&choice);*/
	if(choice==1)
	{
		v=VectorCreate(50,100);
		VectorAppend(v,n1);
		VectorAppend(v,n2);
	}
	printPointer=printInt;
	
	fp=destroyOneElement;
	VectorDestroy(&v,fp);
END_UNIT

UNIT(Print_Person)
	Vector* v=NULL;
	VectorItem fp;
	print printPointer;
	int choice=1;
	void* num1,*num2;
	int arr[]={1,2,3};
	Person *p1,*p2;
	
	p1=(Person*)malloc(1*sizeof(Person));
	p1->m_id=123;
	strcpy(p1->m_name,"Tomer");
	p1->m_age=27;
	
	p2=(Person*)malloc(1*sizeof(Person));
	p1->m_id=456;
	strcpy(p1->m_name,"Alon");
	p1->m_age=25;
	v=VectorCreate(50,100);
	VectorAppend(v,p1);
	VectorAppend(v,p2);
	printPointer=printPerson;
	printPrintGeneral(v,printPointer);
	fp=destroyOneElement;
	VectorDestroy(&v,fp);
END_UNIT

UNIT(Vector_For_Each)
	int i=10,j=80;
	Vector* vec = VectorCreate(10, 5);
	VectorElementAction func;

	ASSERT_NOT_EQUAL_PTR(vec, NULL);
	VectorAppend(vec,&i);
	VectorAppend(vec,&j);

	func=PrintElement;
	ASSERT_THAT(VectorForEach(vec,func,NULL) !=0);

END_UNIT

TEST_SUITE(Dynamic Vector Module Unit Test)
	/*TEST(Vector_Create_AND_Destroy)*/
	/*TEST(Print_Int)*/
	/*TEST(Print_Person)*/
	TEST(Vector_For_Each)
END_SUITE
