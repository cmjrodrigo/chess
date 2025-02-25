#ifndef PIECES_H
#define PIECES_H
#define WHITE 1
#define BLACK -1

typedef struct {
  short Color;						//The piece's color
	char Position[2];				//The piece's position on the board
	char Type;							//The piece's type (pawn, rook, ...)
} Piece;

//Sets a piece's position to a new position
void pieceSetPosition(Piece *piece, char newPosition[2]);

//Default setup for all pieces
void pieceDefaultSetup(Piece *piece, short col, char pos[2], char type);

/* PIECE CREATION FUNCTIONS */
Piece Pawn(short color, char position[2]);
Piece Rook(short color, char position[2]);
Piece Knight(short color, char position[2]);
Piece Bishop(short color, char position[2]);
Piece Queen(short color, char position[2]);
Piece King(short color, char position[2]);

#endif
