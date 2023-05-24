#include <ncurses.h>
#include <string.h>
#include <stdlib.h>

/*********************************************
 *  Utility Functions
 *********************************************/

void center(int row, int *columns, char *str)
{
  mvprintw(row, (*columns - strlen(str)) / 2, "%s", str);
  refresh();
}

void setBackground(char *mode)
{
  if (!has_colors())
  {
    mvprintw(0, 0, "sorry, your terminal doesn't support color.");
    refresh();
    exit(0);
  }

  start_color();
  if (strcmp(mode, "main") == 0)
  {
    init_pair(1, COLOR_YELLOW, COLOR_BLACK);
    bkgd(COLOR_PAIR(1));
  }
}

/*********************************************
 *  EOF
 *********************************************/