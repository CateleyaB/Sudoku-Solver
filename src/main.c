#include "header.h"

/* /cygdrive/c/Users/Timothy/OneDrive/Desktop/Projects/Code/Sudoku\ Solver
Here is the path, so I can stop going crazy from typing it all the time*/


int main() {
    char puzzleChar[9][9];
    Sudoku * sudoku;
    int valid = 0;

    if(readFile(puzzleChar) == 1) {return 0;}
    sudoku = setupSudoku(puzzleChar, &valid);
    if(valid == 1) {
        exitFromError(1, sudoku);
    } else if(valid == 2) {
        exitFromError(2, sudoku);
    }

    printSudoku(sudoku);
    printf("Solving as a person might:\n");
    solveAsHuman(sudoku);

    // To do with puzzles with multiple solutions
    if(sudoku->unsolved == 4) {  // This catches the easy to find cases
        exitFromError(4, sudoku);
    } else if(sudoku->unsolved > 0) {  // Warning for all other cases
        printf("Warning:\n");
        printf("It is possible that this puzzle has multiple solutions.\n");
        printf("The program will only show one if that is the case.\n");
    }

    //Will not be necessary for most inputs, is the last resort solving method.
    if(sudoku->unsolved > 0){
        printf("Now solving by brute force:\n");
        solveWithBruteForce(sudoku);
    }

    if(sudoku->unsolved > 0) {
        exitFromError(5, sudoku);  //Here in case of edge cases
    } else {
        printf("\n Solved!\n");
        freeSudoku(sudoku);
    }

    return 0;
}
