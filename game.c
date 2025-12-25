#include <ncurses.h>
#include "timer.h"

void Game(void){
	int h, w, key;
	getmaxyx(stdscr, h, w);
	erase();
	while(1){
		key = getch();
		mvaddch(h-1, 0, key);
		Timer(h/2, w/2, 330);
		if(key == 'q') break;
	}

}
