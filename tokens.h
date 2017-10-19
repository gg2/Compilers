
#ifndef GG_120_TOKENS
#define GG_120_TOKENS

#include <stdlib.h>
#include <stdio.h>
#include "120++defs.h"


typedef struct token 
{
	char *filename; /* the source file in which the token occurs */
	int lineno;     /* the line number on which the token occurs */
	int category;   /* the integer code returned by yylex */
	char *text;     /* the actual string (lexeme) matched */
	int ival;       /* if you had an integer constant, store its value here */
	double rval;			/* if you had a float constant, store its value here */
	char *sval;     /* if you had a string constant, malloc space and store */
                  /*    the string (less quotes and after escapes) here */
} token;

typedef struct t_node
{
	token *t;
	struct t_node *next;
} t_node;

void tl_init(t_node **head);
int tl_is_empty(t_node *head);
int tl_size(t_node *head);
token* tl_insert(t_node **head);
t_node* tl_end(t_node *head);
void tl_print(t_node *head);
void tl_destruct(t_node **head);

#endif /* GG_120_TOKENS */