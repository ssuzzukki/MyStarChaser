#include <ncurses.h>
#include <time.h>
#include "timer.h"
#include "player.h"
#include "star.h"

void Game(void){
	int h, w, key;
	int sec = 30;
	time_t start = time(NULL);
	int d;
	int i;
	int fin = 0;
	int stand = 1;
	struct timespec t = {0, 100000000}; //0.1s
	Player p = newP();
	Star s = newS();

	timeout(0);
	getmaxyx(stdscr, h, w);
	erase();
	int ground = h-6;
	mvP(ground-1, w/2, &p);

	while(1){
		incP(&p, ground, &stand);
		incS(&s, ground);
		erase();
		for(i=0;i<w;i++){
			mvaddch(ground, i, '-');
		}

		printP(&p);
		printS(&s);

		d = diffsec(start);
		fin = Timer(h-1, w-6, sec - d);
		if(fin == 1) break;
		key = getch();
		mvaddch(h-1, 0, key);
		if(key == 'q') break;
		keyP(key, &p, &stand);
		
		nanosleep(&t, NULL);



	}


}
