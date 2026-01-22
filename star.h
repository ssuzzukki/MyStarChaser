#ifndef STAR_H
#define STAR_H

typedef struct{
	int x, y;
}Star;
extern Star newS(void);
extern void mvS(int y, int x, Star *s);
extern void printS(Star *s);
extern void incS(Star *s, int ground);


#endif
