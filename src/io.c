#include "header.h"


int readFile(char charArray[9][9]) {
    char input[17][10];
    FILE* fp;
    char inputFName[30];
    int valid_file = 0;

    while(valid_file == 0) {
        printf("Input the name of the unsolved sudoku text file or CANCEL to stop the program: ");
        scanf("%s", inputFName);
        if(strcmp(inputFName, "CANCEL") == 0){
            return 1;
        } else if( access( inputFName, F_OK ) == 0 ) {
            printf("Solving...\n");
            valid_file = 1;
        } else {
            printf("That file does not exist, please try again\n");
        }
    }

    //Read from file
    fp=fopen(inputFName, "r");
    for(int i=0; i<17; i++) {
        fgets(input[i], 10, fp);
    }
    fclose(fp);

    //copy to charArray, reformatted
    for(int i=0; i<17; i=i+2) {
        for(int j=0; j<9; j++) {
            charArray[i/2][j] = input[i][j];
        }
    }
    return 0;
}


void printSudoku(Sudoku * sudoku) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; i++) {
            printf(" %d ", sudoku->rows[i][j].value);
        }
    }
}
