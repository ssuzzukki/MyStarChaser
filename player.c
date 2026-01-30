#include "player.h"
#include <stdlib.h>
#include <ncurses.h>

Player newP(void){
	Player p;
	p.x = 0;
	p.y = 0;
	p.vx = 0;
	p.vy = 0;
	p.ax = 0;
	p.ay = 1;
	p.score = 0;

	return p;
}

void mvP(int y, int x, Player *p){
	p->x = x;
	p->y = y;
}

void printP(Player *p){
	mvaddch(p->y, p->x, 'P');
}

void jump(Player *p, int *stand){
	if(*stand == 1) p->vy = -4;
	*stand = 0;
};

void incP(Player *p, int ground, int *stand){
	p->x = p->x + p->vx;
	p->vx = p->vx + p->ax;
	p->y = p->y + p->vy;
	p->vy = p->vy + p->ay;
	if(p->y >= ground){
		p->y = ground - 1;
		p->vy = 0;
		*stand = 1;
	}
}

void keyP(char key, Player *p, int *stand){
	if(key == 'a') p->vx = -1;
	if(key == 'd') p->vx = 1;
	if(key == 's') p->vx = 0;
	if(*stand == 1){
		if(key == 'w'){
			p->vy = -5;
			*stand = 0;
		}
		if(key == ' '){
			p->vy = -3;
			*stand = 0;
		}
	}
}
