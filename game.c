#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include "timer.h"
#include "player.h"
#include "star.h"
#include "score.h"

int Game(sec){
	int h, w, key;
	time_t start = time(NULL);
	int d;
	int i;
	int fin = 0;
	int seed = 0;
	struct timespec t = {0, 100000000}; //0.1s
	Player p = newP();

	timeout(0);
	getmaxyx(stdscr, h, w);

	Star s1 = newS(w, seed+0);
	Star s2 = newS(w, seed+1);
	Star s3 = newS(w, seed+2);
	Star s4 = newS(w, seed+3);
	Star s5 = newS(w, seed+4);
	Star s6 = newS(w, seed+5);
	erase();
	int ground = h-6;
	mvP(ground-1, w/2, &p);

	while(1){
		incP(&p, ground);
		incS(&s1, ground, w, seed+0);
		incS(&s2, ground, w, seed+1);
		incS(&s3, ground, w, seed+2);
		incS(&s4, ground, w, seed+3);
		incS(&s5, ground, w, seed+4);
		incS(&s6, ground, w, seed+5);
		touch(&p, &s1);
		touch(&p, &s2);
		touch(&p, &s3);
		touch(&p, &s4);
		touch(&p, &s5);
		touch(&p, &s6);
		erase();

		pScore(h-1, w-20, &p);
		for(i=0;i<w;i++){
			mvaddch(ground, i, '-');
		}

		printS(&s1);
		printS(&s2);
		printS(&s3);
		printS(&s4);
		printS(&s5);
		printS(&s6);
		printP(&p);

		d = diffsec(start);
		fin = Timer(h-1, w-6, sec - d);
		if(fin == 1) break;
		key = getch();
		mvaddch(h-1, 0, key);
		if(key == 'q') break;
		keyP(key, &p);
		
		nanosleep(&t, NULL);
		
		seed++;


	}
	return p.score;
}
