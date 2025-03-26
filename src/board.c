#include "board.h"

void Board_initialize (Board_t *board){
	for(int y = 0; y < 8; y++){
		for(int x = 0; x < 8; x++){
			(*board)[x][y].s_in_check = false;
			(*board)[x][y].s_coordinate[0] = 'a' + x;
			(*board)[x][y].s_coordinate[1] = '1' + y;
			(*board)[x][y].s_coordinate[2] = '\0';
			(*board)[x][y].s_current_piece = NULL;
		}
	}
}

void Board_print(Board_t *board){
	char *space= "   ";
	//First X coordinate row
	printf(" ");
	for(int x = 0; x < 8; x++){
		printf("%s%c", space,  'a' + x);
	}
	printf("\n\n");

	for(int y = 7; y >= 0; y--){
		
		//First Y coordinate row
		printf("%c", '1' + y);
		for(int x = 0; x < 8; x++){
			if((*board)[x][y].s_current_piece == NULL)
				printf("%s%c", space, ((x+1) + y) % 2  == 0 ? '+' : 'x');
			else
				printf("%s%c", space, (*board)[x][y].s_current_piece -> p_type);
		}
		//Second Y coorinate row
		printf("%s%c\n\n", space, '1' + y);
	}

	//Second X coordinate row
	printf(" ");
	for(int x = 0; x < 8; x++){
		printf("%s%c", space, 'a' + x);
	}
	printf("\n");
}
