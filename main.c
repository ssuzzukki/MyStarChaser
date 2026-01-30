#include <ncurses.h>
#include <string.h>
#include <unistd.h>

#include "game.h"

int Title0(void){
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
        	mvaddstr(19, 3, "Please enjoy \"Star Chaser\", and read \"magic of stella\"");
        	mvaddstr(21, 3, "https://zenpo-huchui.com/magic_of_stella_game/index.php");
        	mvaddstr(25, 3, "quit :[q]");

		key = getch();
		if(key == 'S') Title2();
		if(key == 'q') break;
	}

        return 0;
}

int Title1(void){
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

        refresh();
        return (getch());
}


int Title2(void){
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
        return 0;
}



int main(void){
	int h, w, key;
	initscr();
	noecho();
	curs_set(0);
	getmaxyx(stdscr, h, w);

	while(1){
		key = Title1();
		if(key == 's') Game();
		if(key == 'S') Title0();
		if(key == 'q') break;

	}
	endwin();
	return 0;
	}
