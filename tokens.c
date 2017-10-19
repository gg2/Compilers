
#include "tokens.h"


// Initialize all values for the token list.
void tl_init( t_node **head )
{
	(*head) = NULL;
}


int tl_is_empty( t_node *head ) 
{
	if ( head == NULL ) 
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


int tl_size( t_node *head ) 
{
	t_node *n = head;
	int ct = 0;
	
	while ( n != NULL ) 
	{
		++ct;
		n = n->next;
	}
	
	return ct;
}


// Appends to the end
// If there were problems allocating space, the node's token* should be null.
token* tl_insert( t_node **head ) 
{
	t_node *n = (*head);
	t_node *e = n;
	
	while ( n != NULL )
	{
		e = n;
		n = n->next;
	}
	
	// Allocate at n
	n = ( t_node* ) malloc( sizeof( t_node ) );
	if ( n != NULL )
	{
		n->t = ( token* ) malloc( sizeof( token ) );
		if ( n->t != NULL )
		{
			// Update all next pointers appropriately
			n->next = NULL;
			
			if ( (*head) == NULL )
			{
				(*head) = n;
			}
			else
			{
				e->next = n;
			}
		}
		else
		{
			free( n );
			n = NULL;
			return NULL;
		}
		
		return n->t;
	}
	else
	{
		return NULL;
	}
}


t_node* tl_end( t_node *head ) 
{
	t_node *n = head;
	t_node *e = n;
	
	while ( n != NULL )
	{
		e = n;
		n = n->next;
	}
	
	return e;
}


void tl_print( t_node *head )
{
	t_node *n = head;
	
	printf( "%-16s  %-6s  %-8s  %-25s  %-25s\n\n", "Filename", "Line #", "Category", "Token", "iVal/sVal" );
	printf( "----------------------------------------------------------------------------------------------\n" );
	while ( n != NULL )
	{
		printf( "%-16s  %-6d  %-8d  %-25s  ", n->t->filename, n->t->lineno, n->t->category, n->t->text );
		if ( n->t->category == CONST_BOOL || n->t->category == CONST_INT )
		{
			printf( "%-25d\n", n->t->ival );
		}
		else if ( n->t->category == CONST_FLOAT )
		{
			printf( "%-25g\n", n->t->rval );
		}
		else if ( n->t->category == CONST_CHAR || n->t->category == STRING )
		{
			printf( "%-25s\n", n->t->sval );
		}
		else
		{
			printf( "%-25s\n", "" );
		}
		n = n->next;
	}
}


void tl_destruct( t_node **head ) 
{
	t_node *n = (*head);
	
	while ( (*head) != NULL )
	{
		n = (*head)->next;
		if ( (*head)->t->sval != NULL )
			free( (*head)->t->sval );
		free( (*head)->t->text );
		free( (*head)->t->filename );
		free( (*head)->t );
		free( (*head) );
		(*head) = n;
	}
}
