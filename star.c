#include "star.h"
#include <ncurses.h>

Star newS(void){
	Star s;
	s.x = 0;
	s.y = 0;
	return s;
}

void mcS(int y, int x, Star *s){
	s->y = y;
	s->x = x;
}

void printS(Star *s){
	mvaddch(s->y, s->x, '*');
}

void incS(Star *s, int ground){
	s->y++;
	if(s->y > ground) s->x = -1;
}
	
