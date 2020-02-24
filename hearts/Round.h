/**************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: Round header
* 						DATE: 18-07-2019 10:05:54
*******************************************************************************/

#ifndef __ROUND_H__
#define __ROUND_H__
#include "Game.h"
/**@Description:
 * Average time complexity :
 * Worst : 
 * @params _x :
 * @returns:
 */
typedef struct Game Game;
typedef struct Round Round;

/**@Description: creates round
 * @params _x :game
 * @returns: new round
 */
Round* RoundCreate(Game* _g);

/**@Description: starts round
 * @params _x :game g and round r
 * @returns:
 */
void RoundPlay(Game* _g,Round* _r);

/**@Description: counts score of round
 * @params _x :game g and round r
 * @returns:
 */
void CountRoundPoints(Game* _g,Round* _roundPoints);

/**@Description: gets round points of index i
 * @params _x :game g and int i
 * @returns: points of index i
 */
int getRoundPoints(Round* _r,int _i);
#endif          /* Round s*/




