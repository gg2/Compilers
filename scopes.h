
#ifndef GG_120_SCOPES
#define GG_120_SCOPES

#include <stdlib.h>
#include <stdio.h>
#include "types.h"
#include "parse_tree.h"
#include "symbols.h"


typedef struct scope_node
{
	char *name;
	ctype *assocd_type;
	tree *scope_root;
	symbol **symbols_in_scope;

	struct scope_node *parent;
	int ct_children;
	struct scope_node* *children;
} scope;


scope* scope_init(tree *root);
int scope_is_empty(scope *root);
scope* scope_generate_node(char *scope_name,ctype *instigator,tree *subtree_root,scope *parent);
symbol** scope_generate_st();
scope* scope_get_scope(scope *root,const char *val);
void scope_print(scope *node,int depth);
void scope_destruct(scope **parent);


#endif /* GG_120_SCOPES */