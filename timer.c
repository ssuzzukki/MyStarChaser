#include <ncurses.h>
#include <time.h>

// 残り時間を表示する関数
int Timer(int y, int x, int sec){
	int m, s;
	m = sec / 60;
	s = sec % 60;
	move(y, x);
	printw("%2d:%2d", m, s);
	if(sec<=0) return 1;
	return 0;
}

// 時間の差をintで返す
int diffsec(time_t start){
	time_t now = time(NULL);
	return (int)difftime(now, start);
}
