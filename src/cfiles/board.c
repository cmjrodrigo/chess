#include "../headers/board.h"
#include <stdio.h>
#include <wchar.h>
#include <stdlib.h>
#include <string.h>

Square** InitializeBoard(void)
{
  Square **board = malloc(sizeof(Square *) * 8);
  for(int y = 0; y < 8; y++)
  {
    board[y] = malloc(sizeof(Square) * 8);
    for(int x = 0; x < 8; x++)
    {
      board[y][x].current = calloc(1, sizeof(Piece));
      sprintf(board[y][x].coor, "%c%c", 'a' + x, '8' - y);
    }
  }
  return board;
}
