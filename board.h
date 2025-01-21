#ifndef BOARD_H
#define BOARD_H

typedef struct{
	unsigned short coordinate[2];
	char piece[3];
	char color;
}square;

typedef square *board[8];


#endif
