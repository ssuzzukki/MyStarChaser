#include <ncurses.h>
#include <time.h>
#include "timer.h"
#include "player.h"
#include "star.h"
#include "score.h"

void Game(void){
	int h, w, key;
	int sec = 120;
	time_t start = time(NULL);
	int d;
	int i;
	int fin = 0;
	int stand = 1;
	int seed = 0;
	struct timespec t = {0, 100000000}; //0.1s
	Player p = newP();

	timeout(0);
	getmaxyx(stdscr, h, w);

	Star s1 = newS(w, seed+0);
	Star s2 = newS(w, seed+1);
	Star s3 = newS(w, seed+2);
	erase();
	int ground = h-6;
	mvP(ground-1, w/2, &p);

	while(1){
		incP(&p, ground, &stand);
		incS(&s1, ground, w, seed+0);
		incS(&s2, ground, w, seed+1);
		incS(&s3, ground, w, seed+2);
		if(touch(&p, &s1) == 1) p.score = p.score + 1;
		if(touch(&p, &s2) == 1) p.score = p.score + 1;
		if(touch(&p, &s3) == 1) p.score = p.score + 1;
		erase();

		pScore(h-1, w-20, &p);
		for(i=0;i<w;i++){
			mvaddch(ground, i, '-');
		}
		printS(&s1);
		printS(&s2);
		printS(&s3);
		printP(&p);

		d = diffsec(start);
		fin = Timer(h-1, w-6, sec - d);
		if(fin == 1) break;
		key = getch();
		mvaddch(h-1, 0, key);
		if(key == 'q') break;
		keyP(key, &p, &stand);
		
		nanosleep(&t, NULL);
		
		seed++;


	}


}
