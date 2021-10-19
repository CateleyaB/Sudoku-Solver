#include "header.h"


Sudoku * copySudoku(Sudoku * src) {
    Sudoku * dest;
    Square *** squares;
    int i, j, k;

    dest = malloc(sizeof(Sudoku));
    squares = (Square ***) malloc(sizeof(Square **) * 9);
    dest->unsolved = src->unsolved;

    for(i = 0; i < 9; i ++) {
        squares[i] = (Square **) malloc(sizeof(Square *) * 9);

        for(j = 0; j < 9; j ++) {
            squares[i][j] = (Square*) malloc(sizeof(Square));

            squares[i][j]->value = src->rows[i][j]->value;
            squares[i][j]->candidates = src->rows[i][j]->candidates;
            for(k = 0; k < 6; k ++) {
                squares[i][j]->location[k] = src->rows[i][j]->location[k];
            }
            dest->rows[i][j] = squares[i][j];
            dest->columns[j][i] = dest->rows[i][j];
            dest->boxes[i/3 + 3*(j/3)][i%3 + 3*(j%3)] = dest->rows[i][j];
        }

        free(squares[i]);
    }
    free(squares);
    return dest;
}


void freeSudoku(Sudoku * sudoku) {
    int i, j;
    for(i = 0; i < 9; i ++) {
        for(j = 0; j < 9; j ++) {
            free(sudoku->rows[i][j]);
        }
    }
    free(sudoku);
}
