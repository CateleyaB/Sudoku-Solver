CC = gcc
CFLAGS = -Wall -I$(IDIR) -g

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
