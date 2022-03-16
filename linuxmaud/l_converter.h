/*========================================
=            converter header            =
========================================*/

/* 
I dedicate any and all copyright interest in this software to the
public domain. I make this dedication for the benefit of the public at
large and to the detriment of my heirs and successors. I intend this
dedication to be an overt act of relinquishment in perpetuity of all
present and future rights to this software under copyright law.

DESCRIPTION:
  Functions of converter
*/

#ifndef _MAUD_CONVERTER_
#define _MAUD_CONVERTER_

//base to decimal
int val(char c);
int toDeci(int base,char *str);

//decimal to base
char reVal(int num);
void strev(char *str);
char* fromDeci(int base, int inputNum);

#endif

/*=====  End of converter header  ======*/
