#include <ncurses.h>
#include <time.h>

void Timer(int y, int x, int sec){
	int m, s;
	m = sec / 60;
	s = sec % 60;

	move(y, x);
	printw("%2d:%2d", m, s);
}
