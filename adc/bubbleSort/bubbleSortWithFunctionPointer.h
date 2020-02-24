#ifndef _bubbleSortWithFunctionPointer_h_
#define _bubbleSortWithFunctionPointer_h_


void bubbleSort(int (*f)(void*,void*),void* _arr[], int _n);
static int intcmp(void* a,void* b);
static int lastDigitSort(void* a,void* b);

typedef int (*funcPointer)(void*,void*);
#endif
