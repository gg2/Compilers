/*
 *
 * CS445 Compilers
 * Clinton Jeffery
 * 
 * Gabe Gibler
 * 2017 Oct 15
 * 
 * Run yyparse() from here, 
 * and then perform semantic analysis 
 * for each file provided at the command line,
 * and output the results per assignment instructions.
 *
 */

#ifndef GG_120_MAIN
#define GG_120_MAIN

#include <stdio.h>
#include <stdlib.h>
#include "globals.h"


extern FILE *yyin;
extern int yyparse();
extern void analyze_semantics_1(tree*,ctype**,scope*);


int main(int argc,char **argv);


#endif /* GG_120_MAIN */