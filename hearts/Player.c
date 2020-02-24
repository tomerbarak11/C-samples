/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: Player code
* 						DATE: 18-07-2019 10:06:56
*******************************************************************************/

#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc */
#include <string.h>        /* strcat, strlen, strcpy                           */
#include "Player.h"
#include "vector.h"
#include "bubbleShakeQuick.h"
struct Player{
	char name[15];
	Vector *vecOfCards;
};
static void swapInVector(Vector* _v,int _i,int _j);

/**@Description:checks if card is ok according to game conditions
 * @params _x :_fourCardsOfTrick = cards played in trick,
 _selected Card by user, v=hand of player
 * @returns: 1 if ok and 0 if not
 */
static int isCardOk(int *_fourCardsOfTrick,int _selectedCard,Vector* _v,int* _heartBreak);
Player* PlayerCreate(char* _name)
{
	Player* p;
	int i;
	p=(Player*)malloc(1*sizeof(Player));
	if(NULL==p)
	{
		printf("Allocation fail\n");
		return NULL;
	}
	strcpy(p->name,_name);
	return p;
}

Player* setVectorOfCards(Player* _p)
{
	int i;
	_p->vecOfCards=VectorCreate(13,1);
	return _p;
}

void cardsInsertionSort(Player* _p)
{
	insertionSort(_p->vecOfCards);
}

void setCard(Player *_p,int _data)
{
	VectorAdd(_p->vecOfCards,_data);
}

Vector *getVecOfCards(Player* _p)
{
	return _p->vecOfCards;
}

static int isCardOk(int *_fourCardsOfTrick,int _selectedCard,Vector* _v,int* _heartBreak)
{
	int i;
	int cardsInHand;
	int item;
	int noLeadingSuit=0;
	int countNonMatch=0;
	int countHearts=0;
	VectorItemsNum(_v,&cardsInHand);
	/*First player*/

	
	if(_fourCardsOfTrick[0]==-1)
	{
		return 1;
	}
	
	/*Player has same suit*/
	else if(_fourCardsOfTrick[0]/13==_selectedCard/13)
	{
		return 1;
	}
	/*Player has not matching suit*/
	printf("cardsInHand = %d\n",cardsInHand);
	
	for(i=0;i<cardsInHand;i++)
	{
		VectorGet(_v,i,&item);	
		if(item/13!=_fourCardsOfTrick[0]/13)
		{
			countNonMatch++;
		}	
	}
	if(countNonMatch==cardsInHand)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int selectCardHuman(Player* specPlayer, int* fourCardsOfTrick,int *_heartBreak)
{
	int i,indexOfSelectedCard,num,tempNum;
	int cardsInHand;
	int statusCardOk=0;
	VectorItemsNum(specPlayer->vecOfCards,&cardsInHand);
	printf("%d cards before selection\n",cardsInHand);
	while(1)
	{
		printf("Select an index of card to play\n");
		scanf("%d",&indexOfSelectedCard);
		VectorGet(specPlayer->vecOfCards,indexOfSelectedCard-1,&num);
		tempNum=num;
		statusCardOk=isCardOk(fourCardsOfTrick,num,specPlayer->vecOfCards,_heartBreak);
		if(statusCardOk!=0)
		{
			if(indexOfSelectedCard<0||indexOfSelectedCard>cardsInHand)
			{
				printf("Wrong index of card\n");
			}
			else
			{
				printCardWithIndex(specPlayer,indexOfSelectedCard-1);
				printf("Cards in hand=%d\n",cardsInHand);
				printf("Index of selected card = %d\n\n",indexOfSelectedCard);		
				swapInVector(specPlayer->vecOfCards,indexOfSelectedCard,cardsInHand-1);
				VectorDelete(specPlayer->vecOfCards,&num);				
				cardsInsertionSort(specPlayer);				
				VectorItemsNum(specPlayer->vecOfCards,&cardsInHand);
				printf("cardsInHand = %d\n",cardsInHand);
				VectorItemsNum(specPlayer->vecOfCards,&cardsInHand);
				printf("%d cards after selection\n",cardsInHand);
				printf("\n");
				return tempNum;
			}
		}
		else
		{
			printf("Card does not match to leading suit\n");
			statusCardOk=0;
		}	
	}
}

int selectCardComputer(Player* specPlayer, int* fourCardsOfTrick,int* _heartBreak)
{
	int i,num,tempNum;
	int cardsInHand;
	int statusCardOk=0;
	int isLastSelected=0;
	VectorItemsNum(specPlayer->vecOfCards,&cardsInHand);
	while(1)
	{
		for(i=cardsInHand-1;i>=0;i--)
		{
			VectorGet(specPlayer->vecOfCards,i,&tempNum);
			statusCardOk=isCardOk(fourCardsOfTrick,tempNum,specPlayer->vecOfCards,_heartBreak);
			if(statusCardOk==1)
			{
				break;
			}
		}
		if(statusCardOk==1)
		{
			break;
		}
	}
	swapInVector(specPlayer->vecOfCards,i,cardsInHand-1);	
	printf("%d cards before selection\n",cardsInHand);
	VectorDelete(specPlayer->vecOfCards,&num);
	
	/*VectorPrint(specPlayer->vecOfCards);*/
	
	VectorItemsNum(specPlayer->vecOfCards,&cardsInHand);
	printf("%d cards after selection\n",cardsInHand);
	printf("Chose: ");
	printOneElement(tempNum);
	printf("\n");
	return tempNum;
}

void printCardWithIndex(Player* specPlayer,int indexOfSelectedCard)
{
	int num;
	VectorGet(specPlayer->vecOfCards,indexOfSelectedCard,&num);
	printf("You chose ");
	printOneElement(num);
}

static void swapInVector(Vector* _vec,int i,int j)
{
	int index1value,index2value;
	VectorGet(_vec,i,&index1value);
	VectorGet(_vec,j,&index2value);
	VectorSet(_vec,i,index2value);
	VectorSet(_vec,j,index1value);	
	return;
}
