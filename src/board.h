#ifndef BOARD_H
#define BOARD_H

#include "pieces.h"

typedef struct{
	short Check;							//0 if current square is not in check (other pieces are attacking it)
	short Color;							//Current square's color
	char Coordinate[2];				//Coordinate in the board of each square
	Piece *Current;						//A pointer to the piece inside said square
} Square;


//Initializes the board
Square *board_init(void);

//Function to print a board's colors
void board_print(Square **board);

#endif
