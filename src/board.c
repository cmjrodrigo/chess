#include "board.h"
#include "pieces.h"

#include <stdlib.h>
#include <stdio.h>

#define BOARD board[(y * 8) + x] 					//Similar to c++'s "this" for structs
#define PBOARD (*board)[(y * 8) + x]			//Like the one above but for pointers

Square *board_init(void){
	
	//Memory allocation for all squares
	Square *board = calloc(64, sizeof(Square));

	for(int y = 0; y < 8; y++){
		for(int x = 0; x < 8; x++){
			BOARD.Check = 0;
			BOARD.Coordinate[0] = 'a' + x;
			BOARD.Coordinate[1] = '1' + y;
			BOARD.Current = NULL;

			if((x + y + 2) % 2 == 0){
				BOARD.Color = BLACK;
			}
			else{
				BOARD.Color = WHITE;
			}
		}
	}

	return board;
}

void board_print(Square **board){
	for(int y = 7; y >= 0; y--){
		for(int x = 0; x < 8; x++){
			if(PBOARD.Color == BLACK){
				printf("0  ");
			}
			else{
				printf("1  ");
			}
		}
		printf("\n\n");
	}
}

