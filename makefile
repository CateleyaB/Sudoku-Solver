CC = gcc
CFLAGS = -Wall -I$(IDIR) -lm

IDIR = ./include/
SRCDIR = ./src/

SOURCES = $(SRCDIR)*.c

all: clear sudoku run clean

clear:
	clear

sudoku:
	$(CC) $(SOURCES) $(CFLAGS) -o $@

run:
	./sudoku

clean:
	rm sudoku

debug:
	$(CC) $(SOURCES) $(CFLAGS) -g -o $@
