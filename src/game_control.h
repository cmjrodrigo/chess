#ifndef GAME_CONTROL_H
#define GAME_CONTROL_H

#include "pieces.h"
#include "board.h"

typedef struct{
	Square *Board;
	Piece WhitePieces[16];
	Piece BlackPieces[16];
} Game;

//Initialices a game instance
void game_init(Game *game);

#endif
