#include "vector.h"
#include "test.h"

int main()
{
	int choice, item,itSet;
	int* itDel;
	int* itGet;
	int* numOfItems;
	size_t initialSize,extensionBblockSize,indexGet;
	Vector *v=NULL;

	ADTErr err;
	while(1)
	{
		printf("choose an option\n");
		printf("1 create vector\n");
		printf("2 destroy vector\n");
		printf("3 add item\n");
		printf("4 delete item\n");
		printf("5 get item\n");
		printf("6 set item\n");
		printf("7 print vector\n");
		scanf("%d",&choice);
		
		switch (choice)
		{
		case 1:
			printf("choose vector size and extension block size\n");
			scanf("%lu",&initialSize);
			scanf("%lu",&extensionBblockSize);
			v = VectorCreate(initialSize,extensionBblockSize);
			break;
			
		case 2:
			v = VectorCreate(initialSize,extensionBblockSize);
			break;
			
		case 3:
			printf("choose int item to add\n");
			scanf("%d",&item);
			err=VectorAdd(v,item);
			break;
		
		case 4:
			if(NULL==v)
			{
				printf("vector is not initiallized\n");
				break;
			}
			err=VectorDelete(v,itDel);
			printf("the deleted item was %d\n",*itDel);
			break;
			
		case 5:
			if(NULL==v)
			{
				printf("vector is not initiallized\n");
				break;
			}
			printf("insert index for getting an item\n");
			scanf("%lu",&indexGet);
			err=VectorGet(v,indexGet,itGet);
			printf("get item was %d\n",*itGet);
			break;
			
		case 6:
			if(NULL==v)
			{
				printf("vector is not initiallized\n");
				break;
			}
			printf("insert item and index to insert\n");
			scanf("%d",&itSet);
			scanf("%lu",&indexGet);
			err=VectorSet(v,indexGet,itSet);
			break;

		case 7:
			if(NULL==v)
			{
				printf("vector is not initiallized\n");
				break;
			}
			stackPrint(v);
			break;
			
		default:
				printf("please choose a valid option\n");
			break;
			
		case 8:
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
