/**************************************************************************
* 						PROGRAMMER: Tomer Barak
* 						FILE: game header
* 						DATE: 18-07-2019 09:41:57
*******************************************************************************/

#ifndef __GAME_H__
#define __GAME_H__
#include "Round.h"
#include "Player.h"

 typedef struct Player Player;
typedef struct Round Round;
typedef struct Game Game;
/**@Description: creates game
 * @params _x :
 * @returns: new game
 */
Game* GameCreate();

/**@Description: starts game
 * @params _x :
 * @returns: new game
 */
void GamePlay(Game *g);

/**@Description: get trick number
 * @params _x :game
 * @returns: number of trick
 */
int getNumOfTrick(Game* _g);

/**@Description: creates round
 * @params _x :game
 * @returns: new round
 */
Round* RoundCreate(Game* _g);

/**@Description: get round number
 * @params _x :game
 * @returns: number of round
 */
int getNumOfRounds(Game* _g);

/**@Description: get players array
 * @params _x :game
 * @returns: array of players
 */
Player** getPlayersArr(Game *_game);

/**@Description: get player in index i
 * @params _x :player array p and index i
 * @returns: returns player in index i
 */
Player* getSpecificPlayer(Player **p,int _i);

/**@Description: updades score of round
 * @params _x :game g and round r
 * @returns:
 */
void AddRoundPoints(Game* _g,Round* _r);
#endif          /* Game s*/
