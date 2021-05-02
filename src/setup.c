#include "header.h"


Sudoku * setupSudoku(const char charArray[9][9], int * valid){
    Sudoku * sudoku;
    Square ** squares;
    int i, j;

    sudoku = malloc(sizeof(Sudoku));
    squares = (Square **) malloc(sizeof(Square *) * 9);

    for(i = 0; i < 9; i ++) {
        squares[i] = (Square *) malloc(sizeof(Square) * 9);

        for(j = 0; j < 9; j ++) {
            // squares[i][j] = (Square) malloc(sizeof(Square));
            //I think this previous line is not necessary at all,
            //so I commented it out

            squares[i][j].value = (int)(charArray[i][j] - '0');
            squares[i][j].possibilities = (2 ^ 9) - 1;

            sudoku->rows[i][j] = squares[i][j];
            sudoku->columns[j][i] = squares[i][j];
            sudoku->boxes[i/3 + 3*(j/3)][i%3 + 3*(j%3)] = squares[i][j];

            if(squares[i][j].value < 0 || squares[i][j].value > 9) {
                * valid = 1;
            }
        }
    }
    sudoku->unsolved = 81;
    return sudoku;
}
