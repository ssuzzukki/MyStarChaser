#include "player.h"
#include "star.h"
#include <ncurses.h>

void touch(Player *p, Star *s){
	if(p->x == s->x && p->y == s->y){
		s->touch = 1;
		p->score = p->score + 1 + (1 - p->stand) * 10;
	}
}

void pScore(int y, int x, Player *p){
	move(y, x);
	printw("SCORE:%d", p->score);
}
