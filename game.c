#include <ncurses.h>
#include <time.h>
#include "timer.h"
#include "player.h"
#include "star.h"

void Game(void){
	int h, w, key;
	int sec = 330;
	time_t start = time(NULL);
	int d;
	int i;
	int stand = 1;
	struct timespec t = {0, 100000000}; //0.1s
	Player p = newP();

	timeout(0);
	getmaxyx(stdscr, h, w);
	erase();
	int ground = h-6;
	mvP(ground-1, w/2, &p);

	while(1){
		incP(&p, ground, &stand);
		erase();
		for(i=0;i<w;i++){
			mvaddch(ground, i, '-');
		} //地面はh-6行目

		printP(&p);

		d = diffsec(start);
		Timer(h-1, w-6, sec - d);
		key = getch();
		mvaddch(h-1, 0, key);
		if(key == 'q') break;
		keyP(key, &p, &stand);
		
		nanosleep(&t, NULL);



	}


}
