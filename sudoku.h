#ifndef _SUDOKU_H_
#define _SUDOKU_H_

/*********************************************
 *  Utility Functions
 *********************************************/

void displayBoard();
int randomNumberGeneratorWithRange(int, int);
int checkBlockPosition();
int checkRandomNumber();
void variableReset();

/*********************************************
 *  Game Mechanism Functions
 *********************************************/

void fillThePosition(int, int);
void generateBoard();
int checkWinCondition();
void removeDuplicatesHorizontal();
void removeDuplicatesVertical();

/*********************************************
 *  Game Solver Utility Functions
 *********************************************/

int checkRandomNumberHorizontal(int arr[10]);
void checkHorizontal(int arr[10], int);
void checkVertical(int arr[10], int);
int calculateNumber(int arr[10]);

/*********************************************
 *  Game Solver Functions
 *********************************************/

void horizontalSolver();
void verticalSolver();

/*********************************************
 *  Test and Init Functions
 *********************************************/

void test();
void init();

#endif

/*********************************************
 *  EOF
 *********************************************/