
#include "scopes.h"


// Initialize with a default global scope and symbol table.
scope* scope_init( tree *root )
{
	scope *global;
	
	global = scope_generate_node( "global", NULL, root, NULL );
	if ( global != NULL )
	{
		return global;
	}
	else
	{
		return NULL;
	}
}


int scope_is_empty( scope *root )
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
//   records which composite type generated it, the root of the subtree for this scope, and
//   the parent scope in which this scope was generated, 
//   then attaches it to the parent scope.
// RETURNS: Pointer to the newly generated scope node, 
//            and the children array of parent increased by 1 with a pointer to this new scope added to it.
scope* scope_generate_node( char *scope_name, ctype *instigator, tree *subtree_root, scope *parent )
{
	scope *node = NULL;
	scope **more_children = NULL;
	int i = 0;
	
	node = ( scope* ) malloc( sizeof( scope ) );
	if ( node != NULL)
	{
		node->name = scope_name;
		node->assocd_type = instigator;
		node->scope_root = subtree_root;
		node->symbols_in_scope = scope_generate_st();
		if ( node->symbols_in_scope == NULL )
		{
			free( node );
			return NULL;
		}
		
		node->ct_children = 0;
		node->children = NULL;
		// Now allocate one more for the parent's array of children
		node->parent = parent;
		// Parent can be null (global scope), so check for that to avoid Seg Faults
		if ( node->parent != NULL )
		{
			++(parent->ct_children);
			more_children = ( scope** ) realloc( (parent->children), sizeof( scope* ) * parent->ct_children );
			if ( more_children != NULL )
			{
				parent->children = more_children;
				parent->children[ (parent->ct_children)-1 ] = node;
			}
			else
			{
				free( node );
				return NULL;
			}
		}

		return node;
	}
	else
	{
		return NULL;
	}
}


// Allocate and initialize a new symbol table for a scope.
symbol** scope_generate_st()
{
	symbol **st;
	
	st = ( symbol** ) malloc( sizeof( symbol* ) * st_size );
	if ( st != NULL )
	{
		st_init( st );
		return st;
	}
	else
	{
		return NULL;
	}
}


// Find a scope by name by searching downwards through all children of the supplied node.
// Searches all children first, before trying children's children.
// Presumes that the supplied node is not the scope you're looking for,
//   otherwise you'd just grab a reference to that scope, 
//   because you already had easy access to it.
// RETURNS: pointer to the first scope encountered with the same name as val.
//            i.e. Complexly nested scopes not really well supported.
//          NULL, if no scope found with that name.
scope* scope_get_scope( scope *root, const char *val )
{
	int i = 0;
	scope *s = NULL;
	
	// Make sure we aren't checking nodes that will encounter Seg Faults
	if ( root->children != NULL )
	{
		// Search through each child for a match
		for ( i=0; i<root->ct_children; ++i )
		{
			if ( strcmp( root->children[i]->name, val ) == 0 )
			{
				s = root->children[i];
				break;
			}
		}
		if ( s == NULL ) // keep looking ...
		{
			for ( i=0; i<root->ct_children; ++i )
			{
				s = scope_get_scope( root->children[i], val );
				if ( s != NULL )
					break;
			}
		}
	}
	
	return s;
}


void scope_print( scope *node, int depth )
{
	int i = 0;

	// Check for and ignore NULL nodes to avoid Seg Faults.
	if ( node != NULL )
	{
		// assocd_type and parent can be NULL, so check for that to avoid Seg Faults
		printf( "%*s :: parent scope: %s ; for type: %s\n", depth*2, node->name, ( node->parent != NULL ) ? node->parent->name : "n/a", ( node->assocd_type != NULL ) ? tt_print_base_name( node->assocd_type->base_type ) : "n/a" );
		
		st_print( node->symbols_in_scope, 1 );
		
		for( i=0; i<node->ct_children; ++i )
		{
			// Check for and ignore NULL nodes to avoid Seg Faults.
			if ( node->children[i] != NULL )
			{
				scope_print( node->children[i], depth + 1 );
			}
		}
	}
}


// Post-order traversal to free all dynamically allocated memory
void scope_destruct( scope **parent )
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
				scope_destruct( &( (*parent)->children[i] ) );
			}
		}
		if ( (*parent)->children != NULL )
		{
			free( (*parent)->children );
		}
		st_destruct( (*parent)->symbols_in_scope );
		(*parent)->symbols_in_scope = NULL;
		free( (*parent) );
		(*parent) = NULL;
	}
}
