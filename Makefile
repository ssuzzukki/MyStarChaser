CFLAGS = -DDEBUG -Wall
#CFLAGS = -Wall

all: main.o game.o

main: main.c
	cc main.o game.o -lncurses -o main

main.o: main.c game.h

game.o: game.c

.c.o:
	cc -c $< $(CFLAGS)

.SUFFIXES: .c .o

.PHONY: all
