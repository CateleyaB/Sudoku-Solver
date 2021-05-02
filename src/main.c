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
        printf("\nThat is not a valid sudoku puzzle, aborted.\n");
        printf("(The values in the input file are not between 0 to 9,");
        printf(" or there are missing values)\n");
        return 0;
    } else if(valid == 2) {
        printf("\nThat is not a valid sudoku puzzle, aborted.\n");
        printf("(There are multiple of the same value in a group)\n");
        return 0;
    }

    printSudoku(sudoku);
    while(progress == 0 && UNSOLVED > 0) {
        if(validityCheck(sudoku) == 1) {
            printf("\nThat is not a valid sudoku puzzle, aborted.\n");
            printf("(There is an empty square with no candidates)\n");
            return 0;
        }

        progress = nakedSingles(sudoku);
        if(progress == 1) {
            progress = hiddenSingles(sudoku);
        }
        printSudoku(sudoku);
    }

    if(progress == 1) {
        if(UNSOLVED == 4) {
            printf("\nThere is more than one solution to this puzzle.");
            printf("\nPlease find a better puzzle next time.\n");
        } else {
            printf("\nThe puzzle was unable to be solved with ");
            printf("the current level of logic available in the program.\n");
        }
    } else {
        printf("\n Solved!\n");
    }

    return 0;
}
