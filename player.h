#ifndef PLAYER_H
#define PLAYER_H

typedef struct{
	int x, y;
	double vx, vy;
	double ax, ay;
	int hp;
}Player;
extern Player newP(void);
extern void mvP(int y, int x, Player *p);
extern void printP(Player *p);
extern void jump(Player *p);
extern void incP(Player *p);


#endif
