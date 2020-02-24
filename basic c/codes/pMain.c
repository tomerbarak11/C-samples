#include "parr.h"

int main()
{
	struct student arr[LEN];
	int choice,_index;
	struct student *ps=NULL;
	ps=(struct student*)malloc(sizeof(struct student)*LEN);
	if(!ps)
	{
		printf("malloc failure");
		exit(1);
	}
	else
		printf("malloc success\n");
		
	enterStudent(arr);
	printf("select option:\n1 sort id 2 sort phone 3 sort name 4 remove student _index 5 print students\n");
	scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("before id sort\n");
		print(arr);
		sortId(arr);
		printf("after id sort\n");
		print(arr);
		break;
	case 2:
		printf("before phone sort\n");
		print(arr);
		sortPhone(arr);
		printf("after phone sort\n");
		print(arr);
		break;
	case 3:
		printf("before name sort\n");
		print(arr);
		sortName(arr);
		printf("after name sort\n");
		print(arr);
		break;
	case 4:
		printf("enter _index to remove\n");
		scanf("%d", &_index);
		removeStudent(arr,_index);
		print(arr);
		break;
	case 5:
		print(arr);
		break;
	}
	return 0;
}
