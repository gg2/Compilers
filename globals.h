
#ifndef GG_120_GLOBALS
#define GG_120_GLOBALS

#include "stack.h"
#include "types.h"
#include "parse_tree.h"
#include "symbols.h"
#include "scopes.h"


// Program control constants
static const short PRINT_PARSE_TREES = 0;
static const short PRINT_SYMBOL_TABLES = 0;
static const short PRINT_TYPE_TABLES = 0;
static const short PRINT_SCOPES = 1;
static const short PRINT_SCOPE_SYMBOL_TABLES = 1;
static const short PRINT_SEMANTIC_IDENTIFIERS = 0;

// Program exit constants
static const short EXIT_NORMAL = 0;
static const short EXIT_ERROR_LEXICAL = 1;
static const short EXIT_ERROR_PARSE = 2;
static const short EXIT_ERROR_SEMANTIC = 3;
static const short EXIT_ERROR_FILE = 4;
static const short EXIT_ERROR_PROGRAM = 5;
static const short EXIT_ERROR_UNKNOWN = 6;

static short program_result_120;

stack *yyfiles;
	int included_iostream;
	int included_fstream;
	int included_string;
	int included_cstdlib;
	int included_ctime;

tree *yyparsetree;

symbol **yysymboltable;

int handling_includes;
int defining_new_type;

#endif /* GG_120_GLOBALS */