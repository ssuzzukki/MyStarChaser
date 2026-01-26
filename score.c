#include "player.h"
#include "star.h"
#include <ncurses.h>

int touch(Player *p, Star *s){
	if(p->x == s->x && p->y == s->y){
		s->touch = 1;
		return 1;
	}
	return 0;
}

void pScore(int y, int x, Player *p){
	move(y, x);
	printw("SCORE:%d", p->score);
}
