/*************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: Game code
* 						DATE: 18-07-2019 09:41:57
*******************************************************************************/

#include <stdio.h> 		/* printf                                       */
#include <stdlib.h> 	    /* EXIT_SUCCESS, EXIT_FAILURE, malloc realloc */
#include <string.h>        /* strcat, strlen, strcpy                           */
#include "Game.h"
#include "Player.h"
#include "vector.h"
#include "Round.h"
struct Game{
	int numOfRounds;
	int numOfPlayers;
	Player* players[4];
	int gamePoints[4];
};

/**@Description: check if game is over returns 1 if yes and 0 if not
 * @params _x :array of points
 * @returns: returns 1 if game over yes and 0 if not
 */
static int IsGameOver(int *_points);

/**@Description: check if game is over if one of the players reached 100 points
 * @params _x :array of points
 * @returns: returns index of winner
 */
static int findWinner(int *_points);
Game* GameCreate()
{
	Game* g;
	Player *p;
	int i;
	char name[20];
	g=(Game*)malloc(1*sizeof(Game));
	if(NULL==g)
	{
		printf("Allocation fail\n");
		return NULL;
	}
	g->numOfRounds=0;
	g->numOfPlayers=4;
	printf("Enter players name\n");
	strcpy(name,"Tomer");
	g->players[0]=PlayerCreate(name);
	g->players[1]=PlayerCreate("Player 2");
	g->players[2]=PlayerCreate("Player 3");
	g->players[3]=PlayerCreate("Player 4");
	for(i=0;i<4;i++)
	{
		g->players[i]=setVectorOfCards(g->players[i]);
	}
	return g;
}

static int IsGameOver(int *_points)
{
	int i,winnerIndex=-1;
	for(i=0;i<4;i++)
	{
		if(_points[i]>=100)
		{
			winnerIndex=findWinner(_points);
		}
	}
	return -1;
}

static int findWinner(int *_points)
{
	int i,min,minIndex=0,flagFinish=0;
	min=_points[0];
	for(i=1;i<4;i++)
	{
		if(_points[i]<min)
		{
			min=i;
			minIndex=i;
		}
	}
	if(minIndex==0)
	{
		printf("Congratulations!!!\nYou are the winner\n");
		flagFinish=0;
	}
	else
	{
		printf("Winner is player %d\n",min);
		flagFinish=0;
	}
	if(flagFinish==0)
	{
		exit(1);
	}
	return minIndex;
}

void GamePlay(Game *_g)
{
	int flagOver=0;
	int numOfRound=0;
	Round* r=RoundCreate(_g);
	_g->numOfRounds=0;
	while(flagOver==0)
	{
		if(IsGameOver(_g->gamePoints)!=-1)
		{
			exit(1);
		}
		printf("!!!!!!!!!!!!!!!!!!Round %d starts now!!!!!!!!!!!!!!!!!\n",numOfRound);
		numOfRound++;
		printf("Current round is %d\n\n",_g->numOfRounds);
		RoundPlay(_g,r);
		_g->numOfRounds++;
	}
}

void AddRoundPoints(Game* _g,Round* _r)
{
	int i,roundPointsOfPlayeri;

	for(i=0;i<4;i++)
	{
		roundPointsOfPlayeri=getRoundPoints(_r,i);
		_g->gamePoints[i]=roundPointsOfPlayeri;
	}
}

int getNumOfTrick(Game* _g)
{
	return _g->numOfRounds;
}

int getNumOfRounds(Game* _g)
{
	return _g->numOfRounds;
}

Player** getPlayersArr(Game *_game)
{
	return _game->players;
}

Player* getSpecificPlayer(Player **_p,int _i)
{
	return _p[_i];
}
