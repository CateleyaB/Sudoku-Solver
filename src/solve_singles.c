#include "header.h"


int nakedSingles(Sudoku * sudoku) {
    int i, j, x = 1;
    double a;

    for(i = 0; i < 9; i ++){
        for(j = 0; j < 9; j ++){

            /* check if there is a naked single */
            if(sudoku->rows[i][j]->value == 0) {
                a = log(sudoku->rows[i][j]->candidates)/log(2);
                if(a == (int)a) {

                    /* input value of naked single */
                    sudoku->rows[i][j]->value = a + 1;
                    UNSOLVED --;
                    x = 0;

                    updateCandidates(sudoku, sudoku->rows[i][j]);
                }
            }
        }
    }
    return x; /* 0 if naked single solved, else 1 */
}


int groupHiddenSingles(Square ** group, const int candidate, Sudoku * sudoku){
    int i, location, count = 0, x = 1;

    /* check if there is a hidden single */
    for(i = 0; i < 9; i ++) {
        if(group[i]->value == 0){
            if(  ( ((group[i]->candidates) >> (candidate - 1)) & 1 ) == 1  ) {
                location = i;
                count ++;
            }
        }
    }

    if(count == 1) {

        /*input value of hidden single */
        group[location]->value = candidate;
        UNSOLVED --;
        x = 0;

        updateCandidates(sudoku, group[location]);
    }

    return x;
}


int hiddenSingles(Sudoku * sudoku) {
    int i, candidate, x = 1;

    for(i = 0; i < 9; i ++){
        for(candidate = 1; candidate <= 9; candidate ++) {
            x &= groupHiddenSingles(sudoku->rows[i], candidate, sudoku);
            x &= groupHiddenSingles(sudoku->columns[i], candidate, sudoku);
            x &= groupHiddenSingles(sudoku->boxes[i], candidate, sudoku);
        }
    }

    return x; /* 0 if naked single solved, else 1 */
}
