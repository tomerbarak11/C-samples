/**************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: bubbleShakeQuick header
* 						DATE: 11-07-2019 15:00:57
*******************************************************************************/

#ifndef __BUBBLESHAKEQUICK_H__
#define __BUBBLESHAKEQUICK_H__
#include "vector.h"
#include <math.h>
/**@Description:
 * Average time complexity :
 * Worst : 
 * @params _x :
 * @returns:
 */

ADTErr bubbleSort(Vector* _vec);
ADTErr shakeSort(Vector* _vec);
ADTErr insertionSort(Vector* _vec);
ADTErr quickSort(Vector* _vec,int low, int high);
ADTErr shellSort(Vector* _vec);
ADTErr selectionSort(Vector* _vec);
ADTErr countingSort(Vector* _vec,int range);
ADTErr mergeSort(Vector* _vec);
ADTErr radixSort(Vector* _vec,int _digits);
void printArr(Vector* _vec);
int isSorted(Vector* _vec);
#endif          /* bubbleShakeQuick s*/




