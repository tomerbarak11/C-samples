/**************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: Deck header
* 						DATE: 18-07-2019 13:51:56
*******************************************************************************/
#ifndef __DECK_H__
#define __DECK_H__
#include "Game.h"
#include "vector.h"
#include "Player.h"

/**@Description:creates vector of cards
 * @params _x :game g
 * @returns: new vector
 */
Vector* CardsCreate(Game* _g);
/**@Description:deals 13 unique cards to each of 4 players
 * @params _x array of players p
 * @returns:
 */
void DealCards(Player** _p);
#endif
