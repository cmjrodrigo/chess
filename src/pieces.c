#include "pieces.h"
#include <stdlib.h>
#include <string.h>

void pieceSetPosition(Piece *piece, char newPosition[2]){
	piece -> Position[0] = newPosition[0];
	piece -> Position[1] = newPosition[1];
	return;
}

void pieceDefaultSetup(Piece *piece, short col, char pos[2], char type){
	piece -> Color = col;
	pieceSetPosition(piece, pos);
	piece -> Type = type;
	return;
}



//PIECE CREATION FUNCTIONS

Piece Pawn(short color, char position[2]){
	Piece pawn;
	pieceDefaultSetup(&pawn, color, position, 'p');
	return pawn;
}

Piece Rook(short color, char position[2]){
	Piece rook;
	pieceDefaultSetup(&rook, color, position, 'R');
	return rook;
}

Piece Knight(short color, char position[2]){
	Piece knight;
	pieceDefaultSetup(&knight, color, position, 'K');
	return knight;
}

Piece Bishop(short color, char position[2]){
	Piece bishop;
	pieceDefaultSetup(&bishop, color, position, 'B');
	return bishop;
}

Piece Queen(short color, char position[2]){
	Piece queen;
	pieceDefaultSetup(&queen, color, position, 'Q');
	return queen;
}

Piece King(short color, char position[2]){
	Piece king;
	pieceDefaultSetup(&king, color, position, 'K');
	return king;
}
