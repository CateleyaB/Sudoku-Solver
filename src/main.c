#include "header.h"

/* /cygdrive/c/Users/Timothy/OneDrive/Desktop/Projects/Code/Sudoku\ Solver
Here is the path, so I can stop going crazy from typing it all the time*/


int UNSOLVED = 81;


int main() {
    char puzzleChar[9][9];
    Sudoku * sudoku;
    int valid = 0;
    int progress = 0;

    if(readFile(puzzleChar) == 1) {return 0;}
    sudoku = setupSudoku(puzzleChar, &valid);
    if(valid == 1) {
        printf("That is not a valid sudoku puzzle, aborted.\n");
        return 1;
    }

    printSudoku(sudoku);
    while(progress == 0 && UNSOLVED > 0) {
        progress = nakedSingles(sudoku);
        if(progress == 1) {
            progress = hiddenSingles(sudoku);
        }
        printSudoku(sudoku);
    }

    if(progress == 1) {
        printf("\nThe puzzle was unable to be solved with ");
        printf("the current level of logic available in the program.\n");
    } else if (progress == 0) {
        printf("\n Solved!\n");
    } else {
        printf("\n Error: progress variable in main.c = %d", progress);
        return 1;
    }

    return 0;
}
