
#include "parse_tree.h"


// Initialize all values for the token list.
void pt_init( tree **root )
{
	(*root) = NULL;
}


int pt_is_empty( tree *root ) 
{
	if ( root == NULL ) 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


// Generates a new node, 
//   records which production rule it was a part of, and
//   attaches to it all other nodes that were generated up to recognizing that rule.
// Accepts any number of nodes to insert as children of this new node.
// RETURNS: pointer to the newly generated node.
tree* pt_generate_node( const int productionrule_number, const char *productionrule_name, const int n_children, ... )
{
	tree *node = NULL;
	va_list va_args;
	int i = 0;
	
	node = ( tree* ) malloc( sizeof( tree ) );
	if ( node != NULL)
	{
		node->production = productionrule_number;
		node->prod_label = productionrule_name;
		node->ct_children = n_children;
		node->t = NULL;
		
		// Allocate space for the "array" of child nodes.
		node->children = ( tree** ) malloc( sizeof( tree* ) * n_children );
		// Acquire and run through the variably-sized list of nodes provided to this function.
		// These are the children of the new node generated by this function.
		if ( node->children != NULL )
		{
			va_start( va_args, n_children );
			for ( i=0; i<node->ct_children; ++i )
			{
				node->children[i] = va_arg( va_args, tree* );
			}
			va_end( va_args );
		
			return node;
		}
		else
		{
			free( node );
			node = NULL;
			return NULL;
		}
	}
	else
	{
		return NULL;
	}
}


// Search through the children of root for a node with production == productionrule_number
// Presumes that root does not match the target production,
//   otherwise, you'd just grab root, because you already have direct access to it.
// Options: range == 0, productionrule_number must match exactly.
//          range > 0, productionrule_number must be within the range  
//                     productionrule_number <--> productionrule_number + range.
//          range < 0, you get nothing.
// RETURNS: pointer to the first node found with a production matching productionrule_number
//          NULL, if no node found with such a production.
tree* pt_get_child( tree *root, const int productionrule_number, int range )
{
	tree *t_f = NULL;
	int i = 0;
	
	if ( root != NULL )
	{
		for ( i=0; i<root->ct_children; ++i )
		{
			if ( root->children[i] != NULL )
			{
				if ( root->children[i]->production >= productionrule_number && 
						 root->children[i]->production <= productionrule_number + range
					 )
				{
					t_f = root->children[i];
					break;
				}
				else
				{
					t_f = pt_get_child( root->children[i], productionrule_number, range );
					if ( t_f != NULL )
						break;
				}
			}
		}
	}
	
	return t_f;
}


void pt_print( tree *node, int depth )
{
	int i = 0;

	// Check for and ignore NULL epsilon nodes to avoid Seg Faults.
	if ( node != NULL )
	{
		printf( "%*i (%s): %d: %s %s\n", depth*2, node->production, node->prod_label, node->ct_children, node->ct_children == 0 ? node->t->filename : "", node->ct_children == 0 ? node->t->text : "" );
	
		for( i=0; i<node->ct_children; ++i )
		{
			// Check for and ignore NULL epsilon nodes to avoid Seg Faults.
			if ( node->children[i] != NULL )
			{
				pt_print( node->children[i], depth + 1 );
			}
		}
	}
}


// Post-order traversal to free all dynamically allocated memory
	// !!! Has some sort of memory problem with uninitialized values. 
	//       No idea what those would be, though.
	//       Can make it happen by parsing C.cpp. 
	//       It shows up when freeing class B, somewhere while attempting to free members of the B token.
	//       Started showing up as a result of adding in type definition handling in 120++lex.l,
	//       --> the switch statement that checks identifiers,
	//       but could be entirely unrelated, because adding those may have been what made it evident
	//       (able to parse far enough to show the problem).
void pt_destruct( tree **parent ) 
{
	int i = 0;
	
	// Check for and ignore NULL epsilon nodes to avoid Seg Faults.
	if ( (*parent) != NULL )
	{
		for( i=0; i<(*parent)->ct_children; ++i )
		{
			// Check for and ignore NULL epsilon nodes to avoid Seg Faults.
			if ( (*parent)->children[i] != NULL )
			{
				pt_destruct( &( (*parent)->children[i] ) );
			}
		}
		if ( (*parent)->children != NULL )
		{
			free( (*parent)->children );
		}
		
		if ( (*parent)->t != NULL )
		{
			if ( (*parent)->t->sval != NULL )
			{
				free( (*parent)->t->sval );
			}
			free( (*parent)->t->text );
			free( (*parent)->t->filename );
			free( (*parent)->t );
		}
		free( (*parent) );
		(*parent) = NULL;
	}
}
