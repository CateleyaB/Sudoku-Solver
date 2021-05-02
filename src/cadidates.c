#include "header.h"


void updateSquareCandidates(int * candidates, const int value) {
/*
    if(candidate equal to the value) {
        remove candidate equal to value
    }

    e.g. if the function receives candidates = [001 010 110] and value = 3
    the function changes candidates to [001 010 010]
*/
    if(  ( ((* candidates) >> (value - 1)) & 1 ) == 1  ) {
        * candidates = * candidates - pow(2, value - 1);
    }
}


/* Only pass values that are not 0 into this function! */
void updateCandidates(Sudoku * sudoku, const Square * square) {
    int i, j;
    int * candidates;

    for(i = 0; i < 9; i ++) {
        for(j = 0; j < 9; j ++) {
            candidates = & sudoku->rows[square->location[0]][j]->candidates;
            updateSquareCandidates(candidates, square->value);
            candidates = & sudoku->columns[square->location[2]][j]->candidates;
            updateSquareCandidates(candidates, square->value);
            candidates = & sudoku->boxes[square->location[4]][j]->candidates;
            updateSquareCandidates(candidates, square->value);
        }
    }
}
