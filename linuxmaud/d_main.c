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

#include <d_main.h>
#include <l_converter.h>

int maudmain()
{
  printf("%i\n", toDeci(2,"1000"));
  printf("%s\n", fromDeci(2, 8));
  
  return 0;
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
    exit(-1);
}

/*=====  End of main body  ======*/
