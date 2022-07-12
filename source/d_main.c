/*=================================
=            main body            =
=================================*/

/* 
I dedicate any and all copyright interest in this software to the
public domain. I make this dedication for the benefit of the public at
large and to the detriment of my heirs and successors. I intend this
dedication to be an overt act of relinquishment in perpetuity of all
present and future rights to this software under copyright law.

DESCRIPTION:
  Loop program
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <time.h>

#include <ncurses.h>

#include <d_main.h>
#include <i_main.h>
#include <l_converter.h>

int maudmain()
{
  int frombase = 10, tobase = 2;
  bool maudExit = false;
  WINDOW *mainWindow;
  struct winsize sizeTTY;
  /*
  winsize.ws_row == height
  winsize.ws_col == width
  */

  initscr();
  
  
  while(!maudExit)
  {
    ioctl(0, TIOCGWINSZ, &sizeTTY);
    
    // print main window
    mainWindow = newwin(sizeTTY.ws_row, sizeTTY.ws_col, 0, 0);
    box(mainWindow, 0, 0);
    wprintw(mainWindow, "MAUD DE GALES");
    wrefresh(mainWindow);
    
    move(sizeTTY.ws_row / 2, sizeTTY.ws_col / 2);
    printw("Hello world!");

    refresh();
    delay(1000 * 50);
  }

  endwin();
  return 0;
}

void delay(int mseconds)
{
    // 1000 milli_seconds == 1 secons
    clock_t start_time = clock();
  
    while (clock() < start_time + mseconds);
}

void CheckParam()
{
  for(int i = 0;i < argc;i++)
  {
    if(!strcmp(argv[i], "--help"))
    {
      puts(
        "maud is a number conversion\n"
        "the code goes here: https://github.com/dirthoglin/maud"
        );
      exit(EXIT_SUCCESS);
    }
  }
}

void I_Menu(char* title,char* option,...)
{
  printf("\t%s\n", title);

  va_list argptr;
  va_start(argptr, option);
  char* actual = option;

  while(actual != NULL)
  {
    printf("> %s\n", actual);
    actual = va_arg(argptr, char*);
  }

  return;
}

void I_Error(char *error, ...)
{
    va_list argptr;

    va_start(argptr,error);
    fprintf(stderr, "Error: ");
    vfprintf(stderr,error,argptr);
    fprintf(stderr, "\n");
    va_end(argptr);

    fflush(stderr);
    exit(EXIT_FAILURE);
}

/*=====  End of main body  ======*/
