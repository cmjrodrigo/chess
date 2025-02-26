#include "pieces.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void pieceDefaultSetup(Piece *piece, short col, char pos[3], char type){
	piece -> Color = col;
	strcpy(piece -> Position, pos);
	piece -> Type = type;
	return;
}

void printPieceInfo(Piece *piece){
	printf("TYPE: %c\n", piece -> Type);
	printf("POSITION: %s\n", piece -> Position);
	printf("COLOR: %s\n", piece -> Color == WHITE ? "White" : "Black");
}

//PIECE CREATION FUNCTIONS

Piece Pawn(short color, char position[3]){
	Piece pawn;
	pieceDefaultSetup(&pawn, color, position, 'p');
	return pawn;
}

Piece Rook(short color, char position[3]){
	Piece rook;
	pieceDefaultSetup(&rook, color, position, 'R');
	return rook;
}

Piece Knight(short color, char position[3]){
	Piece knight;
	pieceDefaultSetup(&knight, color, position, 'N');
	return knight;
}

Piece Bishop(short color, char position[3]){
	Piece bishop;
	pieceDefaultSetup(&bishop, color, position, 'B');
	return bishop;
}

Piece Queen(short color, char position[3]){
	Piece queen;
	pieceDefaultSetup(&queen, color, position, 'Q');
	return queen;
}

Piece King(short color, char position[3]){
	Piece king;
	pieceDefaultSetup(&king, color, position, 'K');
	return king;
}
