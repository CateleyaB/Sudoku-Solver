#include "header.h"


Sudoku * setupSudoku(const char charArray[9][9], int * valid){

    Sudoku * sudoku;
    Square *** squares;
    int i, j;

    sudoku = malloc(sizeof(Sudoku));
    squares = (Square ***) malloc(sizeof(Square **) * 9);

    for(i = 0; i < 9; i ++) {
        squares[i] = (Square **) malloc(sizeof(Square *) * 9);

        for(j = 0; j < 9; j ++) {
            squares[i][j] = (Square*) malloc(sizeof(Square));
            //If memory runs out, I think just increase this malloc?

            squares[i][j]->value = (int)(charArray[i][j] - '0');
            squares[i][j]->candidates = pow(2, 9) - 1;
            squares[i][j]->location[0] = i;
            squares[i][j]->location[1] = j;
            squares[i][j]->location[2] = j;
            squares[i][j]->location[3] = i;
            squares[i][j]->location[4] = i/3 + 3*(j/3);
            squares[i][j]->location[5] = i%3 + 3*(j%3);

            sudoku->rows[i][j] = squares[i][j];
            sudoku->columns[j][i] = squares[i][j];
            sudoku->boxes[i/3 + 3*(j/3)][i%3 + 3*(j%3)] = squares[i][j];

            if(squares[i][j]->value < 0 || squares[i][j]->value > 9) {* valid = 1;}

            if(squares[i][j]->value != 0) {UNSOLVED --;}
        }
    }

    for(i = 0; i < 9; i ++) {
        for(j = 0; j < 9; j ++) {
            if(sudoku->rows[i][j]->value != 0) {
                updateCandidates(sudoku, sudoku->rows[i][j]);
            }
        }
    }

    sudoku->unsolved = 81;
    return sudoku;
}
