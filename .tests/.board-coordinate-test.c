#include "pieces.h"
#include "board.h"
#include <stdio.h>
int main(int argc, char *argv[])
{
  Square **Board = InitializeBoard();

  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      printf("%s  ", Board[i][j].coor);
    }
    printf("\n\n");
  }
}
