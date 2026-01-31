#ifndef STAR_H
#define STAR_H

typedef struct{
	int x, y, touch;
}Star;
extern Star *newS(int w, int seed);
extern void mvS(int y, int x, Star *s);
extern void printS(Star *s);
extern void incS(Star *s, int ground, int w, int seed);


#endif
