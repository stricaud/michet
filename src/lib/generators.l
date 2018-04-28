%{
 /* Written by Sebastien Tricaud */

#include <string.h>
#include <stdlib.h>
#include "generators.tab.h"

%}
%option noyywrap
%option yylineno
%option 8bit prefix="generators"

COMMENT          ^#.*\n
VARIABLE         %__.*__%
WORD             ([a-zA-Z0-9_\-]+(\(\-?[0-9\*]+\))?\.?)+
NEWLINE          \n
PROTOTYPE        prototype:.*\n
COMMA            \,
COLON            \:
INTEGER          [0-9]+

%%

{VARIABLE}     {
             generatorslval.string = strdup(generatorstext);
             return TOK_VARIABLE;
           }
{COMMENT}  {}
{COMMA}    { return TOK_COMMA; }
{COLON}    { return TOK_COLON; }
{INTEGER}  {
             generatorslval.integer = atoi(generatorstext);
             return TOK_INTEGER;
           }
[ \t\n];
{WORD}     {
             generatorslval.string = strdup(generatorstext);
             return TOK_WORD;
           }

{PROTOTYPE} {
              generatorslval.string = strdup(generatorstext);
              return TOK_PROTOTYPE;
            }

%%

void generatorserror(const char* s) {
  fprintf(stderr, "line %d: %s with %s\n", generatorslineno, s, generatorstext);
}

/*
int main(void)
{
        generatorslex;
}
*/
