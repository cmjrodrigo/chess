#include "../src/game_control.h"
#include "../src/board.h"
#include "../src/pieces.h"

int main(int argc, char *argv[]){
	Game game;
	game_init(&game);
	board_print(&(game.Board));
}
