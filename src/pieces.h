#ifndef PIECES_H
#define PIECES_H
#define WHITE 1
#define BLACK -1

typedef struct {
  short Color;						//The piece's color
	char Position[3];				//The piece's position on the board
	char Type;							//The piece's type (pawn, rook, ...)
} Piece;

//Default setup for all pieces
void pieceDefaultSetup(Piece *piece, short col, char pos[3], char type);

void printPieceInfo(Piece *piece);

/* PIECE CREATION FUNCTIONS */
Piece Pawn(short color, char position[3]);
Piece Rook(short color, char position[3]);
Piece Knight(short color, char position[3]);
Piece Bishop(short color, char position[3]);
Piece Queen(short color, char position[3]);
Piece King(short color, char position[3]);

#endif
