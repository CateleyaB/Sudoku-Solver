#include "header.h"


void exitFromError(int errorCode, Sudoku * sudoku) {
    freeSudoku(sudoku);
    switch(errorCode) {
        case 1:  //bad input format
            printf("\nThat is not a valid sudoku puzzle, aborted.\n");
            printf("(The values in the input file are not between 0 to 9,");
            printf(" or there are missing values)\n");
            assert(0);

        case 2:  //bad values directly in input
            printf("\nThat is not a valid sudoku puzzle, aborted.\n");
            printf("(There are multiple of the same value in a group)\n");
            assert(0);

        case 3:  //bad values found when solving, no solutions exist
            printf("\nThat is not a valid sudoku puzzle, aborted.\n");
            printf("(There is an empty square with no candidates)\n");
            assert(0);

        case 4:  //more than one solution exists
            printf("\nThere is more than one solution to this puzzle.\n");
            printf("Please find a better puzzle next time.\n");
            assert(0);

        case 5:  //include at the end of program to catch edge cases
            printf("\nThe puzzle was unable to be solved with ");
            printf("the current level of logic available in the program.\n");
            assert(0);
    }
}
