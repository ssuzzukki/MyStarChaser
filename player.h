#ifdef PLAYER_H
#define PLAYER_H

typedef struct {
	int x, y;
	double vx, vy;
	double ax, ay;
	int hp;
} Player;
extern struct Player *newP(void);
extern void mvP(y, x, struct Player *p);
extern void printP(struct Player *p);


#endif
