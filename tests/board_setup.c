#include "../src/board.h"
#include "../src/pieces.h"

#include <stdio.h>

int main(void){
	Square *brd = board_init();
	board_print(&brd);
}
