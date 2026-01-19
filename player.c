#include "player.h"
#include <stdlib.h>
#include <ncurses.h>

struct Player *newP(void){
	struct Player p = (Player)malloc(sizeof(Player));;
	p.x = 0;
	p.y = 0;
	p.vx = 0;
	p.vy = 0;
	p.ax = 0;
	p.ay = 0;
	p.hp = 100;

	return &p;
}

void mvP(int y, int x, struct Player *p){
	p->x = x;
	p->y = y;
}

void printP(struct Player *p){
	mvaddch(p->y, p->x, 'P');
}
