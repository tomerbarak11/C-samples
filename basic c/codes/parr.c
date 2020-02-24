#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN 4

#include "parr.h"

void enterStudent(struct student *arr);
void sortId(struct student *arr);
void sortPhone(struct student *arr);
void sortName(struct student *arr);
void removeStudent(struct student *arr,int _index);
void print(struct student *arr);

void enterStudent(struct student *arr)
{
	
	strcpy(arr[0].name, "tomer");
	arr[0].id = 123;
	arr[0].phone = 44;
	arr[0].grade = 98;

	strcpy(arr[1].name, "alon");
	arr[1].id = 456;
	arr[1].phone = 33;
	arr[1].grade = 95;

	strcpy(arr[2].name, "hadar");
	arr[2].id = 789;
	arr[2].phone = 40;
	arr[2].grade = 96;

	strcpy(arr[3].name, "udi");
	arr[3].id = 1;
	arr[3].phone = 2;
	arr[3].grade = 3;
}
void sortId(struct student *arr)
{
	int i, j;
	struct student temp;

	for (i = 0; i < LEN - 1; i++)
	{
		for (j = 0; j < (LEN - 1 - i); j++)
		{
			if (arr[j].id > arr[j + 1].id)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void sortPhone(struct student *arr)
{
	int i, j;
	struct student temp;

	for (i = 0; i < LEN - 1; i++)
	{
		for (j = 0; j < (LEN - 1 - i); j++)
		{
			if (arr[j].phone > arr[j + 1].phone)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void sortName(struct student *arr)
{
	int i, j;
	struct student temp;

	for (i = 0; i < LEN - 1; i++)
	{
		for (j = 0; j < (LEN - 1 - i); j++)
		{
			if (strcmp(arr[j].name, arr[j+1].name)>0)
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
void removeStudent(struct student *arr,int _index)
{
	int i;
	for (i = _index; i < LEN - 1;i++)
	{
		arr[i] = arr[i +1];
	}
	strcpy(arr[2].name,"none");
	arr[2].id = 0;
	arr[2].phone = 0;
	arr[2].grade = 0;
}
void print(struct student *arr)
{
	int i;
	for(i=0;i<LEN;i++)
	{
		printf("name = %s id = %u phone = %u grade = %u\n\n", arr[i].name,arr[i].id,arr[i].phone,arr[i].grade);
	}
}
