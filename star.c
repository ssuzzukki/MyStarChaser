#include "star.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>


Star *initS(Star *s, int w, int seed){
	srand(seed);
	s->x = rand() % w;
	s->y = -(s->x % 10);
	s->touch = 0;
	s->seed = seed;
	return s;
}

void mcS(int y, int x, Star *s){
	s->y = y;
	s->x = x;
}

void printS(Star *s){
	mvaddch(s->y, s->x, '*');
}


void moveS(Star *s, int ground, int w, int sec, int turn){
	s->y++;

	if(s->y > ground || s->touch == 1){
		s->touch = 0;
		s->x = ((s->x + s->seed) * sec * turn) % w;
		s->y = -(s->x % 10);
	}
}
	
