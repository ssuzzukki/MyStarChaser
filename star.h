#ifndef STAR_H
#define STAR_H

typedef struct{
	int x, y, touch, seed;
}Star;
extern Star *initS(Star *s, int w, int seed);
extern void mvS(int y, int x, Star *s);
extern void printS(Star *s);
extern void moveS(Star *s, int ground, int w, int sec, int turn);


#endif
