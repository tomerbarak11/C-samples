/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: Round code
* 						DATE: 18-07-2019 10:05:54
*******************************************************************************/

#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc */
#include <string.h>        /* strcat, strlen, strcpy                           */
#include "Round.h"
#include "Game.h"
#include "Player.h"
#include "Deck.h"
struct Round{
	int roundPoints[4];
	int numOfTricks;
};
static void printRoundPoints(Round* _r);
static void setRoundPoints(Round* _r,int _loser,int _losersPoints);
static int WhoLost(int* _fourCardsOfTrick,int saveFirst);
static int playTrick(Game* _g,Round *_r,int _first,int _numOfRounds,int *_heartBreak);
static int calculateLosersPoints(int* _fourCardsOfTrick);
static int SelectFirstPlayer(Game* _g);
Round* RoundCreate(Game* _g)
{
	Round* r;
	int i;
	Vector* v[4];
	r=(Round*)malloc(1*sizeof(Round));
	if(NULL==r)
	{
		printf("Allocation fail\n");
		return NULL;
	}
	for(i=0;i<4;i++)
	{
		r->roundPoints[i]=0;
	}
	r->numOfTricks=0;
	return r;
}

void RoundPlay(Game* _g,Round* _r)
{
	int i,first,loser,numOfRounds;
	int *heartBreak;
	heartBreak=0;
	Player** p=getPlayersArr(_g);
	DealCards(p);
	numOfRounds=getNumOfRounds(_g);

		first=SelectFirstPlayer(_g);
	for(i=0;i<13;i++)
	{
		first=playTrick(_g,_r,first,numOfRounds,heartBreak);
	}
	AddRoundPoints(_g,_r);
}

static void setRoundPoints(Round* _r,int _loser,int _losersPoints)
{
	_r->roundPoints[_loser]+=_losersPoints;
}

int getRoundPoints(Round* _r,int _i)
{
	return _r->roundPoints[_i];
}

static void printRoundPoints(Round* _r)
{
	int i;
	printf("Human points = %d\n",_r->roundPoints[0]);
	for(i=1;i<4;i++)
	{
		printf("Player %d points = %d\n",i,_r->roundPoints[i]);
	}
	printf("\n");
}

static int playTrick(Game* _g,Round *_r,int _first,int _numOfRounds,int *_heartBreak)
{
	int i,j,k,num,loser;
	int isFirstTrick;
	int isHumanPlayed=0;
	int computersPlayed=0;
	int fourCardsOfTrick[4];
	int indexOf4CardsOfTrick=0;
	int saveFirst=_first;
	int saveFirst2=_first;
	int losersPoints;
	if(_numOfRounds==0)
	{
		isFirstTrick=1;
	}
	for(i=0;i<4;i++)
	{
		fourCardsOfTrick[i]=-1;
	}
	Player** allPlayers;
	Player* specPlayer;
	Vector* cards;
	for(i=0;i<4;i++)
	{
		if(i==0)
		{
			printf("Human\n");
		}
		else
		{
			printf("Player %d\n",i);
		}
		for(j=0;j<13;j++)
		{
			allPlayers=getPlayersArr(_g);
			specPlayer=getSpecificPlayer(allPlayers,i);			
			cards=getVecOfCards(specPlayer);
			VectorGet(cards,j,&num);
		}
		VectorPrint(cards);
		printf("\n");
	}
	
	/*first trick*/
	while(computersPlayed+isHumanPlayed<4&&_first>=0&&_first<=3)
	{		
		specPlayer=getSpecificPlayer(allPlayers,_first);
		if(computersPlayed==3||(_first==0))
		{
			fourCardsOfTrick[indexOf4CardsOfTrick]=selectCardHuman(specPlayer,fourCardsOfTrick,_heartBreak);
			isHumanPlayed=1;
		}
		else
		{
			printf("Computer number %d is playing\n",_first);
			specPlayer=getSpecificPlayer(allPlayers,_first);			fourCardsOfTrick[indexOf4CardsOfTrick]=selectCardComputer(specPlayer,fourCardsOfTrick,_heartBreak);
			computersPlayed++;

		}
		indexOf4CardsOfTrick++;			
		if(computersPlayed+isHumanPlayed==4)
		{
			for(k=0;k<4;k++)
			{
				if(saveFirst2!=0)
				{
					printf("Player %d selected ",saveFirst2);
				}
				else
				{
					printf("Human selected ");
				}
				printOneElement(fourCardsOfTrick[k]);
				saveFirst2++;
				if(saveFirst2>3)
				{
					saveFirst2=0;
				}
				
			}
			loser=WhoLost(fourCardsOfTrick,saveFirst);
			printf("======================Loser of first trick is = %d=====================\n",loser);
			losersPoints=calculateLosersPoints(fourCardsOfTrick);
			printf("Loser points = %d\n\n",losersPoints);
			setRoundPoints(_r,loser,losersPoints);
			printRoundPoints(_r);
			_first=loser;
			computersPlayed=0;
			isHumanPlayed=0;
			return _first;
		}
		if(_first<3)
		{
			_first++;
		}
		else
		{
			_first=0;
		}	
	}
}
static int calculateLosersPoints(int* _fourCardsOfTrick)
{
	int i;
	int points=0;
	for(i=0;i<4;i++)
	{
		if(_fourCardsOfTrick[i]/13==0)
		{
			points++;
		}
		else if(_fourCardsOfTrick[i]==23)
		{
			points+=13;
		}
	}
	return points;
}

static int SelectFirstPlayer(Game* _g)
{
	int i,j,num;
	Player** allPlayers;
	Player* specPlayer;
	Vector* cards;
	for(i=0;i<4;i++)
	{
		for(j=0;j<13;j++)
		{
			
			allPlayers=getPlayersArr(_g);
			specPlayer=getSpecificPlayer(allPlayers,i);			
			cards=getVecOfCards(specPlayer);
			VectorGet(cards,j,&num);
			if(num==40)
			{
				printf("Player %d starts\n",i);
				return i;
			}
		}
	}
}

static int WhoLost(int* _fourCardsOfTrick,int _saveFirst)
{
	int i,loserIndex=_saveFirst;
	int res,max;
	res=_fourCardsOfTrick[0]/13;
	max=_fourCardsOfTrick[0];
	for(i=1;i<4;i++)
	{
		if(res==_fourCardsOfTrick[i]/13 && max<_fourCardsOfTrick[i])
		{
			max=_fourCardsOfTrick[i];
			loserIndex=(_saveFirst+i)%4;
		}		
	}
	return loserIndex;
}

