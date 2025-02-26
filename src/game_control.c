#include "game_control.h"
#include "board.h"
#include "pieces.h"

#include <stdio.h>

void game_init (Game *game) {
	game -> Board = board_init();

	//Setting pawns
	for(int x = 0; x < 16; x++){
		char wpos[3];
		char bpos[3];

		if(x < 8){
			sprintf(wpos, "%c2", 'a' + x);
			sprintf(bpos, "%c7", 'a' + x);

			game -> WhitePieces[x] = Pawn(WHITE, wpos);
			game -> BlackPieces[x] = Pawn(BLACK, bpos);
		}
		else{

			//Rooks
			if(x == 8 || x == 15){
				sprintf(wpos, "%c1", 'a' + x - 8);
				sprintf(bpos, "%c8", 'a' + x - 8);

				game -> WhitePieces[x] = Rook(WHITE, wpos);
				game -> BlackPieces[x] = Rook(BLACK, bpos);
			}

			//Knights
			else if(x == 9 || x == 14){
				sprintf(wpos, "%c1", 'a' + x - 8);
				sprintf(bpos, "%c8", 'a' + x - 8);

				game -> WhitePieces[x] = Knight(WHITE, wpos);
				game -> BlackPieces[x] = Knight(BLACK, bpos);
			}

			//Bishops
			else if(x == 10 || x == 13){
				sprintf(wpos, "%c1", 'a' + x - 8);
				sprintf(bpos, "%c8", 'a' + x - 8);

				game -> WhitePieces[x] = Bishop(WHITE, wpos);
				game -> BlackPieces[x] = Bishop(BLACK, bpos);
			}

			//Queen
			else if(x == 11){
				sprintf(wpos, "%c1", 'a' + x - 8);
				sprintf(bpos, "%c8", 'a' + x - 8);

				game -> WhitePieces[x] = Queen(WHITE, wpos);
				game -> BlackPieces[x] = Queen(BLACK, bpos);
			}

			//King
			else if(x == 12){
				sprintf(wpos, "%c1", 'a' + x - 8);
				sprintf(bpos, "%c8", 'a' + x - 8);

				game -> WhitePieces[x] = King(WHITE, wpos);
				game -> BlackPieces[x] = King(BLACK, bpos);
			}
		}

		//Updates the board everytime it creates a new piece
		board_update(&(game -> Board), &(game -> WhitePieces[x]), wpos);
		board_update(&(game -> Board), &(game -> BlackPieces[x]), bpos);
	}

}
