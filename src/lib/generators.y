%name-prefix="generators"
   
%{
#include <stdio.h>
#include <stdlib.h>

#define YYDEBUG 1
   
int generatorslex();
int generatorsparse();
FILE *generatorsin;


extern void *generators_scan_string(const char *);
extern void generators_delete_buffer(void *);

void generatorserror(const char *s);
#define YYERROR_VERBOSE

%}

%union {
  char *string;
  int integer;
}

%token <string> TOK_STRING
%token <integer> TOK_INTEGER;
%token TOK_COMMA
%token TOK_COLON
%token <string> TOK_PROTOTYPE
%token <string> TOK_WORD
%token <string> TOK_VARIABLE

%start input

%%

input:  /* empty */
        | input prototype
	| input asmcode
	| asmcode
	;


prototype:
        TOK_PROTOTYPE {
	  printf("Prototype content:%s\n", $1);
	}
        ;
asmcode: TOK_WORD TOK_WORD TOK_COMMA TOK_WORD { /* mov ebx, eax */
	  printf("word putting %s into %s\n", $4, $2);
	}
        | TOK_WORD TOK_WORD TOK_COMMA TOK_INTEGER { /* mov ebx, 1 */
	  printf("putting %d into %s\n", $4, $2);
	}
        | TOK_WORD TOK_WORD TOK_COMMA TOK_VARIABLE {
	  /* mov ebx, %__LEN__% */
	  printf("var putting %s into %s\n", $4, $2);
	}
        | TOK_WORD TOK_WORD {
	  printf("Putting %s into %s\n", $2, $1);
	}
        | TOK_WORD {
	  printf("Calling %s\n", $1);
	}
        ;

%%

int michet_parse_generator(char *genfile)
{
  FILE *fp;
  long fsize;
  char *fbuf;
  void *state;

  fp = fopen(genfile, "r");
  fseek(fp, 0, SEEK_END);
  fsize = ftell(fp);
  fseek(fp, 0, SEEK_SET);

  fbuf = malloc(fsize + 1);
  fbuf[fsize+1] = '\0';
  fread(fbuf, fsize, 1, fp);
  
  fclose(fp);

  state = generators_scan_string(fbuf);
  generatorsparse();

  free(fbuf);
  
  return 0;
}

int yylex();

