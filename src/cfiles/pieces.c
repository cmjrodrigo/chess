#include "../headers/pieces.h"
#include <wchar.h>
#include <string.h>
#include <stdio.h>

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
