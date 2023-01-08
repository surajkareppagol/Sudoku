/*
 *   AUTHOR : SHADOWW
 *   LAST MODIFIED : 17 / 11 / 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define SET_RED printf("\033[0;31m");
#define SET_GREEN printf("\033[0;32m");
#define SET_RESET printf("\033[0m");

int board[9][18], blockPosition[9], randomPositions[9], blockNumber, cellNumber, fillPositions, i, j, randomPosition, randomNumber;

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

int checkRandomNumberHorizontal(int arr[10]);
void checkHorizontal(int arr[10], int);
void horizontalSolver();

int calculateNumber(int arr[10]);
void checkVertical(int arr[10], int);
void verticalSolver();

int main(int argc, char *argv[])
{
  for (int x = 0; i < 9; i++)
    for (int y = 9; j < 18; j++)
      board[i][j] = 0;

  srand(time(NULL));
  printf("* Enjoy the game and thank you for playing it 🙇.\n\n");
  generateBoard();
  checkBoardHorizontal();
  checkBoardVertical();
  displayBoard();

  if (argc > 1 && ((strcmp(argv[1], "-h")) == 0))
  {
    printf("\n\n------------------------\n");
    printf("SOLVING HORIZONTALLY\n\n\n");
    horizontalSolver();
    displayBoard();
    printf("\n\n------------------------\n");
    printf("SOLVING VERTICALLY\n\n\n");
    verticalSolver();
    displayBoard();
    return 0;
  }

  while (checkWinCondition())
  {

    printf("\nEnter the block, cell number and the value 👇,\n> ");
    SET_GREEN
    scanf("%d%d%d", &blockNumber, &cellNumber, &randomNumber);
    SET_RESET
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
    printf("|\033[0;31m %d \033[0m|\033[0;31m %d \033[0m|\033[0;31m %d \033[0m|   "
           "|\033[0;31m %d \033[0m|\033[0;31m %d \033[0m|\033[0;31m %d \033[0m|   "
           "|\033[0;31m %d \033[0m|\033[0;31m %d \033[0m|\033[0;31m %d \033[0m|   \n",
           board[i][0], board[i][1], board[i][2], board[i][3], board[i][4], board[i][5], board[i][6], board[i][7], board[i][8]);
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
      if (!board[0][9])
      {
        board[0][0] = randomNumber;
        board[0][9] = 1;
      }
      break;
    case 2:
      if (!board[0][10])
      {
        board[0][1] = randomNumber;
        board[0][10] = 1;
      }
      break;
    case 3:
      if (!board[0][11])
      {
        board[0][2] = randomNumber;
        board[0][11] = 1;
      }
      break;
    case 4:
      if (!board[1][9])
      {
        board[1][0] = randomNumber;
        board[1][9] = 1;
      }
      break;
    case 5:
      if (!board[1][10])
      {
        board[1][1] = randomNumber;
        board[1][10] = 1;
      }
      break;
    case 6:
      if (!board[1][11])
      {
        board[1][2] = randomNumber;
        board[1][11] = 1;
      }
      break;
    case 7:
      if (!board[2][9])
      {
        board[2][0] = randomNumber;
        board[2][9] = 1;
      }
      break;
    case 8:
      if (!board[2][10])
      {
        board[2][1] = randomNumber;
        board[2][10] = 1;
      }
      break;
    case 9:
      if (!board[2][11])
      {
        board[2][2] = randomNumber;
        board[2][11] = 1;
      }
      break;
    }
    break;

  case 2:
    switch (cellNumber)
    {
    case 1:
      if (!board[0][12])
      {
        board[0][3] = randomNumber;
        board[0][12] = 1;
      }
      break;
    case 2:
      if (!board[0][13])
      {
        board[0][4] = randomNumber;
        board[0][13] = 1;
      }
      break;
    case 3:
      if (!board[0][14])
      {
        board[0][5] = randomNumber;
        board[0][14] = 1;
      }
      break;
    case 4:
      if (!board[1][12])
      {
        board[1][3] = randomNumber;
        board[1][12] = 1;
      }
      break;
    case 5:
      if (!board[1][13])
      {
        board[1][4] = randomNumber;
        board[1][13] = 1;
      }
      break;
    case 6:
      if (!board[1][14])
      {
        board[1][5] = randomNumber;
        board[1][14] = 1;
      }
      break;
    case 7:
      if (!board[2][12])
      {
        board[2][3] = randomNumber;
        board[2][12] = 1;
      }
      break;
    case 8:
      if (!board[2][13])
      {
        board[2][4] = randomNumber;
        board[2][13] = 1;
      }
      break;
    case 9:
      if (!board[2][14])
      {
        board[2][5] = randomNumber;
        board[2][14] = 1;
      }
      break;
    }
    break;

  case 3:
    switch (cellNumber)
    {
    case 1:
      if (!board[0][15])
      {
        board[0][6] = randomNumber;
        board[0][15] = 1;
      }
      break;
    case 2:
      if (!board[0][16])
      {
        board[0][7] = randomNumber;
        board[0][16] = 1;
      }
      break;
    case 3:
      if (!board[0][17])
      {
        board[0][8] = randomNumber;
        board[0][17] = 1;
      }
      break;
    case 4:
      if (!board[1][15])
      {
        board[1][6] = randomNumber;
        board[1][15] = 1;
      }
      break;
    case 5:
      if (!board[1][16])
      {
        board[1][7] = randomNumber;
        board[1][16] = 1;
      }
      break;
    case 6:
      if (!board[1][17])
      {
        board[1][8] = randomNumber;
        board[1][17] = 1;
      }
      break;
    case 7:
      if (!board[2][15])
      {
        board[2][6] = randomNumber;
        board[2][15] = 1;
      }
      break;
    case 8:
      if (!board[2][16])
      {
        board[2][7] = randomNumber;
        board[2][16] = 1;
      }
      break;
    case 9:
      if (!board[2][17])
      {
        board[2][8] = randomNumber;
        board[2][17] = 1;
      }
      break;
    }
    break;

  case 4:
    switch (cellNumber)
    {
    case 1:
      if (!board[3][9])
      {
        board[3][0] = randomNumber;
        board[3][9] = 1;
      }
      break;
    case 2:
      if (!board[3][10])
      {
        board[3][1] = randomNumber;
        board[3][10] = 1;
      }
      break;
    case 3:
      if (!board[3][11])
      {
        board[3][2] = randomNumber;
        board[3][11] = 1;
      }
      break;
    case 4:
      if (!board[4][9])
      {
        board[4][0] = randomNumber;
        board[4][9] = 1;
      }
      break;
    case 5:
      if (!board[4][10])
      {
        board[4][1] = randomNumber;
        board[4][10] = 1;
      }
      break;
    case 6:
      if (!board[4][11])
      {
        board[4][2] = randomNumber;
        board[4][11] = 1;
      }
      break;
    case 7:
      if (!board[5][9])
      {
        board[5][0] = randomNumber;
        board[5][9] = 1;
      }
      break;
    case 8:
      if (!board[5][10])
      {
        board[5][1] = randomNumber;
        board[5][10] = 1;
      }
      break;
    case 9:
      if (!board[5][11])
      {
        board[5][2] = randomNumber;
        board[5][11] = 1;
      }
      break;
    }
    break;

  case 5:
    switch (cellNumber)
    {
    case 1:
      if (!board[3][12])
      {
        board[3][3] = randomNumber;
        board[3][12] = 1;
      }
      break;
    case 2:
      if (!board[3][13])
      {
        board[3][4] = randomNumber;
        board[3][13] = 1;
      }
      break;
    case 3:
      if (!board[3][14])
      {
        board[3][5] = randomNumber;
        board[3][14] = 1;
      }
      break;
    case 4:
      if (!board[4][12])
      {
        board[4][3] = randomNumber;
        board[4][12] = 1;
      }
      break;
    case 5:
      if (!board[4][13])
      {
        board[4][4] = randomNumber;
        board[4][13] = 1;
      }
      break;
    case 6:
      if (!board[4][14])
      {
        board[4][5] = randomNumber;
        board[4][14] = 1;
      }
      break;
    case 7:
      if (!board[5][12])
      {
        board[5][3] = randomNumber;
        board[5][12] = 1;
      }
      break;
    case 8:
      if (!board[5][13])
      {
        board[5][4] = randomNumber;
        board[5][13] = 1;
      }
      break;
    case 9:
      if (!board[5][14])
      {
        board[5][5] = randomNumber;
        board[5][14] = 1;
      }
      break;
    }
    break;

  case 6:
    switch (cellNumber)
    {
    case 1:
      if (!board[3][15])
      {
        board[3][6] = randomNumber;
        board[3][15] = 1;
      }
      break;
    case 2:
      if (!board[3][16])
      {
        board[3][7] = randomNumber;
        board[3][16] = 1;
      }
      break;
    case 3:
      if (!board[3][17])
      {
        board[3][8] = randomNumber;
        board[3][17] = 1;
      }
      break;
    case 4:
      if (!board[4][15])
      {
        board[4][6] = randomNumber;
        board[4][15] = 1;
      }
      break;
    case 5:
      if (!board[4][16])
      {
        board[4][7] = randomNumber;
        board[4][16] = 1;
      }
      break;
    case 6:
      if (!board[4][17])
      {
        board[4][8] = randomNumber;
        board[4][17] = 1;
      }
      break;
    case 7:
      if (!board[5][15])
      {
        board[5][6] = randomNumber;
        board[5][15] = 1;
      }
      break;
    case 8:
      if (!board[5][16])
      {
        board[5][7] = randomNumber;
        board[5][16] = 1;
      }
      break;
    case 9:
      if (!board[5][17])
      {
        board[5][8] = randomNumber;
        board[5][17] = 1;
      }
      break;
    }
    break;

  case 7:
    switch (cellNumber)
    {
    case 1:
      if (!board[6][9])
      {
        board[6][0] = randomNumber;
        board[6][9] = 1;
      }
      break;
    case 2:
      if (!board[6][10])
      {
        board[6][1] = randomNumber;
        board[6][10] = 1;
      }
      break;
    case 3:
      if (!board[6][11])
      {
        board[6][2] = randomNumber;
        board[6][11] = 1;
      }
      break;
    case 4:
      if (!board[7][9])
      {
        board[7][0] = randomNumber;
        board[7][9] = 1;
      }
      break;
    case 5:
      if (!board[7][10])
      {
        board[7][1] = randomNumber;
        board[7][10] = 1;
      }
      break;
    case 6:
      if (!board[7][11])
      {
        board[7][2] = randomNumber;
        board[7][11] = 1;
      }
      break;
    case 7:
      if (!board[8][9])
      {
        board[8][0] = randomNumber;
        board[8][9] = 1;
      }
      break;
    case 8:
      if (!board[8][10])
      {
        board[8][1] = randomNumber;
        board[8][10] = 1;
      }
      break;
    case 9:
      if (!board[8][11])
      {
        board[8][2] = randomNumber;
        board[8][11] = 1;
      }
      break;
    }
    break;

  case 8:
    switch (cellNumber)
    {
    case 1:
      if (!board[6][12])
      {
        board[6][3] = randomNumber;
        board[6][12] = 1;
      }
      break;
    case 2:
      if (!board[6][13])
      {
        board[6][4] = randomNumber;
        board[6][13] = 1;
      }
      break;
    case 3:
      if (!board[6][14])
      {
        board[6][5] = randomNumber;
        board[6][14] = 1;
      }
      break;
    case 4:
      if (!board[7][12])
      {
        board[7][3] = randomNumber;
        board[7][12] = 1;
      }
      break;
    case 5:
      if (!board[7][13])
      {
        board[7][4] = randomNumber;
        board[7][13] = 1;
      }
      break;
    case 6:
      if (!board[7][14])
      {
        board[7][5] = randomNumber;
        board[7][14] = 1;
      }
      break;
    case 7:
      if (!board[8][12])
      {
        board[8][3] = randomNumber;
        board[8][12] = 1;
      }
      break;
    case 8:
      if (!board[8][13])
      {
        board[8][4] = randomNumber;
        board[8][13] = 1;
      }
      break;
    case 9:
      if (!board[8][14])
      {
        board[8][5] = randomNumber;
        board[8][14] = 1;
      }
      break;
    }
    break;

  case 9:
    switch (cellNumber)
    {
    case 1:
      if (!board[6][15])
      {
        board[6][6] = randomNumber;
        board[6][15] = 1;
      }
      break;
    case 2:
      if (!board[6][16])
      {
        board[6][7] = randomNumber;
        board[6][16] = 1;
      }
      break;
    case 3:
      if (!board[6][17])
      {
        board[6][8] = randomNumber;
        board[6][17] = 1;
      }
      break;
    case 4:
      if (!board[7][15])
      {
        board[7][6] = randomNumber;
        board[7][15] = 1;
      }
      break;
    case 5:
      if (!board[7][16])
      {
        board[7][7] = randomNumber;
        board[7][16] = 1;
      }
      break;
    case 6:
      if (!board[7][17])
      {
        board[7][8] = randomNumber;
        board[7][17] = 1;
      }
      break;
    case 7:
      if (!board[8][15])
      {
        board[8][6] = randomNumber;
        board[8][15] = 1;
      }
      break;
    case 8:
      if (!board[8][16])
      {
        board[8][7] = randomNumber;
        board[8][16] = 1;
      }
      break;
    case 9:
      if (!board[8][17])
      {
        board[8][8] = randomNumber;
        board[8][17] = 1;
      }
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
          {
            board[indexValue][indexJ + 9] = 0;
            board[indexValue][indexJ] = 0;
          }
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
          {
            board[indexJ][indexValue + 9] = 0;
            board[indexJ][indexValue] = 0;
          }
      }
    indexValue += 1;
  }
}

int checkRandomNumberHorizontal(int arr[10])
{
  for (int indexNumber = 1; indexNumber < 10; indexNumber++)
    if (arr[indexNumber] == randomNumber)
      return 1;
  return 0;
}

void checkHorizontal(int arr[10], int row)
{
  for (int j = 0; j < 9; j++)
  {
    if (board[row][j] != 0)
      arr[j + 1] = board[row][j];
  }
}

void horizontalSolver()
{
  int horizontalNumberArray[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (int i = 0; i < 9; i++)
  {
    checkHorizontal(horizontalNumberArray, i);
    for (int j = 0; j < 9; j++)
    {
      if (!horizontalNumberArray[j + 1])
      {
        randomNumber = randomNumberGeneratorWithRange(1, 9);
        while (checkRandomNumberHorizontal(horizontalNumberArray))
          randomNumber = randomNumberGeneratorWithRange(1, 9);
        board[i][j] = randomNumber;
        horizontalNumberArray[j + 1] = randomNumber;
      }
    }
    for (int k = 0; k < 10; k++)
      horizontalNumberArray[k] = 0;
  }
}

////////////////////////////////////////////////////
int calculateNumber(int arr[10])
{
  for (int i = 1; i < 10; i++)
  {
    if (arr[i] == 0)
      return i;
  }
}

void checkVertical(int arr[10], int row)
{
  for (int j = 0; j < 9; j++)
  {
    arr[board[j][row]] = board[j][row];
  }
}

void verticalSolver()
{
  int startNumber;
  int generateNumber;
  int veticalNumberArray[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  for (int i = 0; i < 9; i++)
  {
    checkVertical(veticalNumberArray, i);
    for (int j = 0; j < 9; j++)
    {
      startNumber = board[j][i];
      for (int a = j + 1; a < 9; a++)
      {
        if (board[a][i] == startNumber)
        {
          generateNumber = calculateNumber(veticalNumberArray);
          board[a][i] = generateNumber;
          veticalNumberArray[generateNumber] = generateNumber;
        }
      }
    }
    for (int k = 0; k < 10; k++)
      veticalNumberArray[k] = 0;
  }
}