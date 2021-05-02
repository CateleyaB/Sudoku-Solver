#include "header.h"

/* cygdrive/c/Users/Timothy/OneDrive/Desktop/Projects/Code/Sudoku\ Solver
Here is the path, so I can stop going crazy from typing it all the time*/

int main() {
    char puzzleChar[9][9];
    Sudoku * sudoku;

    if(readFile(puzzleChar) == 1) {return 0;}
    sudoku = setupSudoku(puzzleChar);
    printSudoku(sudoku);

    return 0;
}
