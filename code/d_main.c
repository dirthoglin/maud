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

#include <d_main.h>
#include <i_main.h>
#include <l_converter.h>

int maudmain()
{
  int frombase = 10, tobase = 2;
  char* option_selected = malloc(10 * sizeof(char));

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

  while(1)
  {
    I_Menu(
      "Main menu",
      "Exit",
      "ChangeBase",
      "Converter",
      "Calculator",
      NULL
      );

    printf("Write an option: "); scanf("%s", option_selected);

    if(!strcmp(option_selected, "Exit"))
      exit(EXIT_SUCCESS);
    else if(!strcmp(option_selected, "ChangeBase"))
    {
      printf("Write from base: "); scanf("%i", &frombase);
      printf("Write to base: "); scanf("%i", &tobase);
    }
    else if(!strcmp(option_selected, "Converter"))
    {
      int T;
      char* number = malloc(10 * sizeof(char));
      
      puts("Note: Write test cases, Write in the firts line the numbers");
      puts("Note: (i.e. '1 2 4 8 255')");

      printf("From base: %i\nTo base:%i\n", frombase, tobase);
      printf("Write test cases: "); scanf("%i", &T);
      while(T--)
      {
        scanf("%s", number);
        strcpy(number, fromDeci(tobase, toDeci(frombase, number)));
        printf("Result: %s\n", number);
      }

      free(number);
    }
    else if(!strcmp(option_selected, "Calculator"))
    {
      int T, number;
      char* n1 = malloc(10 * sizeof(char));
      char* n2 = malloc(10 * sizeof(char));
      char* opr = malloc(10 * sizeof(char));
      
      puts("Note: Write test cases, Write in the firts line the firts number, opr and second number");
      puts("Note: (i.e. '1 + 2', '254 + 1')");
      puts("Note: More(+) Less(-) Multiplication(*) Division(/)");

      printf("From base: %i\n", frombase);
      printf("Write test cases: "); scanf("%i", &T);
      while(T--)
      {
        scanf("%s %s %s", n1, opr, n2);

        number = toDeci(frombase, n1);
        if(!strcmp(opr, "+")) number += toDeci(frombase, n2);
        else if(!strcmp(opr, "-")) number -= toDeci(frombase, n2);
        else if(!strcmp(opr, "*")) number *= toDeci(frombase, n2);
        else if(!strcmp(opr, "/")) number /= toDeci(frombase, n2);
        else
          I_Error("Calculator: '%s' That's not an operator", opr);

        printf("Result: %s\n", fromDeci(frombase, number));
      }

      free(n1); free(n2); free(opr);
    }
    else
      puts("That's not an option");

    puts("\n");
  }
  
  return 0;
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
