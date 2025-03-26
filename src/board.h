/*
 * This header file defines a Square as a struct with a pointer to a certain
 * color.
 */
#ifndef BOARD_H
#define BOARD_H


#include "pieces.h"

typedef struct{
	bool s_in_check;
	char s_coordinate[3];
	Piece_t *s_current_piece;
} Square_t;

typedef Square_t Board_t[8][8];

//Initializes the board
void Board_initialize(Board_t *board);

//Prints the board
void Board_print (Board_t *board);
#endif
