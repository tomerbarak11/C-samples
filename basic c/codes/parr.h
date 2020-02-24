#ifndef _PARR_H_
#define _PARR_H_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LEN 4

struct student{
	char name[20];
	unsigned int id;
	unsigned int phone;
	unsigned int grade;
};

typedef struct student st;

void enterStudent(struct student *arr);
void sortId(struct student *arr);
void sortPhone(struct student *arr);
void sortName(struct student *arr);
void removeStudent(struct student *arr,int _index);
void print(struct student *arr);


#endif
