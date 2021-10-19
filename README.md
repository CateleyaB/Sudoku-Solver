# Sudoku Solver

This is a program I made which can solve most sudoku puzzles.

## Description

The program takes a text file with 9 lines of 9 digits as an input. 
The program will proceed to solve the sudoku puzzle when it recieves a valid input and print the steps to the console.  
The current algorithm does this by finding [naked and hidden singles](http://hodoku.sourceforge.net/en/tech_singles.php) until it is solved or gets stuck.  
Other than the input file, all IO is console-based and the program is compiled each time it is run using a makefile.

### Dependencies

I have only tested this on Windows 10--it might have input issues on other OSes due to text file formatting.  
GCC and make are required (tested on both Cygwin and WSL).

### Installing

To install, just pull, clone, or download the repository and place the main folder anywhere.

### Executing program
1. Place a text file containing the puzzle you wish to solve into the input folder. There are also sample puzzle files included.   
   e.g. *easy1.txt*
   ```
   000200740
   001730960
   600190000
   200900670
   030628010
   046007008
   000062007
   065079300
   023001000
   ```

2. Navigate inside of the Sudoku Solver folder, wherever you placed it, and use the make command:
```
make
```
3. Input the name of the input file with the puzzle you wish to solve.
## Version History

* 0.1 (May 3 2021)
    * First working version; can solve most puzzles by using both naked and hidden singles.

## Acknowledgments
Based on the following YouTube tutorial (with notable changes to streamline the code):
* [Coding a Sudoku Solver in C by badcodinghabits](https://youtube.com/playlist?list=PLkTXsX7igf8edTYU92nU-f5Ntzuf-RKvW)

This readme uses a simplified version of the following template:
* [README.md-template](https://gist.github.com/DomPizzie/7a5ff55ffa9081f2de27c315f5018afc)
