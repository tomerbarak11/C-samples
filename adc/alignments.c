#include <stdio.h>

typedef struct Person
{
	int id;
	char name[30];
	int age;
	int education;
	double salary;
}p,*ps,pp[5];

int main()
{
	p p1;
	printf("adress of id = %p\n",(void*)&(p1.id));
	printf("adress of name = %p\n",(void*)&p1.name);
	printf("adress of age = %p\n",(void*)&p1.age);
	printf("adress of education = %p\n",(void*)&p1.education);
	printf("adress of salary = %p\n",(void*)&p1.salary);
	printf("size of person = %ld\n",sizeof(p1));
	return 0;
}
