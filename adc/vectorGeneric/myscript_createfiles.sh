#!/bin/bash

gedit $1.c $1_test.c $1.h &

DATE=`date '+%d-%m-%Y %H:%M:%S'`

echo "/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: $1 code
* 						DATE: $DATE
*******************************************************************************/

#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc */
#include <string.h>        /* strcat, strlen, strcpy                           */
#include \"$1.h\"


" >> $1.c

echo "/**************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: $1 header
* 						DATE: $DATE
*******************************************************************************/

#ifndef __`printf '%s' "$1" | awk '{ print toupper($0) }'`_H__
#define __`printf '%s' "$1" | awk '{ print toupper($0) }'`_H__

/**@Description:
 * Average time complexity :
 * Worst : 
 * @params _x :
 * @returns:
 */


#endif          /* $1 s*/



" >> $1.h


#~/git/gpush
clear

