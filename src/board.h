#ifndef BOARD_H
#define BOARD_H

#include "pieces.h"

typedef struct{
	short Check;							//0 if current square is not in check (other pieces are attacking it)
	short Color;							//Current square's color
	char Coordinate[2];				//Coordinate in the board of each square
	Piece *Current;						//A pointer to the piece inside said square
} Square;

//Print square info
void printSquareInfo(Square *square);

//Initializes the board
Square *board_init(void);


//Function to print a board's colors
void board_print(Square **board);

//Sets a new piece in the board
int board_set_pieces (Square **board, Piece *piece, char position[3]);

//Updates a piece's position in the board
int board_update(Square **board, Piece *piece, char new_position[3]);

#endif
