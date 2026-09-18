CC = gcc
CFLAGS = $(shell pkg-config --cflags raylib sdl3)
LIBS = $(shell pkg-config --libs raylib sdl3)

programa: main.c
	$(CC) main.c -o programa $(CFLAGS) $(LIBS)