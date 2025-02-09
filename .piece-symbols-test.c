#include "pieces.h"
#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(int argc, char *argv[])
{
  setlocale(LC_ALL, "en_US-UTF-8");
  Piece pawn = Pawn(BLACK, "b2");
  wprintf(L"%lc", pawn.symbol);
}
