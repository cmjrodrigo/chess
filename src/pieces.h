#ifndef PIECES_H
#define PIECES_H
/*
 * This header defines the piece structure, as well as some basic functions
 * for piece management
 */
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

typedef enum{
	WHITE = 1,
	BLACK = -1
} Color_t;

typedef enum{
	CANNOT_MOVE = 0,
	CAN_MOVE = 1 << 0,
	CAN_ATTACK = 1 << 1
} Movement_t;

typedef struct{
	Color_t p_color;
	bool p_first_move;
	bool p_captured;
	char p_type;
	char p_position[3];
} Piece_t;

#define SLOPE(dy, dx) (double)(dy)/(double)(dx) //used for some movement validation functions


/*
 * The following functions create new Piece_t based on a given color and position
 */

void Piece_default_setup (Piece_t *piece, short color, char position [static 3]);
Piece_t Piece_Pawn(short color, char position [static 3]);
Piece_t Piece_Rook(short color, char position [static 3]);
Piece_t Piece_Knight(short color, char position [static 3]);
Piece_t Piece_Bishop(short color, char position [static 3]);
Piece_t Piece_Queen(short color, char position [static 3]);
Piece_t Piece_King(short color, char position [static 3]);

void Piece_print_info(Piece_t *piece);


/*
 * The next functions return CAN_MOVE, CAN_ATTACK, or CANNOT_MOVE
 * depending on the position and destination of the given piece
 * delta_x and delta_y will be  the change from the piece's current
 * position to the desired position
 */

Movement_t Piece_Pawn_validate_movement(short delta_x, short delta_y, Color_t color, bool first_move);
Movement_t Piece_Rook_validate_movement(short delta_x, short delta_y);
Movement_t Piece_Knight_validate_movement(short delta_x, short delta_y);
Movement_t Piece_Bishop_validate_movement(short delta_x, short delta_y);
Movement_t Piece_Queen_validate_movement(short delta_x, short delta_y);
Movement_t Piece_King_validate_movement(short delta_x, short delta_y);

#endif
