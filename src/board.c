#include "board.h"
#include "pieces.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BOARD(x, y) board[(y * 8) + x] 					//Similar to c++'s "this" for structs
#define PBOARD(x, y) (*board)[(y * 8) + x]			//Like the one above but for pointers

void printSquareInfo(Square *square){
	printf("COORDINATE: %s\n", square -> Coordinate);
	printf("COLOR: %s\n", square -> Color == WHITE ? "White" : "Black");
	printf("CHECK: %d\n", square -> Check);
	printf("CURRENT: %c\n", square -> Current == NULL ? '0' : square -> Current -> Type);
}

Square *board_init(void){
	
	//Memory allocation for all squares
	Square *board = calloc(64, sizeof(Square));

	for(int y = 0; y < 8; y++){
		for(int x = 0; x < 8; x++){
			BOARD(x, y).Check = 0;
			BOARD(x, y).Coordinate[0] = 'a' + x;
			BOARD(x, y).Coordinate[1] = '1' + y;
			BOARD(x, y).Current = NULL;

			if((x + y + 2) % 2 == 0){
				BOARD(x, y).Color = BLACK;
			}
			else{
				BOARD(x, y).Color = WHITE;
			}
		}
	}

	return board;
}

void board_print(Square **board){
	for(int y = 7; y >= 0; y--){
		for(int x = 0; x < 8; x++){

			if(x == 0){
				printf("%c\t", PBOARD(x, y).Coordinate[1]); 
			}

			//Prints each color if no piece is detected inside a square
			if(PBOARD(x, y).Current == NULL){
				printf("%c   ", PBOARD(x, y).Color == WHITE ? '1' : '0');
			}

			//Prints pieces by their type
			else{
				printf("%c   ", PBOARD(x, y).Current -> Type);
			}
		}
		printf("\n\n");
	}

	//Prints the letter coordinates at the bottom
	printf("\n");
	printf(" \t");
	for(int i = 'A'; i <= 'H'; i++){
		printf("%c   ", i);
	}
	printf("\n\n");
	printf("\n\n");
}

int board_update(Square **board, Piece *piece, char new_position[3]){

	short new_x = new_position[0] - 'a';
	short new_y = new_position[1] - '1';

	short past_x = piece -> Position[0] - 'a';
	short past_y = piece -> Position[1] - '1';

	PBOARD(past_x, past_y).Current = NULL;
	PBOARD(new_x, new_y).Current = piece;

	piece -> Position[0] = new_position[0];
	piece -> Position[1] = new_position[1];

#ifdef DEBUG
	printf("New piece position: %s.\n", piece -> Position);
	printf("Piece info: \n");
	printPieceInfo(piece);
	puts("");
	printf("Square info: \n");
	printSquareInfo(&(PBOARD(new_x, new_y)));
	puts("");
	puts("");
#endif

	return 1;
}

