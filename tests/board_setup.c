#include "../src/board.h"
#include "../src/pieces.h"

#include <stdio.h>
#include <stdlib.h>

int main(void){
	Square *brd = board_init();
	Piece pawn = Pawn(BLACK, "h5");
	printf("Position of pawn at start: %s.\n", pawn.Position);


	board_update(&brd, &pawn, "h5");
	board_print(&brd);

	board_update(&brd, &pawn, "b1");
	board_print(&brd);


	board_update(&brd, &pawn, "c8");
	board_print(&brd);
	printf("Position of pawn at end: %s.\n", pawn.Position);
}
