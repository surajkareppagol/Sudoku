#include <stdio.h>
#include <string.h>
#include "sudoku.h"

/*********************************************
 *  Main Function
 *********************************************/

int main(int argc, char *argv[])
{
  if (argc > 1 && ((strcmp(argv[1], "-t")) == 0))
  {
    test();
    return 0;
  }
  init();
  return 0;
}

/*********************************************
 *  EOF
 *********************************************/