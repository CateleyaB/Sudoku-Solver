#ifndef HEADER_H
#define HEADER_H


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <assert.h>


typedef struct Square {
    int value;
    int candidates;  /*  111 111 111 (binary) <-> 0x1FF (hex)
                            987 654 321 (numbers each bit represents)
                            0 = not possible, 1 =  possible */
    int location[6];    /* [rows i, rows j, cols i, cols j, box i, box j] */
} Square;

typedef struct Sudoku {
  Square * rows[9][9];
  Square * columns[9][9];
  Square * boxes[9][9];
  int unsolved;
} Sudoku;


// error function
void exitFromError(int errorCode, Sudoku * sudoku);

// io functions
int readFile(char charArray[9][9]);
void printSudoku(Sudoku * sudoku);

// setup functions
int groupDuplicateNumberCheck(Square ** group, const int number);
int duplicateNumberCheck(Sudoku * sudoku);
Sudoku * setupSudoku(const char charArray[9][9], int * valid);

// sudoku management functions
Sudoku * copySudoku(Sudoku * src);
void freeSudoku(Sudoku * sudoku);

// solve functions
void solveAsHuman(Sudoku * sudoku);
int solveWithBruteForce(Sudoku * sudoku);
int attemptSolveAsHuman(Sudoku * sudoku);

// candidates functions
void updateSquareCandidates(int * candidates, const int value);
void updateCandidates(Sudoku * sudoku, const Square * square);
int validityCheck(Sudoku * sudoku);

// singles functions
int nakedSingles(Sudoku * sudoku);
int groupHiddenSingles(Square ** group, const int candidate, Sudoku * sudoku);
int hiddenSingles(Sudoku * sudoku);

#endif
