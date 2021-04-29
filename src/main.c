#include "header.h"

/* /cygdrive/c/users/Timothy/OneDrive/Desktop/Projects/Code/Sudoku Solver/C
Here is the path, so I can stop going crazy from typing it all the time*/

int main() {
    char puzzleChar[9][9];
    int puzzle[9][9];
    printf(" a \n b 1");
    readFile(puzzleChar);
    printf(" a \n b 2");
    charToInt(puzzleChar, puzzle);

    printf(" a \n b 3");
    printPuzzle(puzzle);

    return 0;
}
