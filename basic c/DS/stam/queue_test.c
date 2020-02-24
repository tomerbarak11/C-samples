/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: queue testing
* 						DATE: 27-06-2019 14:57:43
*******************************************************************************/

#include <assert.h>
#include "queue.h"

int main()
{
	int choice,res,item,out;
	size_t capacity;
	queue *q=NULL;

	ADTErr err;
	while(1)
	{	
		printf("choose an option\n");
		printf("1 create queue\n");
		printf("2 destroy queue\n");
		printf("3 check if queue is empty\n");
		printf("4 check if queue is full\n");
		printf("5 enqueue\n");
		printf("6 dequeue\n");
		printf("7 print queue\n");
		scanf("%d",&choice);
		
		switch (choice)
		{
		case 1:
			printf("choose capacity\n");
			scanf("%lu",&capacity);
			q = queueCreate(capacity);
			break;
			
		case 2:
			queueDestroy(q);
			break;
			
		case 3:
			if(NULL==q)
			{
				printf("queue is not initiallized\n");
				break;
			}
			res=queueIsEmpty(q);
			if(res==1)
			{
				printf("queue is empty\n");
			}
			else
			{
				printf("queue is not empty\n");
			}
			break;
		
		case 4:
			if(NULL==q)
			{
				printf("queue is not initiallized\n");
				break;
			}
			res=queueIsFull(q);
			if(res==0)
			{
				printf("queue is empty\n");
			}
			else
			{
				printf("queue is not empty\n");
			}
			break;
			
		case 5:
			if(NULL==q)
			{
				printf("queue is not initiallized\n");
				break;
			}
			printf("insert an item\n");
			scanf("%d",&item);
			err=enqueue(q,item);
			printf("get item was %d\n",item);
			break;
			
		case 6:
			if(NULL==q)
			{
				printf("queue is not initiallized\n");
				break;
			}
			err=dequeue(q,&out);
			printf("get item was %d\n",out);
			break;
			
		default:
				printf("please choose a valid option\n");
				break;
			
		}
	}
    return 0;
}
