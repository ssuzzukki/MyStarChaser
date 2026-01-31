#include <ncurses.h>
#include <string.h>
#include <unistd.h>

#include "game.h"


void Title_Sudachi(void){
	int key;
        erase();
        mvaddstr(1, 3, "    ##                                  ##                                                    ");
        mvaddstr(2, 3, "########            # #               ########        ##       ##                             ");
        mvaddstr(3, 3, "    ##     ##       # #                 ##            ##        ##                            ");
        mvaddstr(4, 3, "  ####  ############                    ##            ##        ##      ##                    ");
        mvaddstr(5, 3, " #  ##     ##          ##    ##    ##   #####   ###    ##       ##  ########                  ");
        mvaddstr(6, 3, "  ####     ##  ###       ####  ####         ## #####   ##       ##      ##    ##    ##    ##  ");
        mvaddstr(7, 3, "    ##     ##                               ##   #      ###             ##      ####  ####    ");
        mvaddstr(8, 3, "    ##     ##                           #####   ####                 #####                    ");
        mvaddstr(9, 3, "           ##  ####                            #   ##               ##                        ");
	mvaddstr(10,3, "                                                                    ##                        ");
	mvaddstr(11,3, "                                                                     #####                    ");
	
        mvaddstr(15, 3, "SUDACHI");
        mvaddstr(21, 3, "quit :[q]");

        refresh();

	while(1){
		key = getch();
		if(key == 'q') break;
	}
}

void Title_StarChaser(void){
	int key;
	timeout(-1);

	while(1){
        	refresh();
        	erase();
        	mvaddstr(1, 3, "    ##                                  ##                                                    ");
        	mvaddstr(2, 3, "########                              ########        ##       ##                             ");
        	mvaddstr(3, 3, "    ##     ##                           ##            ##        ##                            ");
       		mvaddstr(4, 3, "  ####  ############                    ##            ##        ##      ##                    ");
        	mvaddstr(5, 3, " #  ##     ##          ##    ##    ##   #####   ###    ##       ##  ########                  ");
        	mvaddstr(6, 3, "  ####     ##  ###       ####  ####         ## #####   ##       ##      ##    ##    ##    ##  ");
        	mvaddstr(7, 3, "    ##     ##                               ##   #      ###             ##      ####  ####    ");
        	mvaddstr(8, 3, "    ##     ##                           #####   ####                 #####                    ");
        	mvaddstr(9, 3, "           ##  ####                            #   ##               ##                        ");
		mvaddstr(10,3, "                                                                    ##                        ");
		mvaddstr(11,3, "                                                                     #####                    ");
	
        	mvaddstr(15, 3, "Star Chaser");
        	mvaddstr(17, 3, "\"Star Chaser\" is made by KUROBA-U.");
        	mvaddstr(19, 3, "Please enjoy \"Star Chaser\", and read \"magic of stella\".");
        	mvaddstr(21, 3, "https://zenpo-huchui.com/magic_of_stella_game/index.php");
        	mvaddstr(25, 3, "quit :[q]");


		key = getch();
		if(key == 'S') Title_Sudachi();
		if(key == 'q') break;
	}

}

int Title_StarTracer(int score){
        erase();
        mvaddstr(1, 3, "    ##                                                                                                ");
        mvaddstr(2, 3, "########                                ##    ##              ##       ##                             ");
        mvaddstr(3, 3, "    ##     ##                            ## ###               ##        ##                            ");
        mvaddstr(4, 3, "  ####  ############                      ##        ##        ##        ##      ##                    ");
        mvaddstr(5, 3, " #  ##     ##          ##    ##    ##    ##       #######      ##       ##  ########                  ");
        mvaddstr(6, 3, "  ####     ##  ###       ####  ####     ##          ## #  ###  ##       ##      ##    ##    ##    ##  ");
        mvaddstr(7, 3, "    ##     ##                            #######    ### ## ##   ###             ##      ####  ####    ");
        mvaddstr(8, 3, "    ##     ##                                     ######   ##                #####                    ");
        mvaddstr(9, 3, "           ##  ####                              #  ##     ## #             ##                        ");
	mvaddstr(10,3, "                                                    ##     ###              ##                        ");
	mvaddstr(11,3, "                                                                             #####                    ");
	
        mvaddstr(15, 3, "Star Tracer");
        mvaddstr(17, 3, "GAME start:[s]");
        mvaddstr(19, 3, "quit :[q]");

	mvaddstr(23, 3, "Let's catch stars!");

	move(27, 3);
	printw("LAST SCORE : %d", score);

        refresh();
	return getch();
}




// Game()を動かすとセグフォが出る
// 最初の一行すら動いてないのでmainが悪いかも
int main(void){
	int h, w, key;
	int score = 0;
	int sec = 90;
	initscr();
	noecho();
	curs_set(0);
	getmaxyx(stdscr, h, w);

	mvaddstr(h/2-1, w/2-17, "* Please maximize the screen size *");
	mvaddstr(h/2+1, w/2-10, "Press any key to play");
	getch();

	while(1){
		key = Title_StarTracer(score);
		if(key == 's') score = Game(sec);
		if(key == 'S') Title_StarChaser();
		if(key == 'q') break;
	}
	endwin();
	return 0;
	}
