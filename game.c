#include <ncurses.h>
#include <time.h>
#include "timer.h"
//memo wrisize()

void Game(void){
	int h, w, key;
	int sec = 330;
	time_t start = time(NULL);
	int d;

	getmaxyx(stdscr, h, w);
	erase();

	while(1){

		d = diffsec(start);
		Timer(h-1, w-6, sec - d);
		key = getch();
		mvaddch(h-1, 0, key);
		if(key == 'q') break;
	}


}
