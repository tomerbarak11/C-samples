/**************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: Deck code
* 						DATE: 18-07-2019 13:51:56
*******************************************************************************/
#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc */
#include <string.h>        
/* strcat, strlen, strcpy                           */
#include "Card.h"
#include "Game.h"
#include "Round.h"
#include "math.h"
#include "Player.h"
#include "time.h"
static void swap(int* a,int i,int j);
int* CardsCreate(Game* _g)
{
	int i;
	int *cardsArr;
	cardsArr=(int*)malloc(52*sizeof(int));
	if(NULL==cardsArr)
	{
		printf("Allocation fail\n");
		return NULL;
	}
	return cardsArr;
}

void DealCards(Player** _p)
{
	int i,j,numOfCard;
	int numberOfCardsLeft=52;
	int arrCardsLeft[52];
	int indexToSelect;
	int checkItem;
	int counters[52];
	for(i=0;i<52;i++)
	{
		arrCardsLeft[i]=i;
	}
	
	for(i=0;i<52;i++)
	{
		counters[i]=-1;
	}
	
    srand(time(NULL)); 
	for(i=0;i<4;i++)
	{
		for(j=0;j<13;j++)
		{
			indexToSelect=rand()%numberOfCardsLeft;
			numOfCard=arrCardsLeft[indexToSelect];
			setCard(_p[i],numOfCard);
			cardsInsertionSort(_p[i]);
			swap(arrCardsLeft,indexToSelect,numberOfCardsLeft-1);
			numberOfCardsLeft--;
		}
	}
}

static void swap(int* a,int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
