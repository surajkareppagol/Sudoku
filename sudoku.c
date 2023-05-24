#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "sudoku.h"
#include "decorate.h"

int board[9][18], blockPosition[9], randomPositions[9], blockNumber, cellNumber, fillPositions, i, j, randomPosition, randomNumber;

int rows, columns, rowPosition = 0;

char borderLines[] = {"----+---+----   ----+---+----   ----+---+----\n"};

/*********************************************
 *  Utility Functions
 *********************************************/

void displayBoard()
{

  for (int i = 0; i < 9; i++)
  {

    if (i % 3 == 0 && i > 0)
      center(rowPosition++, &columns, borderLines);
    center(rowPosition++, &columns, borderLines);
    mvprintw(rowPosition++, (columns - strlen(borderLines)) / 2, "| %d | %d | %d |   "
                                                                 "| %d | %d | %d |   "
                                                                 "| %d | %d | %d |   \n",
             board[i][0], board[i][1], board[i][2], board[i][3], board[i][4], board[i][5], board[i][6], board[i][7], board[i][8]);
  }
  center(rowPosition++, &columns, borderLines);
}

int randomNumberGeneratorWithRange(int min, int max)
{
  return rand() % (max - min + 1) + min;
}

int checkBlockPosition()
{
  for (int indexNumber = 1; indexNumber < fillPositions; indexNumber++)
    if (blockPosition[indexNumber] == randomPosition)
      return 1;
  return 0;
}

int checkRandomNumber()
{
  for (int indexNumber = 1; indexNumber < fillPositions; indexNumber++)
    if (randomPositions[indexNumber] == randomNumber)
      return 1;
  return 0;
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

/*********************************************
 *  Game Mechanism Functions
 *********************************************/

void fillThePosition(int blockNumber, int cellNumber)
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

void generateBoard()
{
  int indexNumber, blockNumber = 1;
  for (indexNumber = 0; indexNumber < 9; indexNumber++)
  {
    fillPositions = randomNumberGeneratorWithRange(7, 8);
    for (i = 1; i < fillPositions; i++)
    {
      randomPosition = randomNumberGeneratorWithRange(1, 9);
      while (checkBlockPosition())
        randomPosition = randomNumberGeneratorWithRange(1, 9);
      blockPosition[i] = randomPosition;
    }

    for (i = 1; i < fillPositions; i++)
    {
      randomNumber = randomNumberGeneratorWithRange(1, 9);
      while (checkRandomNumber())
        randomNumber = randomNumberGeneratorWithRange(1, 9);
      randomPositions[i] = randomNumber;
      fillThePosition(blockNumber, blockPosition[i]);
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

void removeDuplicatesHorizontal()
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

void removeDuplicatesVertical()
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

/*********************************************
 *  Game Solver Utility Functions
 *********************************************/

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
    if (board[row][j] != 0)
      arr[j + 1] = board[row][j];
}

void checkVertical(int arr[10], int row)
{
  for (int j = 0; j < 9; j++)
    arr[board[j][row]] = board[j][row];
}

int calculateNumber(int arr[10])
{
  for (int i = 1; i < 10; i++)
    if (arr[i] == 0)
      return i;
  return -1;
}

/*********************************************
 *  Game Solver Functions
 *********************************************/

void horizontalSolver()
{
  int horizontalNumberArray[10] = {0};
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

void verticalSolver()
{
  int startNumber;
  int generateNumber;
  int verticalNumberArray[10] = {0};
  for (int i = 0; i < 9; i++)
  {
    checkVertical(verticalNumberArray, i);
    for (int j = 0; j < 9; j++)
    {
      startNumber = board[j][i];
      for (int a = j + 1; a < 9; a++)
      {
        if (board[a][i] == startNumber)
        {
          generateNumber = calculateNumber(verticalNumberArray);
          board[a][i] = generateNumber;
          verticalNumberArray[generateNumber] = generateNumber;
        }
      }
    }
    for (int k = 0; k < 10; k++)
      verticalNumberArray[k] = 0;
  }
}

/*********************************************
 *  Test and Init Functions
 *********************************************/

void test()
{
  initscr();
  getmaxyx(stdscr, rows, columns);
  srand(time(NULL));
  setBackground("main");
  generateBoard();
  removeDuplicatesHorizontal();
  removeDuplicatesVertical();

  for (int i = 0; i < 3; i++)
  {
    mvprintw(++rowPosition, 2, "%s - %d\n", "stage", i + 1);
    if (i == 1)
      horizontalSolver();
    if (i == 2)
      verticalSolver();
    displayBoard();
    refresh();
    napms(2000);
    rowPosition = 0;
    clear();
    refresh();
  }
  endwin();
}

void init()
{
  initscr();
  getmaxyx(stdscr, rows, columns);
  srand(time(NULL));
  setBackground("main");
  center(rows / 2, &columns, "* Enjoy the game and thank you for playing it .\n\n");
  getch();
  clear();
  refresh();
  generateBoard();
  removeDuplicatesHorizontal();
  removeDuplicatesVertical();
  displayBoard();
  refresh();

  while (checkWinCondition())
  {
    center(rows - 2, &columns, "\nEnter the block, cell number and the value ,> ");
    scanw("%d%d%d", &blockNumber, &cellNumber, &randomNumber);
    clear();
    refresh();
    rowPosition = 0;
    if (blockNumber == 0 && cellNumber == 0 && randomNumber == 0)
    {
      center(rows / 2, &columns, "try again.\n");
      break;
    }
    fillThePosition(blockNumber, cellNumber);
    displayBoard();
    refresh();
  }

  if (!checkWinCondition())
    center(rows / 2, &columns, "Hurray, you won take the .\n");
  else if (checkWinCondition() && blockNumber != 0)
    center(rows / 2, &columns, "You lost, try again for .\n");
  getch();
  endwin();
}

/*********************************************
 *  EOF
 *********************************************/