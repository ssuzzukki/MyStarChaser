#include <ncurses.h>
#include <string.h>
#include <unistd.h>

int Title(void){
        erase();
        mvaddstr(1, 3, "STAR CHASER");
        mvaddstr(3, 3, "Key:");

        refresh();
        return (getch());
}

int main(void){
	int h, w;
	initscr();
	noecho();
	curs_set(0);
	getmaxyx(stdscr, h, w);

	Title();
	endwin();
	return 0;
	}
