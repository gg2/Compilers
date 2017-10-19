
#ifndef GG_120_SYMBOLS
#define GG_120_SYMBOLS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "types.h"
#include "parse_tree.h"


// Size to make these symbol tables.
// Best if a prime.
static const size_t st_size = 1021;

typedef struct symbol
{
	char *id;
	ctype *type;
	int by_ref;
	int class_private;
	int constant;
	int staticity;
	int declared;
	int defined;
	tree *declaring_node;
	
	// Used for pre-semantics in Flex.
	// Use it for whatever you like.
	union
	{
		char *t_val;
		int i_val;
	} temp;
	
	struct symbol *next;
} symbol;


void st_init(symbol **st_table);
size_t st_count_at(symbol **st_table,int index);
symbol* st_insert(symbol **st_table,const char* val,ctype* type);
symbol* st_find(symbol **st_table,const char* val);
ctype* st_get_type(symbol **st_table,const char* val);
void st_print(symbol **st_table,int opts);
void st_destruct(symbol **st_table);
int st_hash(const char* val);


#endif /* GG_120_SYMBOLS */