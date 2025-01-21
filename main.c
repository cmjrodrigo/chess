#include <stdio.h>

int main(void){

	char BOARD[8][8];
	for(int i = 0, c = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			if( (j + i + 1) % 2 == 0){
				BOARD[i][j] = '#';
			}
			else{
				BOARD[i][j] = ' ';
			}
		}
	}

	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			printf("%3c", BOARD[i][j]);
		}
		printf("\n");
	}
}
