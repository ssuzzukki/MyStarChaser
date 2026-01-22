CFLAGS = -DDEBUG -Wall
#CFLAGS = -Wall

all: main.o game.o timer.o player.o star.o

main: main.c
	cc main.o game.o timer.o player.o -lncurses -o main

main.o: main.c game.h

game.o: game.c timer.h player.h

timer.o: timer.c

player.o: player.c player.h

star.o: star.c star.h

.c.o:
	cc -c $< $(CFLAGS)

clean:
	-rm *.o

rmmain:
	-rm main
.SUFFIXES: .c .o

StarTracer:
	make all
	make main

.PHONY: all clean rmmain StarTracer
