
#ifndef GG_120_SEMANTICS
#define GG_120_SEMANTICS

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "120++nonterms.h"
#include "globals.h"
#include "120++parse.tab.h"


static scope *global_scope;
static scope *current_scope;
static ctype **typetable;

static int parameter_count;
static struct param **parameters;
static struct field **struct_fields;


int analyze_semantics_1(tree *parsetree,ctype **types,scope *scopetree);
void pre_order_traversal(tree *dryad,int depth);
int post_order_traversal(tree *dryad,int depth);
int traversal_1(tree *dryad,int depth);
scope* switch_scope_on_declarator(tree *t);
void resolve_members_in_scope( tree* dryad );
scope* resolve_scope_of_class( symbol* symbol_temp );
symbol* add_symbol_to_table(char *id,int line_num);
ctype* assemble_type(tree *t);
char* get_unqualified_id(tree *t);
char* get_id_from_direct_declarator(tree *t);
void prepare_parameter_list();
void handle_semantic_warning(char *msg,char *id,int type,int line_num);
int handle_semantic_error(char *msg,int type,int line_num);


#endif /* GG_120_SEMANTICS */