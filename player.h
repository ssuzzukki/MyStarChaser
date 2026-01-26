#ifndef PLAYER_H
#define PLAYER_H

typedef struct{
	int x, y;
	double vx, vy;
	double ax, ay;
	int score;
}Player;
extern Player newP(void);
extern void mvP(int y, int x, Player *p);
extern void printP(Player *p);
extern void jump(Player *p, int *stand);
extern void incP(Player *p, int ground, int *stand);
extern void keyP(char key, Player *p, int *stand);


#endif
