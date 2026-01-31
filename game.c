#include <ncurses.h>
#include <time.h>
#include "timer.h"
#include "player.h"
#include "star.h"
#include "score.h"

#include <stdlib.h>
#include <unistd.h>

int Game(int sec){
	
	erase();
	
	int h, w, key;
	time_t start = time(NULL);
	int d;
	int i;
	int fin = 0;
	int seed = 0;
//	struct timespec t = {0, 100000000 * 10}; //0.1s
	Player p = newP();
	int snum = 6;
	//Star *stars[20];
	Star **stars = calloc(10, sizeof(Star *));

	timeout(0);
	getmaxyx(stdscr, h, w);

/*
	for(i=0;i<snum;i++){
		stars[i] = newS(w, seed+i);
	}
*/
	stars[1] = newS(w, seed+1);
	stars[2] = newS(w, seed+2);
	stars[3] = newS(w, seed+3);
	stars[4] = newS(w, seed+4);
	stars[5] = newS(w, seed+5);
	stars[6] = newS(w, seed+6);

	erase();
	int ground = h-6;
	mvP(ground-1, w/2, &p);

	while(1){
		incP(&p, ground);
/*
		for(i=0;i<snum;i++){
			incS(stars[i], ground, w, seed+i);
		}
*/
		incS(stars[1], ground, w, seed+1);
		//incS(stars[2], ground, w, seed+2);
		//incS(stars[3], ground, w, seed+3);
		//incS(stars[4], ground, w, seed+4);
		//incS(stars[5], ground, w, seed+5);
		//incS(stars[6], ground, w, seed+6);

		
/*
		for(i=0;i<snum;i++){
			touch(&p, stars[i]);
		}
*/
		touch(&p, stars[1]);
		touch(&p, stars[2]);
		touch(&p, stars[3]);
		touch(&p, stars[4]);
		touch(&p, stars[5]);
		touch(&p, stars[6]);

		erase();

		pScore(h-1, w-20, &p);
		for(i=0;i<w;i++){
			mvaddch(ground, i, '-');
		}

/*
		for(i=0;i<snum;i++){
			printS(stars[i]);
		}
*/
		printS(stars[1]);
		printS(stars[2]);
		printS(stars[3]);
		printS(stars[4]);
		printS(stars[5]);
		printS(stars[6]);


		move(0,0);
		printw("%d, %d", stars[1]->x, stars[1]->y);
		move(1,0);
		printw("%d, %d", stars[2]->x, stars[1]->y);
		move(2,0);
		printw("%d, %d", stars[3]->x, stars[1]->y);
		
		printP(&p);

		d = diffsec(start);
		fin = Timer(h-1, w-6, sec - d);
		if(fin == 1) break;
		key = getch();
		mvaddch(h-1, 0, key);
		if(key == 'q') break;
		keyP(key, &p);
		
//		nanosleep(&t, NULL);
		usleep(100000); // 0.1s
		
		seed++;


	}
	free(stars);
	return p.score;
}
