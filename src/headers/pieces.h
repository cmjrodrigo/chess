#ifndef PIECES_H
#define PIECES_H

#include <wchar.h>

#define BLACK -1
#define WHITE 1
#define BETWEEN(n,min,max) ((n) >= (min)) && ((n) <= (max)) ? 1 : 0

typedef struct
{
  unsigned short max;       //If max == 1 can be any x or y value from 1 to x/yVal. If not, the movement will be exactly as xVal and yVal
  short attk;               //0 for move only, 1 for attack only, -1 for both
  short int xVal;
  short int yVal;
} Movement;

typedef struct
{
  unsigned short color;      //Color of the piece to detemrine movement
  char pos[3];          //Current position of the piece
  wchar_t symbol;            //Shown symbol of the piece
  unsigned short movlen;
  Movement movset[8];      //Array of possible moves per piece
} Piece;


//Checks if the movement given is one that the piece can do.
//Returns an index if valid and -1 if not
int IsMovementValid(char *destination, Piece *piece);

Piece Pawn(unsigned short c, char p[3]);

Piece Knight(unsigned short c, char p[3]);

#endif
