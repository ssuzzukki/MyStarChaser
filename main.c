#include <ncurses.h>
#include <string.h>
#include <unistd.h>

#include "game.h"

int Title(void){
        erase();
        mvaddstr(1, 3, "STAR CHASER");
        mvaddstr(3, 3, "Key:");
        mvaddstr(5, 3, "start:[s]");
        mvaddstr(6, 3, "quit :[q]");

        refresh();
        return (getch());
}

int main(void){
	int h, w, key;
	initscr();
	noecho();
	curs_set(0);
	getmaxyx(stdscr, h, w);

	while(1){
		key = Title();
		if(key == 's'){
			Game();
		}else if(key == 'q'){
			break;
		}
	}
	endwin();
	return 0;
	}
