/*===================================
=            main header            =
===================================*/

/* 
I dedicate any and all copyright interest in this software to the
public domain. I make this dedication for the benefit of the public at
large and to the detriment of my heirs and successors. I intend this
dedication to be an overt act of relinquishment in perpetuity of all
present and future rights to this software under copyright law.

DESCRIPTION:
  Functions of main
*/

#ifndef _MAUD_MAIN_
#define _MAUD_MAIN_

int maudmain();
void I_Menu(char* title,char* option,...);
void I_Error (char *error, ...);
void delay(int mseconds);
void CheckParam();

#endif

/*=====  End of main header  ======*/
