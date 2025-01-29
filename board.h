#ifndef BOARD_H
#define BOARD_H
#define B_H 2
typedef struct{
	unsigned short coordinate[2];
	char piece[3];
	char color;
}square;

void b_init();
void b_print();

#endif
