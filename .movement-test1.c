#include "pieces.h"
#include <string.h>
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

void InteractiveCheckMovementValidity()
{

  //Get piece info
  printf("Please enter a piece(p, N): ");
  char p;
  scanf("%c", &p);
  getchar();

  printf("Please enter a coordinate: ");
  char coor[3];
  scanf("%s", coor);
  getchar();

  printf("Please enter a destination: ");
  char dest[3];
  scanf("%s", dest);
  getchar();

  printf("Choose a color (Black = -1, White = 1): ");
  int color;
  scanf("%d", &color);
  getchar();

  char movtype[20];
  int validity;

  Piece piece;
  //Process piece info and set print message parameters
  if(p == 'p')
  {
    piece = Pawn(color, coor);
    if((validity = IsMovementValid(dest, &piece)) > -1)
    {
      if(piece.movset[validity].attk == 1)
      {
        strcpy(movtype, "attack");
      }
      else if(piece.movset[validity].attk == 0)
      {
        strcpy(movtype, "move");
      }
      else
      {
        strcpy(movtype, "attack/move");
      }
    }
    else
    {
      strcpy(movtype, "attack/move");
    }
  }
  else if( p == 'N')
  {
    
    piece = Knight(color, coor);
    if((validity = IsMovementValid(dest, &piece)) > -1)
    {
      if(piece.movset[validity].attk == 1)
      {
        strcpy(movtype, "attack");
      }
      else if(piece.movset[validity].attk == 0)
      {
        strcpy(movtype, "move");
      }
      else
      {
        strcpy(movtype, "attack/move");
      }
    }
    else
    {
      strcpy(movtype, "attack/move");
    }
  }

  printf("%s %s %s to %s\n", piece.pos, validity >= 0 ? "can" : "can't", movtype, dest);

}

int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "");

  for(;;)
  {
    InteractiveCheckMovementValidity();
  }

}
