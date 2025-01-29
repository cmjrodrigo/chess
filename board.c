#include <stdio.h>
#include "board.h"

square board[8][8];

void b_init(){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      if((i + j + 2) % 2){
        board[i][j].color = ' ';
      }
      else{
        board[i][j].color = '#';
      }
    }
  }
}

void b_print(){
  //prints the squares
  for(int i = 0; i < 8; i++){
    printf("%d", 8 - i);
    for(int j = 0; j < 8; j++){
      printf("%6c", board[i][j].color);
    }
    for(int k = 0; k < B_H; k++){
      printf("\n");
    }
  }
  //prints bottom row of coordinates
  printf(" ");
  for(int i = 0; i < 8; i ++){
    printf("%6c", 'A' + i);
  }
  printf("\n");
 }
