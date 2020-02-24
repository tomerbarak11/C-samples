/**************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: Player header
* 						DATE: 18-07-2019 10:06:56
*******************************************************************************/

#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "Game.h"
#include "vector.h"

typedef struct Player Player;
typedef struct Game Game;

/**@Description:create player with an input name
 * @params _x :name
 * @returns: new player
 */
Player* PlayerCreate(char* _name);

/**@Description:sets data card in players hand
 * @params _x :specific player p and data
 * @returns:
 */
void setCard(Player* _p,int _data);

/**@Description:sorts hand of player
 * @params _x :specific player p
 * @returns:
 */
void cardsInsertionSort(Player* _p);

/**@Description:sets players hand
 * @params _x :specific player p
 * @returns:
 */
Player* setVectorOfCards(Player* _p);

/**@Description:gets players hand
 * @params _x :specific player p
 * @returns: vector hand
 */
Vector *getVecOfCards(Player* _p);

/**@Description:human/computers select card to put on board
 * @params _x :specPlayer = player, _fourCardsOfTrick = cards played in trick
 * @returns: 1 if ok and 0 if not 
 */
int selectCardHuman(Player* specPlayer, int* fourCardsOfTrick,int* _heartBreak);
int selectCardComputer(Player* specPlayer,int* fourCardsOfTrick,int* _heartBreak);
void printCardWithIndex(Player* specPlayer,int indexOfSelectedCard);

#endif          /* Player s*/
