#ifndef PIECES_H
#define PIECES_H

#include <wchar.h>
#include <string.h>
#include <stdio.h>

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
int IsMovementValid(char *destination, Piece *piece)
{
  int valid = -1;
  char *des2 = destination;
  char *position = piece -> pos;

  //Calculation of X an Y offset
  int x_offset = *(destination ++) - *(position++);
  int y_offset = *destination - *position;
  
  //Reads the movset array and compares it to the possible X and Y values
  for(int i = 0; i < piece -> movlen; i++)
  {
    if(
        (piece -> movset[i].xVal == x_offset) && 
        (piece -> movset[i].yVal == y_offset) && 
        BETWEEN(des2[0], 'a', 'h') &&
        BETWEEN(des2[1], '1', '8')
      )
    {
      valid = i;
      break;
    }
  }

  return valid;
}



Piece Pawn(unsigned short c, char p[3])
{
  Piece pawn = {
    c,
    "  ",
    (wchar_t)(c == -1 ? L'\u2659' : L'\u265F'),
    3,
    {
    //max, attk, x, y
      {0, 1, 1, 1 * (int) c},
      {0, 1, -1, 1 * (int) c},
      {0, 0, 0, 1 * (int) c}
    }
  };
  
  strcpy(pawn.pos, p);
  return pawn;
}

Piece Knight(unsigned short c, char p[3])
{
  Piece knight ={
    c,
    "  ",
    L'N',
    8,
    {
    // max, attk, x, y
      {0, -1, 2, 1},
      {0, -1, 2, -1},
      {0, -1, -2, 1},
      {0, -1, -2, -1},
      {0, -1, 1, 2},
      {0, -1, -1, 2},
      {0, -1, 1, -2},
      {0, -1, -1, -2}
    }
  };

  strcpy(knight.pos, p);
  return knight;
}

#endif
