/*===================================
=            main body            =
===================================*/

/* 
I dedicate any and all copyright interest in this software to the
public domain. I make this dedication for the benefit of the public at
large and to the detriment of my heirs and successors. I intend this
dedication to be an overt act of relinquishment in perpetuity of all
present and future rights to this software under copyright law.

DESCRIPTION:
  Main program, simply calls to maudmain
*/

#include <i_main.h>
#include <d_main.h>

int main(int arg1,char** arg2)
{
  argc = arg1;
  argv = arg2;

  maudmain();

  return 0;
}

/*=====  End of main body  ======*/
