/*
 * This file is an implementation of the pieces.h header
 */

#include "pieces.h"

void Piece_default_setup (Piece_t *piece, short color, char position[static 3]){
	piece -> p_color = color;
	piece -> p_first_move = true;
	piece -> p_captured = false;
	strcpy(piece -> p_position, position);
}

Piece_t Piece_Pawn(short color, char position [static 3]){
	Piece_t p = { .p_type = 'p'};
	Piece_default_setup(&p, color, position);
	return p;
}

Piece_t Piece_Rook(short color, char position [static 3]){
	Piece_t p = { .p_type = 'R'};
	Piece_default_setup(&p, color, position);
	return p;
}

Piece_t Piece_Knight(short color, char position [static 3]){
	Piece_t p = { .p_type = 'N'};
	Piece_default_setup(&p, color, position);
	return p;
}

Piece_t Piece_Bishop(short color, char position [static 3]){
	Piece_t p = { .p_type = 'B'};
	Piece_default_setup(&p, color, position);
	return p;
}

Piece_t Piece_Queen(short color, char position [static 3]){
	Piece_t p = { .p_type = 'Q'};
	Piece_default_setup(&p, color, position);
	return p;
}

Piece_t Piece_King(short color, char position [static 3]){
	Piece_t p = { .p_type = 'K'};
	Piece_default_setup(&p, color, position);
	return p;
}



void Piece_print_info(Piece_t *piece){
	printf("PIECE: 0x%x\n", piece); //Due to no ID, prints the memory location
	printf("\tp_color = %s\n", piece -> p_color == BLACK ? "BLACK" : "WHITE");
	printf("\tp_first_move = %s\n", piece -> p_first_move == true ? "TRUE" : "FALSE");
	printf("\tp_captured = %s\n", piece -> p_captured == true ? "TRUE" : "FALSE");
	printf("\tp_type = \'%c\'\n", piece -> p_type);
	printf("\tp_position = \"%s\"\n", piece -> p_position);
}



Movement_t Piece_Pawn_validate_movement(short delta_x, short delta_y, Color_t color, bool first_move){
	if(delta_y == 1 * color){

		//It will always attack when moving to the side
		if(delta_x == 1 || delta_x == -1){
			return CAN_ATTACK;
		}
			//It can move one square at a time (except first move)
		else if (delta_x == 0){
			return CAN_MOVE;
		}
	}

	//If its the first move, the pawn can move two spaces at once
	else if(delta_y == 2 * color && first_move == true){
		return CAN_MOVE;
	}
	return CANNOT_MOVE;
}

Movement_t Piece_Rook_validate_movement(short delta_x, short delta_y){
	//any change in x for no change in y an viceversa
	if(delta_x != 0 && delta_y == 0){
		return CAN_MOVE | CAN_ATTACK;
	}
	else if(delta_x == 0 && delta_y != 0){
		return CAN_MOVE | CAN_ATTACK;
	}

	//All other cases will end up here
	return CANNOT_MOVE;
}

Movement_t Piece_Knight_validate_movement(short delta_x, short delta_y){
	
	//If there is one square of difference, it will have to be either to blocks up
	//or two down
	if(
			(delta_x == 1 || delta_x == -1) &&
			(delta_y == 2 || delta_y == -2)
		)
			return CAN_MOVE | CAN_ATTACK;
	
	//If it is a 2 square difference, it can only be one up or down
	else if (
			(delta_x == 2 || delta_x == -2) &&
			(delta_y == 1 || delta_y == -1)
		)
			return CAN_MOVE | CAN_ATTACK;
	
	return CANNOT_MOVE;
}

Movement_t Piece_Bishop_validate_movement(short delta_x, short delta_y){
	//If the slope is either 1 or -1 (X shape) it will be a valid move
	if(SLOPE(delta_y, delta_x) == 1 || SLOPE(delta_y, delta_x) == -1){
		return CAN_MOVE | CAN_ATTACK;
	}
	return CANNOT_MOVE;
}

//The queen is a mix of both bishop and rook
Movement_t Piece_Queen_validate_movement(short delta_x, short delta_y){
	return 
		Piece_Bishop_validate_movement(delta_x, delta_y) |
		Piece_Rook_validate_movement(delta_x, delta_y);
}

Movement_t Piece_King_validate_movement(short delta_x, short delta_y){
	//if it is between 1 and -1 in both x an y
	if((delta_x >= -1 || delta_x <= 1) && (delta_y >= -1 || delta_y <= 1)){
		
		//If both values are 0 (no movement) it will not move (for obvious reasons)
		if(delta_x != 0 || delta_y != 0){
			return CAN_MOVE | CAN_ATTACK;
		}
	}
	return CANNOT_MOVE;
}

