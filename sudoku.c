/*
 *   AUTHOR : SHADOWW
 *   LAST MODIFIED : 17 / 11 / 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SET_RED printf("\033[0;31m");
#define SET_GREEN printf("\033[0;32m");
#define SET_RESET printf("\033[0m");

int board[9][9], blockPosition[9], randomPositions[9], blockNumber, cellNumber, fillPositions, i, j, randomPosition, randomNumber;
int boardCheck[81] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

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
      if (!boardCheck[0])
      {
        board[0][0] = randomNumber;
        boardCheck[0] = 1;
      }
      break;
    case 2:
      if (!boardCheck[1])
      {
        board[0][1] = randomNumber;
        boardCheck[1] = 1;
      }
      break;
    case 3:
      if (!boardCheck[2])
      {
        board[0][2] = randomNumber;
        boardCheck[2] = 1;
      }
      break;
    case 4:
      if (!boardCheck[3])
      {
        board[1][0] = randomNumber;
        boardCheck[3] = 1;
      }
      break;
    case 5:
      if (!boardCheck[4])
      {
        board[1][1] = randomNumber;
        boardCheck[4] = 1;
      }
      break;
    case 6:
      if (!boardCheck[5])
      {
        board[1][2] = randomNumber;
        boardCheck[5] = 1;
      }
      break;
    case 7:
      if (!boardCheck[6])
      {
        board[2][0] = randomNumber;
        boardCheck[6] = 1;
      }
      break;
    case 8:
      if (!boardCheck[7])
      {
        board[2][1] = randomNumber;
        boardCheck[7] = 1;
      }
      break;
    case 9:
      if (!boardCheck[8])
      {
        board[2][2] = randomNumber;
        boardCheck[8] = 1;
      }
      break;
    }
    break;

  case 2:
    switch (cellNumber)
    {
    case 1:
      if (!boardCheck[9])
      {
        board[0][3] = randomNumber;
        boardCheck[9] = 1;
      }
      break;
    case 2:
      if (!boardCheck[10])
      {
        board[0][4] = randomNumber;
        boardCheck[10] = 1;
      }
      break;
    case 3:
      if (!boardCheck[11])
      {
        board[0][5] = randomNumber;
        boardCheck[11] = 1;
      }
      break;
    case 4:
      if (!boardCheck[12])
      {
        board[1][3] = randomNumber;
        boardCheck[12] = 1;
      }
      break;
    case 5:
      if (!boardCheck[13])
      {
        board[1][4] = randomNumber;
        boardCheck[13] = 1;
      }
      break;
    case 6:
      if (!boardCheck[14])
      {
        board[1][5] = randomNumber;
        boardCheck[14] = 1;
      }
      break;
    case 7:
      if (!boardCheck[15])
      {
        board[2][3] = randomNumber;
        boardCheck[15] = 1;
      }
      break;
    case 8:
      if (!boardCheck[16])
      {
        board[2][4] = randomNumber;
        boardCheck[16] = 1;
      }
      break;
    case 9:
      if (!boardCheck[17])
      {
        board[2][5] = randomNumber;
        boardCheck[17] = 1;
      }
      break;
    }
    break;

  case 3:
    switch (cellNumber)
    {
    case 1:
      if (!boardCheck[18])
      {
        board[0][6] = randomNumber;
        boardCheck[18] = 1;
      }
      break;
    case 2:
      if (!boardCheck[19])
      {
        board[0][7] = randomNumber;
        boardCheck[19] = 1;
      }
      break;
    case 3:
      if (!boardCheck[20])
      {
        board[0][8] = randomNumber;
        boardCheck[20] = 1;
      }
      break;
    case 4:
      if (!boardCheck[21])
      {
        board[1][6] = randomNumber;
        boardCheck[21] = 1;
      }
      break;
    case 5:
      if (!boardCheck[22])
      {
        board[1][7] = randomNumber;
        boardCheck[22] = 1;
      }
      break;
    case 6:
      if (!boardCheck[23])
      {
        board[1][8] = randomNumber;
        boardCheck[23] = 1;
      }
      break;
    case 7:
      if (!boardCheck[24])
      {
        board[2][6] = randomNumber;
        boardCheck[24] = 1;
      }
      break;
    case 8:
      if (!boardCheck[25])
      {
        board[2][7] = randomNumber;
        boardCheck[25] = 1;
      }
      break;
    case 9:
      if (!boardCheck[26])
      {
        board[2][8] = randomNumber;
        boardCheck[26] = 1;
      }
      break;
    }
    break;

  case 4:
    switch (cellNumber)
    {
    case 1:
      if (!boardCheck[27])
      {
        board[3][0] = randomNumber;
        boardCheck[27] = 1;
      }
      break;
    case 2:
      if (!boardCheck[28])
      {
        board[3][1] = randomNumber;
        boardCheck[28] = 1;
      }
      break;
    case 3:
      if (!boardCheck[29])
      {
        board[3][2] = randomNumber;
        boardCheck[29] = 1;
      }
      break;
    case 4:
      if (!boardCheck[30])
      {
        board[4][0] = randomNumber;
        boardCheck[30] = 1;
      }
      break;
    case 5:
      if (!boardCheck[31])
      {
        board[4][1] = randomNumber;
        boardCheck[31] = 1;
      }
      break;
    case 6:
      if (!boardCheck[32])
      {
        board[4][2] = randomNumber;
        boardCheck[32] = 1;
      }
      break;
    case 7:
      if (!boardCheck[33])
      {
        board[5][0] = randomNumber;
        boardCheck[33] = 1;
      }
      break;
    case 8:
      if (!boardCheck[34])
      {
        board[5][1] = randomNumber;
        boardCheck[34] = 1;
      }
      break;
    case 9:
      if (!boardCheck[35])
      {
        board[5][2] = randomNumber;
        boardCheck[35] = 1;
      }
      break;
    }
    break;

  case 5:
    switch (cellNumber)
    {
    case 1:
      if (!boardCheck[36])
      {
        board[3][3] = randomNumber;
        boardCheck[36] = 1;
      }
      break;
    case 2:
      if (!boardCheck[37])
      {
        board[3][4] = randomNumber;
        boardCheck[37] = 1;
      }
      break;
    case 3:
      if (!boardCheck[38])
      {
        board[3][5] = randomNumber;
        boardCheck[38] = 1;
      }
      break;
    case 4:
      if (!boardCheck[39])
      {
        board[4][3] = randomNumber;
        boardCheck[39] = 1;
      }
      break;
    case 5:
      if (!boardCheck[40])
      {
        board[4][4] = randomNumber;
        boardCheck[40] = 1;
      }
      break;
    case 6:
      if (!boardCheck[41])
      {
        board[4][5] = randomNumber;
        boardCheck[41] = 1;
      }
      break;
    case 7:
      if (!boardCheck[42])
      {
        board[5][3] = randomNumber;
        boardCheck[42] = 1;
      }
      break;
    case 8:
      if (!boardCheck[43])
      {
        board[5][4] = randomNumber;
        boardCheck[43] = 1;
      }
      break;
    case 9:
      if (!boardCheck[44])
      {
        board[5][5] = randomNumber;
        boardCheck[44] = 1;
      }
      break;
    }
    break;

  case 6:
    switch (cellNumber)
    {
    case 1:
      if (!boardCheck[45])
      {
        board[3][6] = randomNumber;
        boardCheck[45] = 1;
      }
      break;
    case 2:
      if (!boardCheck[46])
      {
        board[3][7] = randomNumber;
        boardCheck[46] = 1;
      }
      break;
    case 3:
      if (!boardCheck[47])
      {
        board[3][8] = randomNumber;
        boardCheck[47] = 1;
      }
      break;
    case 4:
      if (!boardCheck[48])
      {
        board[4][6] = randomNumber;
        boardCheck[48] = 1;
      }
      break;
    case 5:
      if (!boardCheck[49])
      {
        board[4][7] = randomNumber;
        boardCheck[49] = 1;
      }
      break;
    case 6:
      if (!boardCheck[50])
      {
        board[4][8] = randomNumber;
        boardCheck[50] = 1;
      }
      break;
    case 7:
      if (!boardCheck[51])
      {
        board[5][6] = randomNumber;
        boardCheck[51] = 1;
      }
      break;
    case 8:
      if (!boardCheck[52])
      {
        board[5][7] = randomNumber;
        boardCheck[52] = 1;
      }
      break;
    case 9:
      if (!boardCheck[53])
      {
        board[5][8] = randomNumber;
        boardCheck[53] = 1;
      }
      break;
    }
    break;

  case 7:
    switch (cellNumber)
    {
    case 1:
      if (!boardCheck[54])
      {
        board[6][0] = randomNumber;
        boardCheck[54] = 1;
      }
      break;
    case 2:
      if (!boardCheck[55])
      {
        board[6][1] = randomNumber;
        boardCheck[55] = 1;
      }
      break;
    case 3:
      if (!boardCheck[56])
      {
        board[6][2] = randomNumber;
        boardCheck[56] = 1;
      }
      break;
    case 4:
      if (!boardCheck[57])
      {
        board[7][0] = randomNumber;
        boardCheck[57] = 1;
      }
      break;
    case 5:
      if (!boardCheck[58])
      {
        board[7][1] = randomNumber;
        boardCheck[58] = 1;
      }
      break;
    case 6:
      if (!boardCheck[59])
      {
        board[7][2] = randomNumber;
        boardCheck[59] = 1;
      }
      break;
    case 7:
      if (!boardCheck[60])
      {
        board[8][0] = randomNumber;
        boardCheck[60] = 1;
      }
      break;
    case 8:
      if (!boardCheck[61])
      {
        board[8][1] = randomNumber;
        boardCheck[61] = 1;
      }
      break;
    case 9:
      if (!boardCheck[62])
      {
        board[8][2] = randomNumber;
        boardCheck[62] = 1;
      }
      break;
    }
    break;

  case 8:
    switch (cellNumber)
    {
    case 1:
      if (!boardCheck[63])
      {
        board[6][3] = randomNumber;
        boardCheck[63] = 1;
      }
      break;
    case 2:
      if (!boardCheck[64])
      {
        board[6][4] = randomNumber;
        boardCheck[64] = 1;
      }
      break;
    case 3:
      if (!boardCheck[65])
      {
        board[6][5] = randomNumber;
        boardCheck[65] = 1;
      }
      break;
    case 4:
      if (!boardCheck[66])
      {
        board[7][3] = randomNumber;
        boardCheck[66] = 1;
      }
      break;
    case 5:
      if (!boardCheck[67])
      {
        board[7][4] = randomNumber;
        boardCheck[67] = 1;
      }
      break;
    case 6:
      if (!boardCheck[68])
      {
        board[7][5] = randomNumber;
        boardCheck[68] = 1;
      }
      break;
    case 7:
      if (!boardCheck[69])
      {
        board[8][3] = randomNumber;
        boardCheck[69] = 1;
      }
      break;
    case 8:
      if (!boardCheck[70])
      {
        board[8][4] = randomNumber;
        boardCheck[70] = 1;
      }
      break;
    case 9:
      if (!boardCheck[71])
      {
        board[8][5] = randomNumber;
        boardCheck[71] = 1;
      }
      break;
    }
    break;

  case 9:
    switch (cellNumber)
    {
    case 1:
      if (!boardCheck[72])
      {
        board[6][6] = randomNumber;
        boardCheck[72] = 1;
      }
      break;
    case 2:
      if (!boardCheck[73])
      {
        board[6][7] = randomNumber;
        boardCheck[73] = 1;
      }
      break;
    case 3:
      if (!boardCheck[74])
      {
        board[6][8] = randomNumber;
        boardCheck[74] = 1;
      }
      break;
    case 4:
      if (!boardCheck[75])
      {
        board[7][6] = randomNumber;
        boardCheck[75] = 1;
      }
      break;
    case 5:
      if (!boardCheck[76])
      {
        board[7][7] = randomNumber;
        boardCheck[76] = 1;
      }
      break;
    case 6:
      if (!boardCheck[77])
      {
        board[7][8] = randomNumber;
        boardCheck[77] = 1;
      }
      break;
    case 7:
      if (!boardCheck[78])
      {
        board[8][6] = randomNumber;
        boardCheck[78] = 1;
      }
      break;
    case 8:
      if (!boardCheck[79])
      {
        board[8][7] = randomNumber;
        boardCheck[79] = 1;
      }
      break;
    case 9:
      if (!boardCheck[80])
      {
        board[8][8] = randomNumber;
        boardCheck[80] = 1;
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