#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// io functions
int readFile(char charArray[9][9]);
void printSudoku(Sudoku * sudoku);

//setup function
Sudoku * setupSudoku(const char charArray[9][9]);

// solving functions
//
//

typedef struct Square {
  int value;
  int possibilities;  /*000 000 000 (binary) <-> 987 654 321 (numbers each bit represents)
                        0 = not possible, 1 =  possible*/
} Square;

typedef struct Sudoku {
  Square rows[9][9];
  Square columns[9][9];
  Square boxes[9][9];
  int unsolved;
} Sudoku;

#endif
