
#ifndef GG_120_SYNTAX_TREE
#define GG_120_SYNTAX_TREE

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>


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

typedef struct pt_node
{
	int production;
	const char *prod_label;
	int ct_children;
	struct pt_node* *children;
	token *t;
} tree;

// Hash table in semantic_analysis context to store references between semantic attributes and tree nodes, 
//   based on address of tree*,
//   to keep parse_tree uncomplicated by semantic_analysis properties.

void pt_init(tree **root);
int pt_is_empty(tree *root);
tree* pt_generate_node(const int productionrule_number,const char *productionrule_name,const int n_children,...);
tree* pt_get_child(tree *root,const int productionrule_number,int range);
void pt_print(tree *node,int depth);
void pt_destruct(tree **parent);


#endif /* GG_120_SYNTAX_TREE */