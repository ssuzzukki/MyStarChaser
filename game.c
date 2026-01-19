#include <ncurses.h>
#include <time.h>
#include "timer.h"

void Game(void){
	int h, w, key;
	int sec = 330;
	time_t start = time(NULL);
	int d;
	int i;

	getmaxyx(stdscr, h, w);
	erase();
	int ground = h-6

	while(1){
		for(i=0;i<w;i++){
			mvaddch(h-6, i, '-');
		} //地面はh-6行目

		d = diffsec(start);
		Timer(h-1, w-6, sec - d);
		key = getch();
		mvaddch(h-1, 0, key);
		if(key == 'q') break;
	}


}
