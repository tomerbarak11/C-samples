#include <stdio.h>
#include "Game.h"
#include "Round.h"
int main()
{
	Game* game=NULL;
	Round* round;
	printf("Press y if you want to create the game\n");
	game=GameCreate();
	printf("Press y if you want to start the game\n");
	GamePlay(game);
}
