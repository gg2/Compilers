
#include "types.h"


// Initialize all values for the type table.
// Must distinguish what to initialize based on type.
//   i.e. Initializes a struct for each simple base type.
// RETURNS: NULL, if malloc failed, 
//          Otherwise, a pointer to a ready type table.
ctype** tt_init( ctype **tt_table )
{
	short i = 0;
	
	if ( tt_table != NULL )
	{
		// Insert initial entries for base types,
		// Then NULL for types that must be specialized.
		for ( i=0; i<t_ARRAY; ++i )
		{
			tt_table[i] = ( ctype* ) malloc( sizeof( ctype ) );
			if ( tt_table[i] != NULL )
			{
				tt_table[i]->base_type = i;
				tt_table[i]->next = NULL;
			}
			else
			{
				while( i > 0 )
				{
					free( tt_table[--i] );
				}
				return NULL;
			}
		}
		for ( i=t_ARRAY; i<tt_size; ++i )
		{
			tt_table[i] = NULL;
		}
	}
	
	return tt_table;
}


// RETURNS: count of items at an index, if an index for the table is given.
//          total count of all items in the table, 
//            if an index of -1 or an otherwise invalid index is given.
size_t tt_count_at( ctype **tt_table, int index )
{
	int i = 0;
	size_t total = 0;
	ctype *n = NULL;
	
	if ( index > -1 && index < tt_size )
	{
		n = tt_table[index];
		
		while ( n != NULL )
		{
			++total;
			n = n->next;
		}
	}
	else
	{
		for( i=0; i<tt_size; ++i )
		{
			n = tt_table[i];
			
			while ( n != NULL )
			{
				++total;
				n = n->next;
			}
		}
	}

	return total;
}


// Insert a new type into the table, 
//   where its index is determined by the base type being used.
// For complex or composite types, the details are to be filled in
//   afterwards, using the returned pointer to the new type's struct.
// If one is concerned about not duplicating types,
//   then one must use one of the check_type functions below beforehand,
//   because I don't feel like sorting out a shit-ton of possible things to send to this function
//   nor do I want to create a bunch of type-specific functions for allocating each type.
// RETURNS: pointer to newly inserted type
//          NULL, if new type could not be allocated
ctype* tt_insert( ctype **tt_table, const short base_index )
{
	ctype *n = NULL;
	ctype *e = NULL;
	
	n = tt_table[base_index];
	e = n;
	
	while ( n != NULL )
	{
		e = n;
		n = n->next;
	}
	
	// Allocate at n
	n = ( ctype* ) malloc( sizeof( ctype ) );
	if ( n != NULL )
	{
		n->base_type = base_index;
		
		// Update all next pointers appropriately
		n->next = NULL;
		
		if ( tt_table[base_index] == NULL )
		{
			tt_table[base_index] = n;
		}
		else
		{
			e->next = n;
		}
		
		return n;
	}
	else
	{
		return NULL;
	}
}


// Functions to check for existence of specific composite or complex types.
// RETURNS: pointer to the type's only struct, for the basic type getter.
//          NULL, if asking for anything other than a basic type.
ctype* tt_get_type_basic( ctype **tt_table, const short base_index )
{
	if ( tt_table != NULL && ( base_index > -1 && base_index < t_ARRAY ) )
	{
		return tt_table[base_index];
	}
	else
	{
		return NULL;
	}
}
//!!! Yet to make other type getters. Not sure it's necessary.
//    But, I did make a type comparison function, so this should be do-able now!


// Compares the two supplied types.
// ! Works directly with its parameters, so do not pass in by reference.
// RETURNS: 0, if they do not match
//          1, if they match, but the name of params for func t2 are empty or named 
//                                                      while t1 always has names
//          2, if they match, but the name of params for func t1 are empty or named 
//                                                      while t2 always has names
//          3, if they match on types, but names of struct fields differ
//          4, if they match 100%
int tt_compare_types( ctype *t1, ctype *t2 )
{
	int result = 4, cmp_tmp = 0, param_tmp = 4, i = 0;
	struct field **f1, **f2;
	struct param **p1, **p2;
	
	while ( result > 0 && t1 != NULL && t2 != NULL )
	{
		// Compare base_type to begin with, no point if that doesn't at least match.
		if ( t1->base_type != t2->base_type )
			result = 0;
		else
		{
			// Compare arrays
			if ( t1->base_type == t_ARRAY )
			{
				if ( t1->u.array.size != t2->u.array.size )
					result = 0;
				t1 = t1->u.array.of; t2 = t2->u.array.of;
				if ( ( t1 == NULL && t2 != NULL ) || ( t1 != NULL && t2 == NULL ) )
					result = 0;
			}
			// Compare pointers
			else if ( t1->base_type == t_POINTER )
			{
				t1 = t1->u.ptr; t2 = t2->u.ptr;
				if ( ( t1 == NULL && t2 != NULL ) || ( t1 != NULL && t2 == NULL ) )
					result = 0;
			}
			else
			{
				// Compare structs
				if ( t1->base_type == t_STRUCT )
				{
					if ( strcmp( t1->u.strct.label, t2->u.strct.label ) != 0 )
						result = 3;
					if ( t1->u.strct.ct_fields != t2->u.strct.ct_fields )
						result = 0;
					if ( result > 0 )
					{
						// Compare struct fields
						f1 = t1->u.strct.fields; f2 = t2->u.strct.fields;
						if ( ( f1 == NULL && f2 != NULL ) || ( f1 != NULL && f2 == NULL ) )
							result = 0;
						else
						{
							for ( i=0; result > 0 && i < t1->u.strct.ct_fields; ++i )
							{
								cmp_tmp = tt_compare_types( f1[i]->type, f2[i]->type );
								if ( cmp_tmp < result )
									result = cmp_tmp;
								if ( result > 3 )
								{
									if ( strcmp( f1[i]->name, f2[i]->name ) != 0 )
										result = 3; 
								}
							}
						}
					}
				}
				// Compare functions
				else if ( t1->base_type == t_FUNC )
				{
					cmp_tmp = tt_compare_types( t1->u.func.return_type, t2->u.func.return_type );
					if (cmp_tmp < result )
						result = cmp_tmp;
					if ( strcmp( t1->u.func.func_name, t2->u.func.func_name ) != 0 )
						result = 0;
					if ( t1->u.func.ct_params != t2->u.func.ct_params )
						result = 0;
					if ( result > 0 )
					{
						// Compare function parameters
						p1 = t1->u.func.params; p2 = t2->u.func.params;
						if ( ( p1 == NULL && p2 != NULL ) || ( p1 != NULL && p2 == NULL ) )
							result = 0;
						else
						{
							for ( i=0; result > 0 && i < t1->u.func.ct_params; ++i )
							{
								cmp_tmp = tt_compare_types( p1[i]->type, p2[i]->type );
								if ( cmp_tmp < result )
									result = cmp_tmp;
								if ( result > 0 )
								{
									// Don't bother comparing if both are NULL; that changes nothing.
									if ( !( p1[i]->name == NULL && p2[i]->name == NULL ) )
									{
										if ( p1[i]->name != NULL && p2[i]->name != NULL )
										{
											// mixtures of results == types do not match
											if ( strcmp( p1[i]->name, p2[i]->name ) != 0 )
												param_tmp = 0;
										}
										else
										{
											if ( p1[i]->name == NULL && p2[i]->name != NULL )
											{
												// param_tmp == 2 should remain unchanged
												// mixture of results == types do not match
												//   (Some named on both, but unnamed only on t1 should be fine.)
												if ( param_tmp == 4 )
													param_tmp = 2;
												if ( param_tmp == 1 )
													param_tmp = 0;
											}
											else if ( p1[i]->name != NULL && p2[i]->name == NULL )
											{
												// param_tmp == 1 should remain unchanged
												// mixture of results == types do not match
												//   (Some named on both, but unnamed only on t2 should be fine.)
												if ( param_tmp == 4 )
													param_tmp = 1;
												if ( param_tmp == 2 )
													param_tmp = 0;
											}
										}
										// Collate results
										if ( param_tmp < 3 )
											result = param_tmp;
									}
								}
							}
						}
					}
				}
				// Compare classes
				else if ( t1->base_type == t_CLASS )
				{
					if ( strcmp( t1->u.clss.clss_name, t2->u.clss.clss_name ) != 0 )
						result = 0;
				}
				// Compare miscellaneous
				else if ( t1->base_type == t_MISC )
				{
					if ( strcmp( t1->u.misc.name_of_type, t2->u.misc.name_of_type ) != 0 )
						result = 0;
				}
				// Structs, classes, and simple types are the end of the line
				t1 = NULL; t2 = NULL;
			}
		}
	}
}


// Prints the properties of each type stored away in the table.
// Must distinguish what to print based on type.
void tt_print( ctype **tt_table )
{
	ctype *n = NULL;
	int i = 0;
	
	if ( tt_table != NULL )
	{
		for ( i=0; i<tt_size; ++i )
		{
			n = tt_table[i];
			// Cycle through each struct, class, or pointer that has been entered into the type table.
			// (There should only be one node for each of the simple types.)
			while ( n != NULL )
			{
				printf( "%i : %s", ( int )n->base_type, tt_print_base_name( i ) );
				
				if      ( i == t_ARRAY )
				{
					printf( " of %i ", n->u.array.size );
					tt_print_depth( n->u.array.of );
				}
				else if ( i == t_STRUCT )
					printf( " %s", n->u.strct.label );
				else if ( i == t_FUNC )
				{
					printf( " " );
					tt_print_function_signature( n );
				}
				else if ( i == t_CLASS )
					printf( " %s", n->u.clss.clss_name );
				else if ( i == t_POINTER )
				{
					printf( " to " );
					tt_print_depth( n->u.ptr );
				}
				else if ( i == t_MISC )
				{
					printf( " %s", n->u.misc.name_of_type );
				}
				printf( "\n" );
				n = n->next;
			}
		}
		printf( "\n" );
	}
}


// Cycle through each layer of an ARRAY or POINTER.
// Useful for printing the complete description of any composite type.
	// Did not arrange the following as a switch statement
	//   so that I could use the constant enumerators 
	//   rather than hard-coded constants.
void tt_print_depth( ctype *n )
{
	while ( n != NULL )
	{
		printf( "%s", tt_print_base_name( n->base_type ) );
		// Array of arrays
		if ( n->base_type == t_ARRAY )
		{
			printf( " of %i ", n->u.array.size );
			n = n->u.array.of;
		}
		// Array of pointers to ...
		else if ( n->base_type == t_POINTER )
		{
			printf( " to " );
			n = n->u.ptr;
		}
		else
		{
			// Array of struct X
			if ( n->base_type == t_STRUCT )
			{
				printf( " %s", n->u.strct.label );
			}
			// Array of func X
			else if ( n->base_type == t_FUNC )
			{
				printf( " " );
				tt_print_function_signature( n );
			}
			// Array of class X
			else if ( n->base_type == t_CLASS )
			{
				printf( " %s", n->u.clss.clss_name );
			}
			else if ( n->base_type == t_MISC )
			{
				printf( " %s", n->u.misc.name_of_type );
			}
			// Structs, classes, and simple types are the end of the line
			n = NULL;
		}
	}
}


// RETURNS: the human-readable, textual name of the basic types.
	// Did not arrange the following as a switch statement
	//   so that I could use the constant enumerators 
	//   rather than hard-coded constants.
const char* tt_print_base_name( short t_type )
{
	if      ( t_type == t_VOID )
		return( "VOID" );
	else if ( t_type == t_BOOL )
		return( "BOOL" );
	else if ( t_type == t_CHAR )
		return( "CHAR" );
	else if ( t_type == t_INT || t_type == t_SHORT || t_type == t_LONG )
		return( "INT" );
	else if ( t_type == t_DOUBLE || t_type == t_FLOAT )
		return( "DOUBLE" );
	else if ( t_type == t_ARRAY )
		return( "ARRAY" );
	else if ( t_type == t_STRUCT )
		return( "STRUCT" );
	else if ( t_type == t_FUNC )
		return( "FUNCTION" );
	else if ( t_type == t_CLASS )
		return( "CLASS" );
	else if ( t_type == t_POINTER )
		return( "POINTER" );
	else if ( t_type == t_MISC )
		return( "MISCELLANEOUS" );
	else
		return( "UNDEFINED" );
}


//  Print out the representation of a function's signature.
void tt_print_function_signature( ctype *f )
{
	int i = 0;
	
	tt_print_depth( f->u.func.return_type );
	printf( " %s ( ", f->u.func.func_name );
	for ( i=0; i<f->u.func.ct_params; ++i )
	{
		if ( i > 0 )
			printf( ", " );
		tt_print_depth( (f->u.func.params)[i]->type );
		printf( " %s", (f->u.func.params)[i]->name );
	}
	printf( " ) " );
}


// Must distinguish what to destroy based on type.
void tt_destruct( ctype **tt_table )
{
	ctype *n = NULL;
	int i = 0;
	
	if ( tt_table != NULL )
	{
		for ( i=0; i<tt_size; ++i )
		{
			while ( tt_table[i] != NULL )
			{
				n = tt_table[i]->next;
				// Not worrying about deleting all the grand variety of things 
				//   that might be saved for each type. Not worth it here.
				free( tt_table[i] );
				tt_table[i] = n;
			}
		}
	}
}
