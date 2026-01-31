#include "star.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

Star *newS(int w, int seed){
	Star *s;
	srand(seed);
	s->x = rand() % w;
	s->y = 0;
	s->touch = 0;
	return s;
}

void mcS(int y, int x, Star *s){
	s->y = y;
	s->x = x;
}

void printS(Star *s){
	mvaddch(s->y, s->x, '*');
}

void incS(Star *s, int ground, int w, int seed){
	s->y++;
	if(s->y > ground || s->touch == 1){
		s->y = 0;
		s->touch = 0;
		srand(seed);
		s->x = rand() % w;
	}
}
	
