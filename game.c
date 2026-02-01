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
	int turn = 0;
	Player p = newP();
	int snum = 10;
	Star **stars = calloc(20, sizeof(Star *));

	timeout(0);
	getmaxyx(stdscr, h, w);
	int ground = h-6;
	
	Star s0;
	Star s1;
	Star s2;
	Star s3;
	Star s4;
	Star s5;
	Star s6;
	Star s7;
	Star s8;
	Star s9;


	stars[0] = initS(&s0, w, seed+0);
	stars[1] = initS(&s1, w, seed+1);
	stars[2] = initS(&s2, w, seed+2);
	stars[3] = initS(&s3, w, seed+3);
	stars[4] = initS(&s4, w, seed+4);
	stars[5] = initS(&s5, w, seed+5);
	stars[6] = initS(&s6, w, seed+6);
	stars[7] = initS(&s7, w, seed+7);
	stars[8] = initS(&s8, w, seed+8);
	stars[9] = initS(&s9, w, seed+9);

/*
	for(i=0;i<snum;i++){
		initS(stars[i], w, seed+i);
	}
*/

/*
	stars[1] = newS(w, seed+1);
	stars[2] = newS(w, seed+2);
	stars[3] = newS(w, seed+3);
	stars[4] = newS(w, seed+4);
	stars[5] = newS(w, seed+5);
	stars[6] = newS(w, seed+6);
*/

	erase();
	mvP(ground-1, w/2, &p);

	while(1){
		incP(&p, ground);

		for(i=0;i<snum;i++){
			moveS(stars[i], ground, w, seed+i, turn);
		}


		
		for(i=0;i<snum;i++){
			touch(&p, stars[i]);
		}

		erase();

		pScore(h-1, w-20, &p);
		for(i=0;i<w;i++){
			mvaddch(ground, i, '-');
		}

		for(i=0;i<snum;i++){
			printS(stars[i]);
		}

		
		printP(&p);

		d = diffsec(start);
		fin = Timer(h-1, w-6, sec - d);
		if(fin == 1) break;
		key = getch();
		mvaddch(h-1, 0, key);
		if(key == 'q') break;
		keyP(key, &p);
		
		usleep(100000); // 0.1s
		
		seed++;
		turn++;


	}
	free(stars);
	return p.score;
}
