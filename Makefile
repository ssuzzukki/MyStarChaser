CFLAGS = -DDEBUG -Wall
#CFLAGS = -Wall

all: main.o game.o timer.o

main: main.c
	cc main.o game.o timer.o -lncurses -o main

main.o: main.c game.h

game.o: game.c

timer.o: timer.c

.c.o:
	cc -c $< $(CFLAGS)

clean:
	-rm *.o

.SUFFIXES: .c .o

.PHONY: all clean
