#include "header.h"


void solveAsHuman(Sudoku * sudoku) {
    int progress = 0;
    while(progress == 0 && sudoku->unsolved > 0) {
        if(validityCheck(sudoku) == 1) {
            exitFromError(3, sudoku);
        }

        progress = nakedSingles(sudoku);
        if(progress == 1) {
            progress = hiddenSingles(sudoku);
        }
        printSudoku(sudoku);
    }
}


int attemptSolveAsHuman(Sudoku * sudoku){
    int progress = 0;
    while(progress == 0 && sudoku->unsolved > 0) {
        if(validityCheck(sudoku) == 1) {
            return 1;  //would normally call exitFromError(3)
        }

        progress = nakedSingles(sudoku);
        if(progress == 1) {
            progress = hiddenSingles(sudoku);
        }
    }
    if(progress == 0) {
        return 0;  //found a solution to the puzzle
    }
    return 2;  //Needs more brute force applied
}


int solveWithBruteForce(Sudoku * sudoku) {
    Sudoku * sudokuIter;
    Sudoku * temp;
    int i, j, value;
    int solved, recursionDone, emptySquareFound;

    // for every square
    for(i = 0; i < 9; i ++) {
        for(j = 0; j < 9; j ++) {
            // for values 1 thru 9
            for(value = 0; value < 9; value ++) {
                // if the value is a candidate
                if((sudoku->rows[i][j]->candidates >> (value - 1)) & 1) {
                    emptySquareFound = 1;
                    // assume that square has that value
                    sudokuIter = copySudoku(sudoku);
                    sudokuIter->rows[i][j]->value = value;
                    sudokuIter->unsolved --;

                    updateCandidates(sudokuIter, sudokuIter->rows[i][j]);

                    // attempt to solve with the assumed value
                    solved = attemptSolveAsHuman(sudokuIter);

                    // decide what to do based on what happened when attempting to solve
                    switch(solved) {
                        case 0:
                            // In case I need to use this in the future
                            temp = copySudoku(sudokuIter);
                            * sudoku = * temp;

                            printSudoku(sudoku);
                            return 1;

                        case 2:  // iteration wasn't easily solveable
                            recursionDone = solveWithBruteForce(sudokuIter);  // recursive brute force
                            if(recursionDone) {  // this should break out of the recursion
                                temp = copySudoku(sudokuIter);
                                * sudoku = * temp;
                                return 1;
                            }

                        case 1:  // not the solution
                            break;  // nothing needs to be done, keep iterating
                    freeSudoku(sudokuIter);
                    }
                }
            }
            if(emptySquareFound == 1) return 0;
        }
    }
    return 0;
}
