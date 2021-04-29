#include "header.h"


void printPuzzle(int puzzle[9][9]) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; i++) {
            printf("%d", puzzle[i][j]);
        }
    }
}


void charToInt(char charArray[9][9], int intArray[9][9]) {
    for(int i=0; i<9; i++) {
        for(int  j=0; j<9; j++) {
            intArray[i][j] = charArray[i][j] - '0';
        }
    }
}


void readFile(char charArray[9][9]) {
    char input[17][10];
    FILE* fp;
    char inputFName[30];

    printf("Input the name of the unsolved sudoku text file: ");
    scanf("%s", inputFName);

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
}
