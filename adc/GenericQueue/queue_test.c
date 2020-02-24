#include "mu_test.h"/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: queue testing
* 						DATE: 27-06-2019 14:57:43
*******************************************************************************/

#include <assert.h>
#include "GenericQueue.h"
static int PrintElement(void* _element, size_t _index, void* _context);
static int PrintElement(void* _element, size_t _index, void* _context)
{
	if(NULL==_element)
	{
		return 0;
	}
	printf("item number %ld is %d\n",_index,*(int*)_element);
return 1;
}

UNIT(Create_Queue)
	Queue *q=NULL;
	q = QueueCreate(5);
END_UNIT

UNIT(Destroy_Queue)
	int magicNumber;
	_elementDestroy voidPointer=destroyOneElement;
	int *n1,*n2;
	Queue *q=NULL;
	q = QueueCreate(5);
	n1=(int*)malloc(1*sizeof(int));
	n2=(int*)malloc(1*sizeof(int));
	*n1=1;
	*n2=2;
	QueueEnqueue(q,n1);
	QueueEnqueue(q,n2);
	
	QueueDestroy(&q,voidPointer);
	magicNumber=getMagicNumber(q);
	ASSERT_THAT(magicNumber==0);
END_UNIT

UNIT(Is_Empty_And_Is_Full)
	int magicNumber;
	_elementDestroy voidPointer=destroyOneElement;
	int *n1,*n2;
	Queue *q=NULL;
	q = QueueCreate(2);
	n1=(int*)malloc(1*sizeof(int));
	n2=(int*)malloc(1*sizeof(int));
	*n1=1;
	*n2=2;
	ASSERT_THAT(QueueIsFull(q)==0);
	ASSERT_THAT(QueueIsEmpty(q)==1);
	QueueEnqueue(q,n1);
	ASSERT_THAT(QueueIsFull(q)==0);
	QueueEnqueue(q,n2);
	ASSERT_THAT(QueueIsFull(q)==1);
	ASSERT_THAT(QueueIsEmpty(q)==0);
	
END_UNIT

UNIT(For_Each)
	int magicNumber;
	QueueElementAction func=PrintElement;
	int *n1,*n2;
	Queue *q=NULL;
	q = QueueCreate(2);
	n1=(int*)malloc(1*sizeof(int));
	n2=(int*)malloc(1*sizeof(int));
	*n1=1;
	*n2=2;
	QueueEnqueue(q,n1);
	QueueEnqueue(q,n2);
	ASSERT_THAT(QueueForEach(q,func,NULL) !=0);
END_UNIT

TEST_SUITE(Dynamic Vector Module Unit Test)
	TEST(Create_Queue)
	TEST(Destroy_Queue)
	TEST(Is_Empty_And_Is_Full)
	TEST(For_Each)
END_SUITE




