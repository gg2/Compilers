
#include "stack.h"


// I feel that all of these are pretty self-evident, 
//   if one has the general idea what stacks do.
void stack_init( stack **head )
{
	(*head) = NULL;
}


int stack_is_empty( stack *head )
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


int stack_push( stack **head, char *val, FILE *fptr, int ln )
{
	size_t length = strlen( val );
	
	stack *n = ( stack* ) malloc( sizeof( stack ) );
	if ( n != NULL )
	{
		n->filename =  ( char* ) malloc( sizeof( char ) * ( length + 1 ) );
		if ( n->filename != NULL )
		{
			strncpy( n->filename, val, length );
			(n->filename)[length] = '\0';
			n->file_ptr = fptr;

			n->line_num = ln;
			n->included_iostream = 0;
			n->included_fstream = 0;
			n->included_string = 0;
			n->included_cstdlib = 0;
			n->included_ctime = 0;
			n->included_cmath = 0;
			n->w_include = 1;
			n->w_preprocdirective = 1;
			n->w_numberformats = 1;
			n->w_digraphs = 1;

			n->next = (*head);
			(*head) = n;
			
			return 0;
		}
		else
		{
			free( n );
			return 1;
		}
	}
	else
	{
		return 1;
	}
}


void stack_pop( stack **head )
{
	stack *n = NULL;
	
	if ( (*head) != NULL )
	{
		n = (*head);
		(*head) = n->next;
		
		free( n->filename );
		free( n );
	}
}


void stack_destruct( stack **head )
{
	while ( !stack_is_empty( (*head) ) )
	{
		stack_pop( head );
	}
}
