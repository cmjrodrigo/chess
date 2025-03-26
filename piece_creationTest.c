#include <stdio.h>

#include "src/pieces.h"
#include "src/board.h"

int main(int argc, char *argv[]){
	Piece_t newpiece = Piece_Pawn(BLACK, "e3");

	Board_t board;
	Board_initialize(&board);
	puts("Before piece");
	Board_print(&board);

	puts("");
	puts("After piece");
	board[4][4].s_current_piece = &newpiece;
	Board_print(&board);
}
