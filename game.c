#include <ncurses.h>

void Game(void){
	int h, w, key;
	getmaxyx(stdscr, h, w);
	erase();
	while(1){
		key = getch();
		mvaddch(h-1, 0, key);
		if(key == 'q') break;
	}

}
