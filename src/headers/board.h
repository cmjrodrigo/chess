#ifndef BOARD_H
#define BOARD_H

#include "pieces.h"

typedef struct
{
  Piece *current;
  char coor[3];
} Square;

Square **InitializeBoard(void);


#endif
