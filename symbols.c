
#include "symbols.h"


// Initialize each slot of the symbol table.
void st_init( symbol **st_table )
{
	int i = 0;
	
	if ( st_table != NULL )
	{
		for ( i=0; i<st_size; ++i )
		{
			st_table[i] = NULL;
		}
	}
}


// RETURNS: the count of items at that index, 
//            if an index for the table is given.
//          total count of all items in the table, 
//            if an index of -1 or an otherwise invalid index is given.
size_t st_count_at( symbol **st_table, int index )
{
	int i = 0;
	size_t total = 0;
	symbol *n = NULL;
	
	if ( index > -1 && index < st_size )
	{
		n = st_table[index];
		
		while ( n != NULL )
		{
			++total;
			n = n->next;
		}
	}
	else
	{
		for( i=0; i<st_size; ++i )
		{
			n = st_table[i];
			
			while ( n != NULL )
			{
				++total;
				n = n->next;
			}
		}
	}

	return total;
}


// Insert a new symbol at an index of the hash table, 
//    where its index is determined by the hash function.
// RETURNS: pointer to the newly inserted symbol, if none found,
//          pointer to an existing symbol, if one found with the same name as val,
//          NULL, if new symbol could not be allocated.
symbol* st_insert( symbol **st_table, const char* val, ctype* type )
{
	symbol *existing_sym = st_find( st_table, val );
	int key = -1;
	symbol *n = NULL;
	symbol *e = NULL;
	
	// Check that the supplied symbol hasn't already been inserted
	if ( existing_sym == NULL )
	{
		key = st_hash( val );
		
		n = st_table[key];
		e = n;
		
		while ( n != NULL )
		{
			e = n;
			n = n->next;
		}
		
		// Allocate at n
		n = ( symbol* ) malloc( sizeof( symbol ) );
		if ( n != NULL )
		{
			n->id = ( char* ) malloc( sizeof( char ) * ( strlen( val ) + 1 ) );
			if ( n->id == NULL )
			{
				free( n );
				n = NULL;
				return NULL;
			}
			else
			{
				// Fill in new symbol's value and type et al
				strcpy( n->id, val );
				n->type = type;
				n->temp.i_val = 0;
				n->by_ref = 0;
				n->class_private = 0;
				n->constant = 0;
				n->staticity = 0;
				n->declared = 0;
				n->defined = 0;
				n->declaring_node = NULL;

				// Update all next pointers appropriately
				n->next = NULL;
				
				if ( st_table[key] == NULL )
				{
					st_table[key] = n;
				}
				else
				{
					e->next = n;
				}
			}
			
			return n;
		}
		else
		{
			return NULL;
		}
	}
	// The supplied symbol has already been inserted,
	//    so return a reference to it.
	else
	{
		return existing_sym;
	}
}


// Receives a string
// RETURNS: pointer to the string in the table, 
//            if the string exists in the table.
//          NULL, if the string does not exist in the table.
symbol* st_find( symbol **st_table, const char* val )
{
	int key = st_hash( val ), found = 1;
	symbol *n = NULL;
	
	if ( st_table != NULL )
	{
		n = st_table[key];
		
		while ( n != NULL && found != 0 )
		{
			found = strcmp( val, n->id );
			if ( found != 0 )
				n = n->next;
		}
	}
	
	if ( found == 0 )
		return n;
	else
		return NULL;
}


ctype* st_get_type( symbol **st_table, const char* val )
{
	int key = st_hash( val ), found = 1;
	symbol *n = NULL;

	if ( st_table != NULL )
	{
		n = st_table[key];
	
		while ( n != NULL && found != 0 )
		{
			found = strcmp( val, n->id );
			if ( found != 0 )
				n = n->next;
		}
	}
	
	if ( found == 0 )
		return n->type;
	else
		return NULL;
}


// Prints the name of the symbol
// Prints the type code if opts == 1
void st_print( symbol **st_table, int opts )
{
	symbol *n = NULL;
	int i = 0;
	
	if ( st_table != NULL )
	{
		for ( i=0; i<st_size; ++i )
		{
			n = st_table[i];
			while ( n != NULL )
			{
				printf( "%s", n->id );
				if ( opts == 1 && n->type != NULL )
				{
					printf( " ; type: " );
					tt_print_depth( n->type );
				}
				printf( "\n" );
				n = n->next;
			}
		}
		printf( "\n" );
	}
}


void st_destruct( symbol **st_table )
{
	symbol *n = NULL;
	int i = 0;
	
	if ( st_table != NULL )
	{
		for ( i=0; i<st_size; ++i )
		{
			while ( st_table[i] != NULL )
			{
				n = st_table[i]->next;
				if ( st_table[i]->id != NULL )
					free( st_table[i]->id );
				free( st_table[i] );
				st_table[i] = n;
			}
		}
	}
}


// The hash function
/*
Based loosely on hash methods from:
https://www.cs.hmc.edu/~geoff/classes/hmc.cs070.200101/homework10/hashfuncs.html
"
The following functions map a single integer key (k) to a small integer bucket value h(k). 
m is the size of the hash table (number of buckets).
...
Knuth Variant on Division h(k) = k(k+3) mod m. 
"
*/
int st_hash( const char* val )
{
	int k1 = (int)( *val );
	int k2 = (int)( val[ strlen(val) - 1 ] );
	
	return ( k1 * ( k2 + 3 ) ) % st_size;
}
