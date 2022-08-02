/*
 *   AUTHOR : SHADOWW
 *   LAST MODIFIED : 07 / 07 / 2022
 */

//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//////////////////////////////////////////////////////////////////////////////

int board[9][9], blockPosition[9], randomPositionA[9], blockNumber, cellNumber, numberOfBlocks, i, j, randomPosition, randomNumber;

//////////////////////////////////////////////////////////////////////////////

void gameIntroduction();
void displayBoard();
int checkBlockPosition();
int checkRandomNumber();
int randomNumberGeneratorWithRange(int, int);
void fillTheBlockWithRandomNumber(int, int);
void variableReset();
void generateBoard();
int checkWinCondition();
void checkBoard();

//////////////////////////////////////////////////////////////////////////////

// MAIN FUNCTION
int main()
{
  gameIntroduction();
  printf("LOADING GAME .......\n\n");
  generateBoard();
  checkBoard();
  displayBoard();
  while (checkWinCondition)
  {
    printf("\nENTER THE BLOCK NUMBER, CELL NUMBER AND THE VALUE : ");
    scanf("%d%d%d", &blockNumber, &cellNumber, &randomNumber);
    if (blockNumber == 0 && cellNumber == 0 && randomNumber == 0)
    {
      printf("---------------------------------------------\n");
      printf("|   OH!!!! QUITTING TRY AGAIN NEXT TIME.    |\n");
      printf("---------------------------------------------\n");
      break;
    }
    fillTheBlockWithRandomNumber(blockNumber, cellNumber);
    displayBoard();
  }

  if (!checkWinCondition)
  {
    printf("------------------------------------\n");
    printf("|   CONGRATULATIONS!!! YOU WON.    |\n");
    printf("------------------------------------\n");
  }

  return 0;
}

//////////////////////////////////////////////////////////////////////////////

// GAMR INTRO
void gameIntroduction()
{
  printf("                                                 --------------\n");
  printf("                                                 |  SUDOKU    |\n");
  printf("                                                 --------------\n\n");

  printf("  ==> ABOUT THE GAME : \n\n");
  printf("|---------------------------------------------------------------------------------\n");
  printf("| * WELCOME TO SUDOKU GAME CREATED IN C LANGUAGE.                                |\n");
  printf("| * THIS GAME HAS NINE(9) BLOCKS AND NINE(9) CELLS IN EACH BLOCK.                |\n");
  printf("| * THE PROGRAM WILL PROMPT TO ENTER THE BLOCK NUMBER, CELL NUMBER AND THE VALUE.|\n");
  printf("| * IF YOU WANT TO EXIT THE GAME ENTER 0 0 0.                                    |\n");
  printf("| * IT WILL TAKE SOME TIME TO GENERATE THE BOARD.                                |\n");
  printf("|---------------------------------------------------------------------------------\n\n");
  printf("                                        +--------+  +--------+  +--------+\n");
  printf("                                        |   1    |  |   2    |  |   3    |\n");
  printf("                                        +--------+  +--------+  +--------+\n");
  printf("                                        |   4    |  |   5    |  |   6    |\n");
  printf("                                        +--------+  +--------+  +--------+\n");
  printf("                                        |   7    |  |   8    |  |   9    |\n");
  printf("                                        +--------+  +--------+  +--------+\n");
}

//////////////////////////////////////////////////////////////////////////////

// DISPLAY BOARD
void displayBoard()
{
  printf("----+---+----   ----+---+----   ----+---+----\n");
  printf("| %d | %d | %d |   | %d | %d | %d |   | %d | %d | %d |\n", board[0][0], board[0][1], board[0][2], board[0][3], board[0][4], board[0][5], board[0][6], board[0][7], board[0][8]);
  printf("----+---+----   ----+---+----   ----+---+----\n");
  printf("| %d | %d | %d |   | %d | %d | %d |   | %d | %d | %d |\n", board[1][0], board[1][1], board[1][2], board[1][3], board[1][4], board[1][5], board[1][6], board[1][7], board[1][8]);
  printf("----+---+----   ----+---+----   ----+---+----\n");
  printf("| %d | %d | %d |   | %d | %d | %d |   | %d | %d | %d |\n", board[2][0], board[2][1], board[2][2], board[2][3], board[2][4], board[2][5], board[2][6], board[2][7], board[2][8]);
  printf("----+---+----   ----+---+----   ----+---+----\n");

  printf("----+---+----   ----+---+----   ----+---+----\n");
  printf("| %d | %d | %d |   | %d | %d | %d |   | %d | %d | %d |\n", board[3][0], board[3][1], board[3][2], board[3][3], board[3][4], board[3][5], board[3][6], board[3][7], board[3][8]);
  printf("----+---+----   ----+---+----   ----+---+----\n");
  printf("| %d | %d | %d |   | %d | %d | %d |   | %d | %d | %d |\n", board[4][0], board[4][1], board[4][2], board[4][3], board[4][4], board[4][5], board[4][6], board[4][7], board[4][8]);
  printf("----+---+----   ----+---+----   ----+---+----\n");
  printf("| %d | %d | %d |   | %d | %d | %d |   | %d | %d | %d |\n", board[5][0], board[5][1], board[5][2], board[5][3], board[5][4], board[5][5], board[5][6], board[5][7], board[5][8]);
  printf("----+---+----   ----+---+----   ----+---+----\n");

  printf("----+---+----   ----+---+----   ----+---+----\n");
  printf("| %d | %d | %d |   | %d | %d | %d |   | %d | %d | %d |\n", board[6][0], board[6][1], board[6][2], board[6][3], board[6][4], board[6][5], board[6][6], board[6][7], board[6][8]);
  printf("----+---+----   ----+---+----   ----+---+----\n");
  printf("| %d | %d | %d |   | %d | %d | %d |   | %d | %d | %d |\n", board[7][0], board[7][1], board[7][2], board[7][3], board[7][4], board[7][5], board[7][6], board[7][7], board[7][8]);
  printf("----+---+----   ----+---+----   ----+---+----\n");
  printf("| %d | %d | %d |   | %d | %d | %d |   | %d | %d | %d |\n", board[8][0], board[8][1], board[8][2], board[8][3], board[8][4], board[8][5], board[8][6], board[8][7], board[8][8]);
  printf("----+---+----   ----+---+----   ----+---+----\n");
}

//////////////////////////////////////////////////////////////////////////////

// CHECK BLOCK POSITION
int checkBlockPosition()
{
  int indexNumber;
  for (indexNumber = 1; indexNumber < numberOfBlocks; indexNumber++)
    if (blockPosition[indexNumber] == randomPosition)
      return 1;
  return 0;
}

//////////////////////////////////////////////////////////////////////////////

// CHECK RANDOM NUMBER
int checkRandomNumber()
{
  int indexNumber;
  for (indexNumber = 1; indexNumber < numberOfBlocks; indexNumber++)
  {
    if (randomPositionA[indexNumber] == randomNumber)
      return 1;
  }
  return 0;
}

//////////////////////////////////////////////////////////////////////////////

// RANDOM NUMBER GENERATOR
int randomNumberGeneratorWithRange(int min, int max)
{
  int randomNumber;
  srand(time(NULL));
  randomNumber = rand() % (max - min + 1) + min;
  return randomNumber;
}

//////////////////////////////////////////////////////////////////////////////

// FILL THE BLOCK WITH RANDOM NUMBER
void fillTheBlockWithRandomNumber(int blockNumber, int cellNumber)
{
  if (blockNumber == 1)
  {
    switch (cellNumber)
    {
    case 1:
      board[0][0] = randomNumber;
      break;
    case 2:
      board[0][1] = randomNumber;
      break;
    case 3:
      board[0][2] = randomNumber;
      break;
    case 4:
      board[1][0] = randomNumber;
      break;
    case 5:
      board[1][1] = randomNumber;
      break;
    case 6:
      board[1][2] = randomNumber;
      break;
    case 7:
      board[2][0] = randomNumber;
      break;
    case 8:
      board[2][1] = randomNumber;
      break;
    case 9:
      board[2][2] = randomNumber;
      break;
    }
  }
  else if (blockNumber == 2)
  {
    switch (cellNumber)
    {
    case 1:
      board[0][3] = randomNumber;
      break;
    case 2:
      board[0][4] = randomNumber;
      break;
    case 3:
      board[0][5] = randomNumber;
      break;
    case 4:
      board[1][3] = randomNumber;
      break;
    case 5:
      board[1][4] = randomNumber;
      break;
    case 6:
      board[1][5] = randomNumber;
      break;
    case 7:
      board[2][3] = randomNumber;
      break;
    case 8:
      board[2][4] = randomNumber;
      break;
    case 9:
      board[2][5] = randomNumber;
      break;
    }
  }
  else if (blockNumber == 3)
  {
    switch (cellNumber)
    {
    case 1:
      board[0][6] = randomNumber;
      break;
    case 2:
      board[0][7] = randomNumber;
      break;
    case 3:
      board[0][8] = randomNumber;
      break;
    case 4:
      board[1][6] = randomNumber;
      break;
    case 5:
      board[1][7] = randomNumber;
      break;
    case 6:
      board[1][8] = randomNumber;
      break;
    case 7:
      board[2][6] = randomNumber;
      break;
    case 8:
      board[2][7] = randomNumber;
      break;
    case 9:
      board[2][8] = randomNumber;
      break;
    }
  }
  else if (blockNumber == 4)
  {
    switch (cellNumber)
    {
    case 1:
      board[3][0] = randomNumber;
      break;
    case 2:
      board[3][1] = randomNumber;
      break;
    case 3:
      board[3][2] = randomNumber;
      break;
    case 4:
      board[4][0] = randomNumber;
      break;
    case 5:
      board[4][1] = randomNumber;
      break;
    case 6:
      board[4][2] = randomNumber;
      break;
    case 7:
      board[5][0] = randomNumber;
      break;
    case 8:
      board[5][1] = randomNumber;
      break;
    case 9:
      board[5][2] = randomNumber;
      break;
    }
  }
  else if (blockNumber == 5)
  {
    switch (cellNumber)
    {
    case 1:
      board[3][3] = randomNumber;
      break;
    case 2:
      board[3][4] = randomNumber;
      break;
    case 3:
      board[3][5] = randomNumber;
      break;
    case 4:
      board[4][3] = randomNumber;
      break;
    case 5:
      board[4][4] = randomNumber;
      break;
    case 6:
      board[4][5] = randomNumber;
      break;
    case 7:
      board[5][3] = randomNumber;
      break;
    case 8:
      board[5][4] = randomNumber;
      break;
    case 9:
      board[5][5] = randomNumber;
      break;
    }
  }
  else if (blockNumber == 6)
  {
    switch (cellNumber)
    {
    case 1:
      board[3][6] = randomNumber;
      break;
    case 2:
      board[3][7] = randomNumber;
      break;
    case 3:
      board[3][8] = randomNumber;
      break;
    case 4:
      board[4][6] = randomNumber;
      break;
    case 5:
      board[4][7] = randomNumber;
      break;
    case 6:
      board[4][8] = randomNumber;
      break;
    case 7:
      board[5][6] = randomNumber;
      break;
    case 8:
      board[5][7] = randomNumber;
      break;
    case 9:
      board[5][8] = randomNumber;
      break;
    }
  }
  else if (blockNumber == 7)
  {
    switch (cellNumber)
    {
    case 1:
      board[6][0] = randomNumber;
      break;
    case 2:
      board[6][1] = randomNumber;
      break;
    case 3:
      board[6][2] = randomNumber;
      break;
    case 4:
      board[7][0] = randomNumber;
      break;
    case 5:
      board[7][1] = randomNumber;
      break;
    case 6:
      board[7][2] = randomNumber;
      break;
    case 7:
      board[8][0] = randomNumber;
      break;
    case 8:
      board[8][1] = randomNumber;
      break;
    case 9:
      board[8][2] = randomNumber;
      break;
    }
  }
  else if (blockNumber == 8)
  {
    switch (cellNumber)
    {
    case 1:
      board[6][3] = randomNumber;
      break;
    case 2:
      board[6][4] = randomNumber;
      break;
    case 3:
      board[6][5] = randomNumber;
      break;
    case 4:
      board[7][3] = randomNumber;
      break;
    case 5:
      board[7][4] = randomNumber;
      break;
    case 6:
      board[7][5] = randomNumber;
      break;
    case 7:
      board[8][3] = randomNumber;
      break;
    case 8:
      board[8][4] = randomNumber;
      break;
    case 9:
      board[8][5] = randomNumber;
      break;
    }
  }
  else if (blockNumber == 9)
  {
    switch (cellNumber)
    {
    case 1:
      board[6][6] = randomNumber;
      break;
    case 2:
      board[6][7] = randomNumber;
      break;
    case 3:
      board[6][8] = randomNumber;
      break;
    case 4:
      board[7][6] = randomNumber;
      break;
    case 5:
      board[7][7] = randomNumber;
      break;
    case 6:
      board[7][8] = randomNumber;
      break;
    case 7:
      board[8][6] = randomNumber;
      break;
    case 8:
      board[8][7] = randomNumber;
      break;
    case 9:
      board[8][8] = randomNumber;
      break;
    }
  }
}

//////////////////////////////////////////////////////////////////////////////

// RESET VARIABLES
void variableReset()
{
  for (int i = 0; i < numberOfBlocks; i++)
  {
    blockPosition[i] = 0;
    randomPositionA[i] = 0;
  }
  numberOfBlocks = 0;
  randomPosition = 0;
  randomNumber = 0;
}

//////////////////////////////////////////////////////////////////////////////

// GENERATE BOARD
void generateBoard()
{
  int indexNumber, blockNumber = 1;
  for (indexNumber = 0; indexNumber < 9; indexNumber++)
  {
    numberOfBlocks = randomNumberGeneratorWithRange(6, 8);
    for (i = 1; i < numberOfBlocks; i++)
    {
      randomPosition = randomNumberGeneratorWithRange(1, 9);
      while (checkBlockPosition())
        randomPosition = randomNumberGeneratorWithRange(1, 9);
      blockPosition[i] = randomPosition;
    }

    for (i = 1; i < numberOfBlocks; i++)
    {
      randomNumber = randomNumberGeneratorWithRange(1, 9);
      while (checkRandomNumber())
        randomNumber = randomNumberGeneratorWithRange(1, 9);
      randomPositionA[i] = randomNumber;
      fillTheBlockWithRandomNumber(blockNumber, blockPosition[i]);
    }
    blockNumber += 1;
    variableReset();
  }
}

//////////////////////////////////////////////////////////////////////////////

// CHECK WIN CONDITION
int checkWinCondition()
{
  int indexI, indexJ, sum, score;
  for (indexI = 0; indexI < 9; indexI++)
  {
    sum = 0;
    for (indexJ = 0; indexJ < 9; indexJ++)
    {
      sum += board[indexI][indexJ];
    }

    if (sum != 45)
      return 1;
    else if (sum == 45)
      score += 1;
  }
  for (indexJ = 0; indexJ < 9; indexJ++)
  {
    sum = 0;
    for (indexI = 0; indexI < 9; indexI++)
    {
      sum += board[indexI][indexJ];
    }
    score += 1;
    if (sum != 45)
      return 1;
    else if (sum == 45)
      score += 1;
  }
  if (score == 18)
    return 0;
  return -1;
}

//////////////////////////////////////////////////////////////////////////////

// CHECK BOARD FOR REPEATED NUMBERS
void checkBoard()
{
  int indexI, indexJ, indexValue = 0, indexNumber, tempElement;
  for (indexNumber = 0; indexNumber < 9; indexNumber++)
  {
    for (indexI = 0; indexI < 9; indexI++)
    {
      if (board[indexValue][indexI] != 0)
      {
        tempElement = board[indexValue][indexI];
        for (indexJ = 0; indexJ < 9; indexJ++)
        {
          if (board[indexValue][indexJ] == tempElement && indexJ != indexI)
            board[indexValue][indexJ] = 0;
        }
      }
    }
    indexValue += 1;
  }
}

//////////////////////////////////////////////////////////////////////////////