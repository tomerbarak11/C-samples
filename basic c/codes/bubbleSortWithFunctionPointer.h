#ifndef _bubbleSortWithFunctionPointer_h_
#define _bubbleSortWithFunctionPointer_h_

static void swap(int *_a, int *_b);
void bubbleSort(int (*f)(int,int),int _arr[], int _n);
static void printArray(int arr[], int size);
static int intcmp(int a,int b);
static int lastDigitSort(int a,int b);

typedef int (*funcPointer)(int,int);
#endif
