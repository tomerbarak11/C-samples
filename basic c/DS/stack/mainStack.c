#include "vector.h"
#include "test.h"

int main()
{
	int choice, item,itSet;
	int* itDel;
	int* itGet;
	int* numOfItems;
	size_t initialSize,extensionBblockSize,indexGet;
	stack *s=NULL;

	ADTErr err;
	while(1)
	{
		printf("choose an option\n");
		printf("1 create stack\n");
		printf("2 destroy stack\n");
		printf("3 push item\n");
		printf("4 pop item\n");
		printf("5 get top item\n");
		printf("6 check if stack is empty\n");
		printf("7 print vector\n");
		scanf("%d",&choice);
		
		switch (choice)
		{
		case 1:
			printf("choose stack size and extension block size\n");
			scanf("%lu",&initialSize);
			scanf("%lu",&extensionBblockSize);
			s = VectorCreate(initialSize,extensionBblockSize);
			break;
			
		case 2:
			s = VectorCreate(initialSize,extensionBblockSize);
			break;
			
		case 3:
			printf("choose int item to add\n");
			scanf("%d",&item);
			err=VectorAdd(v,item);
			break;
		
		case 4:
			if(NULL==s)
			{
				printf("stack is not initiallized\n");
				break;
			}
			err=VectorDelete(v,itDel);
			printf("the deleted item was %d\n",*itDel);
			break;
			
		case 5:
			if(NULL==s)
			{
				printf("stack is not initiallized\n");
				break;
			}
			printf("insert index for getting an item\n");
			scanf("%lu",&indexGet);
			err=VectorGet(s,indexGet,itGet);
			printf("get item was %d\n",*itGet);
			break;
			
		case 6:
			if(NULL==s)
			{
				printf("stack is not initiallized\n");
				break;
			}
			printf("insert item and index to insert\n");
			scanf("%d",&itSet);
			scanf("%lu",&indexGet);
			err=VectorSet(s,indexGet,itSet);
			break;
			
		case 7:
			if(NULL==s)
			{
				printf("stack is not initiallized\n");
				break;
			}
			err=VectorItemsNum(s,numOfItems);
			printf("the number of items is %d\n",*numOfItems);
			break;
			
		case 8:
			if(NULL==s)
			{
				printf("stack is not initiallized\n");
				break;
			}
			VectorPrint(s);
			break;
			
		default:
				printf("please choose a valid option\n");
			break;
			
		case 9:
			{

				if(VectorCreateTest()==ERR_OK)
				{
					printf("ERR_OK\n");
				}
				else if(VectorCreateTest()==ERR_GENERAL)
				{
					printf("ERR_GENERAL\n");
				}
			}
			
		}
	}
}
