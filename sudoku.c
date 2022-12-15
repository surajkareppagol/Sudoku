/*
 *   AUTHOR : SHADOWW
 *   LAST MODIFIED : 17 / 11 / 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int board[9][9], blockPosition[9], randomPositions[9], blockNumber, cellNumber, fillPositions, i, j, randomPosition, randomNumber;

void displayBoard();
int checkBlockPosition();
int checkRandomNumber();
int randomNumberGeneratorWithRange(int, int);
void fillTheBlockWithRandomNumber(int, int);
void variableReset();
void generateBoard();
int checkWinCondition();

// Check if numbers are repeated in same rows and columns.
void checkBoardHorizontal();
void checkBoardVertical();

int main()
{
  srand(time(NULL));
  printf("* The game will take some time to generate the board, be patient 🙇.\n\n");
  generateBoard();
  checkBoardHorizontal();
  checkBoardVertical();
  displayBoard();
  while (checkWinCondition())
  {
    printf("\nEnter the block, cell number and the value 👇,\n> ");
    scanf("%d%d%d", &blockNumber, &cellNumber, &randomNumber);
    if (blockNumber == 0 && cellNumber == 0 && randomNumber == 0)
    {
      printf("You can do it 👍, try again.\n");
      break;
    }
    fillTheBlockWithRandomNumber(blockNumber, cellNumber);
    displayBoard();
  }

  if (!checkWinCondition())
    printf("Hurray, you won take the 🏅.\n");
  else if (checkWinCondition() && blockNumber != 0)
    printf("You lost, try again for 🏅.\n");
  return 0;
}

void displayBoard()
{
  for (int i = 0; i < 9; i++)
  {
    if (i % 3 == 0 && i > 0)
      printf("----+---+----   ----+---+----   ----+---+----\n");
    printf("----+---+----   ----+---+----   ----+---+----\n");
    printf("| %d | %d | %d |   | %d | %d | %d |   | %d | %d | %d |\n", board[i][0], board[i][1], board[i][2], board[i][3], board[i][4], board[i][5], board[i][6], board[i][7], board[i][8]);
  }
  printf("----+---+----   ----+---+----   ----+---+----\n");
}

// blockPosition[9] stores the position of the boards that already assigned.
int checkBlockPosition()
{
  for (int indexNumber = 1; indexNumber < fillPositions; indexNumber++)
    if (blockPosition[indexNumber] == randomPosition)
      return 1;
  return 0;
}

// Check if random number is repeated.
int checkRandomNumber()
{
  for (int indexNumber = 1; indexNumber < fillPositions; indexNumber++)
    if (randomPositions[indexNumber] == randomNumber)
      return 1;
  return 0;
}

// Generate random numbers within the range.
int randomNumberGeneratorWithRange(int min, int max)
{
  return rand() % (max - min + 1) + min;
}

// Fill the board with value.
void fillTheBlockWithRandomNumber(int blockNumber, int cellNumber)
{
  switch (blockNumber)
  {
  case 1:
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
    break;

  case 2:
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
    break;

  case 3:
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
    break;

  case 4:
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
    break;

  case 5:
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
    break;

  case 6:
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
    break;

  case 7:
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
    break;

  case 8:
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
    break;

  case 9:
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
    break;
  }
}

void variableReset()
{
  for (int i = 0; i < fillPositions; i++)
  {
    blockPosition[i] = 0;
    randomPositions[i] = 0;
  }
  fillPositions = 0;
  randomPosition = 0;
  randomNumber = 0;
}

void generateBoard()
{
  int indexNumber, blockNumber = 1;
  for (indexNumber = 0; indexNumber < 9; indexNumber++)
  {
    /* First find the number of positions to be filled. */
    fillPositions = randomNumberGeneratorWithRange(7, 8);
    for (i = 1; i < fillPositions; i++)
    {
      randomPosition = randomNumberGeneratorWithRange(1, 9);
      while (checkBlockPosition())
        randomPosition = randomNumberGeneratorWithRange(1, 9);
      blockPosition[i] = randomPosition;
    }

    /* Fill the positions with unique random numbers.*/
    for (i = 1; i < fillPositions; i++)
    {
      randomNumber = randomNumberGeneratorWithRange(1, 9);
      while (checkRandomNumber())
        randomNumber = randomNumberGeneratorWithRange(1, 9);
      randomPositions[i] = randomNumber;
      fillTheBlockWithRandomNumber(blockNumber, blockPosition[i]);
    }
    blockNumber += 1;
    variableReset();
  }
}

int checkWinCondition()
{
  int indexI, indexJ, score = 0;
  for (indexI = 0; indexI < 9; indexI++)
    for (indexJ = 0; indexJ < 9; indexJ++)
      score += board[indexI][indexJ];

  for (indexJ = 0; indexJ < 9; indexJ++)
    for (indexI = 0; indexI < 9; indexI++)
      score += board[indexI][indexJ];

  if (score == 810)
    return 0;
  return 1;
}

void checkBoardHorizontal()
{
  int indexI, indexJ, indexValue = 0, indexNumber, tempElement;
  for (indexNumber = 0; indexNumber < 9; indexNumber++)
  {
    for (indexI = 0; indexI < 9; indexI++)
      if (board[indexValue][indexI] != 0)
      {
        tempElement = board[indexValue][indexI];
        for (indexJ = 0; indexJ < 9; indexJ++)
          if (board[indexValue][indexJ] == tempElement && indexJ != indexI)
            board[indexValue][indexJ] = 0;
      }
    indexValue += 1;
  }
}

void checkBoardVertical()
{
  int indexI, indexJ, indexValue = 0, indexNumber, tempElement;
  for (indexNumber = 0; indexNumber < 9; indexNumber++)
  {
    for (indexI = 0; indexI < 9; indexI++)
      if (board[indexI][indexValue] != 0)
      {
        tempElement = board[indexI][indexValue];
        for (indexJ = 0; indexJ < 9; indexJ++)
          if (board[indexJ][indexValue] == tempElement && indexJ != indexI)
            board[indexJ][indexValue] = 0;
      }
    indexValue += 1;
  }
}