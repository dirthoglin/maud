/*=====================================
=            converter body           =
=====================================*/

/* 
I dedicate any and all copyright interest in this software to the
public domain. I make this dedication for the benefit of the public at
large and to the detriment of my heirs and successors. I intend this
dedication to be an overt act of relinquishment in perpetuity of all
present and future rights to this software under copyright law.

DESCRIPTION:
  Convert number from any base to any base
*/

#include <stdlib.h>
#include <string.h>

#include <l_converter.h>
#include <d_main.h>

// To return value of a char. For example, 2 is
// returned for '2'. 10 is returned for 'A', 11
// for 'B'
int val(char c)
{
  if (c >= '0' && c <= '9')
    return (int)c - '0';
  else
    return (int)c - 'A' + 10;
}

// Function to convert a number from given base 'b'
// to decimal
int toDeci(int base,char *str)
{
  int len = strlen(str);
  int power = 1;
  int num = 0;
  int i;

  for (i = len - 1; i >= 0; i--)
  {
    if (val(str[i]) >= base)
      I_Error("toDeci: Invalid Number");

    num += val(str[i]) * power;
    power = power * base;
  }

  return num;
}

// To return char for a value. For example '2'
// is returned for 2. 'A' is returned for 10. 'B'
// for 11
char reVal(int num)
{
  if (num >= 0 && num <= 9)
    return (char)(num + '0');
  else
    return (char)(num - 10 + 'A');
}

// Utility function to reverse a string
void strev(char *str)
{
  int len = strlen(str);
  int i;
  for (i = 0; i < len/2; i++)
  {
    char temp = str[i];
    str[i] = str[len-i-1];
    str[len-i-1] = temp;
  }
}

// Function to convert a given decimal number
// to a base 'base' and
char* fromDeci(int base, int inputNum)
{
  int index = 0;
  char *res = malloc(10 * sizeof(char));

  while (inputNum > 0)
  {
    res[index++] = reVal(inputNum % base);
    inputNum /= base;
  }
  res[index] = '\0';
  strev(res);

  return res;
}

/*=====  End of converter body ======*/
