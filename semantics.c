
#include "semantics.h"


int analyze_semantics_1( tree *parsetree, ctype **types, scope *scopetree )
{
	global_scope = scopetree;
	current_scope = scopetree;
	typetable = types;
	
	//pre_order_traversal( parsetree, 0 );
	traversal_1( parsetree, 0 );
	if ( program_result_120 == EXIT_NORMAL )
	{
		
	}

	return program_result_120;
}


// Post-order traversal
int post_order_traversal( tree *dryad, int depth )
{
	int i = 0;
	
	if ( dryad != NULL )
	{
		for ( i=0; i<dryad->ct_children; ++i )
		{
			// Check for and ignore NULL epsilon nodes to avoid Seg Faults.
			if ( dryad->children[i] != NULL )
			{
				post_order_traversal( dryad->children[i], depth+1 );
			}
		}
		if ( dryad->t != NULL )
		{
			printf( "%*s%-s\n", depth, "", dryad->t->text );
		}
		else
		{
			printf( "%*s%-s\n", depth, "", dryad->prod_label );
		}
	}

	return program_result_120;
}


// Pre-order traversal
void pre_order_traversal( tree *dryad, int depth )
{
	int i = 0;
	
	if ( dryad != NULL )
	{
		if ( dryad->t != NULL )
		{
			printf( "%*s%-s\n", depth, "", dryad->t->text );
		}
		else
		{
			printf( "%*s%-s\n", depth, "", dryad->prod_label );
		}
		for ( i=0; i<dryad->ct_children; ++i )
		{
			// Check for and ignore NULL epsilon nodes to avoid Seg Faults.
			if ( dryad->children[i] != NULL )
			{
				pre_order_traversal( dryad->children[i], depth+1 );
			}
		}
	}
}


// Creating scopes and populating symbol tables.
int traversal_1( tree *dryad, int depth )
{
	int i = 0;
	int skip_traversals = 0;
	tree *pt_temp = NULL;
	scope *scope_temp = NULL;
	scope *original_scope = NULL;
	symbol *symbol_temp = NULL;
	ctype *type_temp = NULL;
	char *name_temp = NULL;
	
	if ( dryad != NULL )
	{
		/* SECTION: Operations to perform on terminals (leaf nodes)
		  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
		if ( dryad->children == NULL || dryad->ct_children == 0 )
		{
			if ( dryad->t != NULL )
			{
				if ( dryad->production == identifier || dryad->production == class_name || dryad->production == original_namespace_name )
				{
					// Get symbol
					name_temp = dryad->t->text;
					
					// Add to symbol table or give warning if redeclaring
					symbol_temp = st_find( current_scope->symbols_in_scope, name_temp );
					if ( symbol_temp == NULL )
					{
						// Assign a void type initially
						type_temp = tt_get_type_basic( typetable, t_VOID );
						symbol_temp = st_insert( current_scope->symbols_in_scope, name_temp, type_temp );
						if ( symbol_temp == NULL )
							return handle_semantic_error( "Failed to allocate memory for a symbol for a class.", 2, dryad->t->lineno );
					}

					if ( PRINT_SEMANTIC_IDENTIFIERS )
						printf( "%*s%-s\n", depth, "", dryad->t->text );
				}
			}
		}
		/* END: Terminal operations
		  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
		  
		/* SECTION: Operations to perform on non-terminals
		  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
		else
		{
			/* SUBSECTION: Operations to perform when entering a subtree
		    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
			if ( dryad->production == class_specifier || ( dryad->production >= function_definition+1 && dryad->production <= function_definition+2 ) )
			{
				// Check for direct_declarator_7|8; if found, change scope to appropriate class scope
				pt_temp = pt_get_child( dryad, direct_declarator+7, 1 );
				if ( pt_temp != NULL && pt_temp->children != NULL && pt_temp->children[0]->t != NULL )
				{
					original_scope = current_scope;
					current_scope = scope_get_scope( global_scope, pt_temp->children[0]->t->text );
					if ( current_scope == NULL )
					{
						current_scope = original_scope;
						handle_semantic_warning( "Class or namespace is undeclared.", pt_temp->children[0]->t->text, 2, pt_temp->children[0]->t->lineno );
					}
					pt_temp = NULL;
				}
				// Generate new scope for this class or function and change scope.
				// name and type are both NULL at this point, 
				//   to be filled in as children are traversed.
				current_scope = scope_generate_node( NULL, NULL, dryad, current_scope );
			}
			
			if ( dryad->production == class_head+1 )
			{
				// Define new class type
				type_temp = tt_insert( typetable, t_CLASS );
				if ( type_temp == NULL )
					return handle_semantic_error( "Failed to allocate memory for the type for a class.", 2, dryad->children[0]->t->lineno );
				
				// Gather info for new type, for scope, and for class identifier in symbol table
				name_temp = dryad->children[1]->t->text;

				// Assign class name to new type
				type_temp->u.clss.clss_name = name_temp;
				// Assign class name and type to class's scope
				current_scope->name = name_temp;
				current_scope->assocd_type = type_temp;
				
				// Add to parent scope's symbol table or give warning if redeclaring
				symbol_temp = st_find( current_scope->parent->symbols_in_scope, name_temp );
				if ( symbol_temp != NULL && symbol_temp->defined == 1 )
				{
					handle_semantic_warning( "Redeclaring class within scope.", name_temp, 2, -1 );
				}
				else
				{
					// Add to symbol table of class scope's parent (not to symbol table for class itself)
					symbol_temp = st_insert( current_scope->parent->symbols_in_scope, name_temp, type_temp );
					if ( symbol_temp == NULL )
						return handle_semantic_error( "Failed to allocate memory for the symbol for a class.", 2, dryad->children[0]->t->lineno );
					symbol_temp->declaring_node = dryad;
					symbol_temp->declared = 1;
					symbol_temp->defined = 1;
				}

				skip_traversals = dryad->ct_children;
			}
			
			if ( dryad->production == function_definition+1 )
			{
				// Grab function name for general usage, and finish filling out scope name
				name_temp = get_id_from_direct_declarator( dryad->children[0] );
				current_scope->name = name_temp;
				
				// This function definition has no return type
				//   though it might actually need to return the class type ...
				type_temp = tt_insert( typetable, t_FUNC );
				if ( type_temp == NULL )
					return handle_semantic_error( "Failed to allocate memory for the type for a function.", 2, -1 );
				type_temp->u.func.func_name = name_temp;
				type_temp->u.func.return_type = tt_get_type_basic( typetable, t_VOID );
				
				// Add to parent scope's symbol table or give warning if already defined
				symbol_temp = st_find( current_scope->parent->symbols_in_scope, name_temp );
				if ( symbol_temp != NULL && symbol_temp->defined == 1 )
				{
					handle_semantic_warning( "Redefining function within scope.", name_temp, 2, -1 );
				}
				else
				{
					// Add to symbol table of function scope's parent (not to symbol table for function itself)
					symbol_temp = st_insert( current_scope->parent->symbols_in_scope, name_temp, type_temp );
					if ( symbol_temp == NULL )
						return handle_semantic_error( "Failed to allocate memory for the symbol for a function.", 2, -1 );
					symbol_temp->declaring_node = dryad;
					symbol_temp->declared = 1;
					symbol_temp->defined = 1;
				}				
				
				// Manually instigate traversal for parameter_declaration_clause_opt
				parameter_count = 0;
				parameters = NULL;
				
				pt_temp = pt_get_child( dryad->children[0], parameter_declaration_clause_opt+1, 0 );
				traversal_1( pt_temp, 0 );
				pt_temp = NULL;
				// And handle the results of parameter traversal immediately
				// i.e. Finish defining function type
				// Assign each of its discovered parameters
				type_temp->u.func.ct_params = parameter_count;
				type_temp->u.func.params = parameters;
				parameter_count = 0;
				parameters = NULL;
				
				// And don't let anything happen automatically for the function's own definition
				skip_traversals = 1;
			}

			if ( dryad->production == function_definition+2 )
			{
				// Grab function name for general usage, and finish filling out scope name
				name_temp = get_id_from_direct_declarator( dryad->children[1] );
				current_scope->name = name_temp;
				
				// Create the function type
				type_temp = tt_insert( typetable, t_FUNC );
				if ( type_temp == NULL )
					return handle_semantic_error( "Failed to allocate memory for the type for a function.", 2, -1 );
				type_temp->u.func.func_name = name_temp;
				type_temp->u.func.return_type = tt_get_type_basic( typetable, t_VOID );
				
				// Add to parent scope's symbol table or give warning if already defined
				symbol_temp = st_find( current_scope->parent->symbols_in_scope, name_temp );
				if ( symbol_temp != NULL && symbol_temp->defined == 1 )
				{
					handle_semantic_warning( "Redefining function within scope.", name_temp, 2, -1 );
				}
				else
				{
					// Add to symbol table of function scope's parent (not to symbol table for function itself)
					symbol_temp = st_insert( current_scope->parent->symbols_in_scope, name_temp, type_temp );
					if ( symbol_temp == NULL )
						return handle_semantic_error( "Failed to allocate memory for the symbol for a function.", 2, -1 );
					symbol_temp->declaring_node = dryad;
					symbol_temp->declared = 1;
					symbol_temp->defined = 1;
				}				
				
				// Gather return type now, and update with symbol
				type_temp = NULL;
				type_temp = assemble_type( dryad );
				symbol_temp->type->u.func.return_type = type_temp;
				type_temp = symbol_temp->type;
				// Take a moment to update the function's scope with this information
				current_scope->assocd_type = type_temp;

				// Manually instigate traversal for parameter_declaration_clause_opt
				parameter_count = 0;
				parameters = NULL;
				
				pt_temp = pt_get_child( dryad->children[1], parameter_declaration_clause_opt+1, 0 );
				traversal_1( pt_temp, 0 );
				pt_temp = NULL;
				// And handle the results of parameter traversal immediately
				// i.e. Finish defining function type
				// Assign each of its discovered parameters
				type_temp->u.func.ct_params = parameter_count;
				type_temp->u.func.params = parameters;
				parameter_count = 0;
				parameters = NULL;
				
				// And don't let anything happen automatically for the function's own definition
				skip_traversals = 2;
			}
			
			if ( dryad->production == simple_declaration+1 || dryad->production == member_declaration+1 )
			{
				// Grab function name for general usage, and finish filling out scope name
				name_temp = get_id_from_direct_declarator( dryad->children[1] );
				if ( name_temp == NULL )
					name_temp = get_unqualified_id( dryad->children[1] );
				
				// Differentiate based on direct_declarator_5 or direct_declarator_6
				// If is present, then is a function declaration; 
				// if it isn't, it's simply a variable (haha ... does that exist?).
				pt_temp = pt_get_child( dryad->children[1], direct_declarator+5, 1 );
				// Create function type
				if ( pt_temp != NULL )
				{
					type_temp = tt_insert( typetable, t_FUNC );
					if ( type_temp == NULL )
						return handle_semantic_error( "Failed to allocate memory for a type for a function.", 2, -1 );
					type_temp->u.func.func_name = name_temp;
					type_temp->u.func.return_type = tt_get_type_basic( typetable, t_VOID );
					
					// Add to scope's symbol table or give warning if already defined
					symbol_temp = st_find( current_scope->symbols_in_scope, name_temp );
					if ( symbol_temp != NULL && symbol_temp->declared == 1 )
					{
						handle_semantic_warning( "Redeclaring function within scope.", name_temp, 2, -1 );
					}
					else
					{
						symbol_temp = st_insert( current_scope->symbols_in_scope, name_temp, type_temp );
						if ( symbol_temp == NULL )
							return handle_semantic_error( "Failed to allocate memory for the symbol for a function.", 2, -1 );
						symbol_temp->declaring_node = dryad;
						symbol_temp->declared = 1;
						symbol_temp->defined = 0;
					}				
					
					// Gather return type now, and update with symbol
					type_temp = NULL;
					type_temp = assemble_type( dryad );
					symbol_temp->type->u.func.return_type = type_temp;
					type_temp = symbol_temp->type;
	
					// Manually instigate traversal for parameter_declaration_clause_opt
					parameter_count = 0;
					parameters = NULL;
					
					pt_temp = pt_get_child( dryad->children[1], parameter_declaration_clause_opt+1, 0 );
					traversal_1( pt_temp, 0 );
					pt_temp = NULL;
					// And handle the results of parameter traversal immediately
					// i.e. Finish defining function type
					// Assign each of its discovered parameters
					type_temp->u.func.ct_params = parameter_count;
					type_temp->u.func.params = parameters;
					parameter_count = 0;
					parameters = NULL;
				}
				// Create basic variable declaration
				else
				{
					type_temp = NULL;
					// Add to scope's symbol table or give warning if already defined
					symbol_temp = st_find( current_scope->symbols_in_scope, name_temp );
					if ( symbol_temp != NULL && symbol_temp->declared == 1 )
					{
						handle_semantic_warning( "Redeclaring variable within scope.", name_temp, 2, -1 );
					}
					else
					{
						symbol_temp = st_insert( current_scope->symbols_in_scope, name_temp, type_temp );
						if ( symbol_temp == NULL )
							return handle_semantic_error( "Failed to allocate memory for the symbol for a variable.", 2, -1 );
						symbol_temp->declaring_node = dryad;
						symbol_temp->declared = 1;
						symbol_temp->defined = 1;
					}

					type_temp = assemble_type( dryad );
					symbol_temp->type = type_temp;
				}
				// And just skip over this production's children, because we've manually handled it all.
				skip_traversals = 3;
			}
			
			if ( dryad->production == parameter_declaration+1 || dryad->production == parameter_declaration+2 )
			{
				name_temp = get_unqualified_id( dryad->children[1] );
			}
			
			if ( dryad->production == direct_declarator+7 || dryad->production == direct_declarator+8 )
			{
				// Check that children[3] ( + get_unqualified_id() for declarator+7) 
				//   is in scope and is declared
				if ( dryad->production == direct_declarator+8 )
					name_temp = dryad->children[3]->t->text;
				else
					name_temp = get_unqualified_id( dryad->children[3] );
				
				scope_temp = current_scope->parent;
				if ( strcmp( scope_temp->name, dryad->children[0]->t->text ) == 0 )
				{
					symbol_temp = st_find( scope_temp->symbols_in_scope, name_temp );
					if ( ( symbol_temp != NULL && symbol_temp->declared == 0 ) || symbol_temp == NULL )
						handle_semantic_warning( "Class member is undeclared.", name_temp, 2, dryad->children[0]->t->lineno );
				}
				else
				{
					handle_semantic_warning( "Class or namespace is undeclared.", dryad->children[0]->t->text, 2, dryad->children[0]->t->lineno );
				}
			}
			
			if ( dryad->production == direct_declarator+6 )
			{
				// Check that current scope name == name of child 1.
				// If not, issue warning about function definition missing return type
				if ( strcmp( current_scope->name, dryad->children[0]->t->text ) != 0 )
					handle_semantic_warning( "Function definition is missing its return type or constructor is not defined within proper scope.", dryad->children[0]->t->text, 2, dryad->children[0]->t->lineno );
				
				name_temp = dryad->children[0]->t->text;
			}
			
			if ( dryad->production == using_directive+4 )
			{
				name_temp = dryad->children[0]->t->text;
			}

			/* END: Operations upon entering subtree
		    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
			
			
			
			
			
			/* SUBSECTION: Continue analysis with subtree traversal
		    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
			for ( i=skip_traversals; i<dryad->ct_children; ++i )
			{
				// Check for and ignore NULL epsilon nodes to avoid Seg Faults.
				if ( dryad->children[i] != NULL )
				{
					traversal_1( dryad->children[i], depth );
				}
			}
			skip_traversals = 0;
			/* END: Subtree traversal
		    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
			
			
			
			
			
			/* SUBSECTION: Operations to perform after leaving a subtree
		    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
		  
		  // Fetch a reference to the symbol for all the rules in general, 
		  //   so we don't have to keep doing that repeatedly.
		  if ( name_temp != NULL )
		  	symbol_temp = st_find( current_scope->symbols_in_scope, name_temp );

			if ( dryad->production == using_directive+4 )
			{
				// Change symbol type to namespace
				if ( symbol_temp != NULL )
					symbol_temp->type = tt_get_type_basic( typetable, t_NAMESPC );
			}
			
			if ( dryad->production == type_name+1 )
			{
				if ( symbol_temp != NULL && symbol_temp->declared == 0 )
					handle_semantic_warning( "Undeclared type name.", name_temp, 2, dryad->children[0]->t->lineno );
			}
			
			if ( dryad->production == parameter_declaration+1 || dryad->production == parameter_declaration+2 )
			{
				// Gather parameter type, and update with symbol
				type_temp = NULL;
				type_temp = assemble_type( dryad );
				symbol_temp->type = type_temp;
				symbol_temp->declared = 1;
				symbol_temp->defined = 1;
				symbol_temp->declaring_node = dryad;
				
				// Assemble or add to parameter list for function type definition.
				prepare_parameter_list();
				parameters[ parameter_count ]->name = symbol_temp->id;
				parameters[ parameter_count ]->type = symbol_temp->type;
				++parameter_count;
			}
			
			if ( dryad->production == parameter_declaration+3 || dryad->production == parameter_declaration+4 )
			{
				// Gather parameter type, but there is no symbol to update.
				// We're only filling out an abstract type for a function declaration.
				type_temp = NULL;
				type_temp = assemble_type( dryad );
				
				// Assemble or add to parameter list for function type definition.
				prepare_parameter_list();
				parameters[ parameter_count ]->name = NULL;
				parameters[ parameter_count ]->type = type_temp;
				++parameter_count;
			}
			
			if ( dryad->production == direct_declarator+6 )
			{
				// Type = function
				// Return type = type of scope's class
				// Assign parameters if available
			}
			
			if ( dryad->production == function_definition+1 )
			{
				
			}

			if ( dryad->production == function_definition+2 )
			{
				
			}

			// Change scope back
			if ( dryad->production == class_specifier || ( dryad->production >= function_definition+1 && dryad->production <= function_definition+2 ) )
			{
				// If original_scope != NULL, then we jumped scopes, e.g. defined a class member outside a class
				if ( original_scope != NULL )
				{
					current_scope = original_scope;
					original_scope = NULL;
				}
				else if ( current_scope->parent != NULL )
				{
					current_scope = current_scope->parent;
				}
				else
				{
					return handle_semantic_error( "Problem switching scopes when leaving a function or class definition. Class or function scoping is malformed.", 1, -1 );
				}
			}

			/* END: Operations upon leaving subtree
		    - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
		}
		/* END: Non-terminal Operations
		  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
	}
	
	return program_result_120;
}


// Traverses a subtree, 
// Looks for type_specifier_1 to acquire the basic type, 
//   then looks for pointers, then arrays. 
// It should look for and assemble them in that order.
// When first calling, provide NULL for all parameters except t.
// RETURNS: pointer to assembled type
//          NULL, if there was an error, or none of the appropriate productions found to assemble from.
ctype* assemble_type( tree *t )
{
	int i = 0;
	ctype *assembled_type = NULL;
	ctype *tmp_new = NULL;
	ctype *tmp_t = NULL;
	short cat_def = 0;
	
	if ( t != NULL )
	{
		if ( t->children != NULL && t->ct_children > 0 )
		{
			for ( i=0; i<t->ct_children; ++i )
			{
				if ( t->children[i] != NULL 
					&& t->production != member_specification_opt+1 
					&& t->production != parameter_declaration_clause_opt+1 
					&& t->production != initializer_opt+1
					&& t->production != function_body )
					tmp_new = assemble_type( t->children[i] );
				
				if ( program_result_120 != EXIT_NORMAL )
					exit( program_result_120 );
				
				// Integrate type results
				// Don't let NULL type searches overwrite progress so far.
				if ( tmp_new != NULL )
				{
					if ( assembled_type == NULL )
					{
						assembled_type = tmp_new;
						tmp_new = NULL;
					}
					else
					{
						// Do some gymnastics to keep all types
						//   and get all types pointed to subtypes
						tmp_t = tmp_new;
						do
						{
							if ( tmp_t->base_type == t_ARRAY )
							{
								if ( tmp_t->u.array.of != NULL )
									tmp_t = tmp_t->u.array.of;
								else
									break;
							}
							else if ( tmp_t->base_type == t_POINTER )
							{
								if ( tmp_t->u.ptr != NULL )
									tmp_t = tmp_t->u.ptr;
								else
									break;
							}
							else
								break;
						} while ( tmp_t != NULL );
						
						if ( tmp_t->base_type == t_ARRAY )
						{
							tmp_t->u.array.of = assembled_type;
							assembled_type = tmp_new;
							tmp_new = NULL;
							tmp_t = NULL;
						}
						else if ( tmp_t->base_type == t_POINTER )
						{
							tmp_t->u.ptr = assembled_type;
							assembled_type = tmp_new;
							tmp_new = NULL;
							tmp_t = NULL;
						}
						else
						{
							handle_semantic_warning( "Type specification error.", NULL, 1, -1 );
							return NULL;
						}
					}
				}
			}
		}
		// Create a new array type, point it at type, then point type to it.
		if ( t->production == literal+1 
				 || (( t->production == direct_declarator+9 || t->production == direct_abstract_declarator+5 ) && tmp_new == NULL ) )
		{
			tmp_new = tt_insert( typetable, t_ARRAY );
			if ( tmp_new == NULL )
			{
				handle_semantic_error( "Failed to allocate memory while getting symbol and type information.", 2, -1 );
				return NULL;
			}
			if ( t->production == literal+1 )
				tmp_new->u.array.size = t->children[0]->t->ival;
			else
				tmp_new->u.array.size = -1;
			tmp_new->u.array.of = NULL;
			assembled_type = tmp_new;
			tmp_new = NULL;
		}
		// Create a new pointer type, point it at type, then point type to it.
		if ( t->production == ptr_operator+1 )
		{
			tmp_new = tt_insert( typetable, t_POINTER );
			if ( tmp_new == NULL )
			{
				handle_semantic_error( "Failed to allocate memory while getting symbol and type information.", 2, -1 );
				return NULL;
			}
			tmp_new->u.ptr = NULL;
			assembled_type = tmp_new;
			tmp_new = NULL;
		}
		if ( t->production == type_name+1 )
		{
			tmp_new = tt_insert( typetable, t_CLASS );
			if ( tmp_new == NULL )
			{
				handle_semantic_error( "Failed to allocate memory while getting symbol and type information.", 2, -1 );
				return NULL;
			}
			tmp_new->u.clss.clss_name = t->children[0]->t->text;
			assembled_type = tmp_new;
			tmp_new = NULL;
		}
		if ( t->production == type_specifier+1 )
		{
			if ( t->children[0]->t->category == VOID )
				cat_def = t_VOID;
			else if ( t->children[0]->t->category == BOOL )
				cat_def = t_BOOL;
			else if ( t->children[0]->t->category == CHAR )
				cat_def = t_CHAR;
			else if ( t->children[0]->t->category == INT )
				cat_def = t_INT;
			else if ( t->children[0]->t->category == SHORT )
				cat_def = t_SHORT;
			else if ( t->children[0]->t->category == LONG )
				cat_def = t_LONG;
			else if ( t->children[0]->t->category == DOUBLE )
				cat_def = t_DOUBLE;
			else if ( t->children[0]->t->category == FLOAT )
				cat_def = t_FLOAT;
			else
				cat_def = t_MISC;
			
			if ( cat_def == t_MISC )
			{
				tmp_new = tt_insert( typetable, t_MISC );
				if ( tmp_new == NULL )
				{
					handle_semantic_error( "Failed to allocate memory while getting symbol and type information.", 2, -1 );
					return NULL;
				}
				tmp_new->u.misc.name_of_type = t->children[0]->t->text;
			}
			else
			{
				tmp_new = tt_get_type_basic( typetable, cat_def );
			}
			assembled_type = tmp_new;
			tmp_new = NULL;
		}
		if ( t->production == ptr_operator+3 && assembled_type != NULL )
		{
			// byref = true -- how to pass back out? That's stored in symbol, but symbol not created yet.
			// Saving this problem for later.
		}
	}
	
	return assembled_type;
}


// It's a far-reaching bullet, 
//   so narrow down the subtree you provide as much as possible first.
char* get_unqualified_id( tree *t )
{
	t = pt_get_child( t, unqualified_id+1, 0 );
	if ( t != NULL && t->children != NULL && t->children[0]->t != NULL )
	{
		return t->children[0]->t->text;
	}
	else
		return NULL;
}


// It's a far-reaching bullet, 
//   so narrow down the subtree you provide as much as possible first.
char* get_id_from_direct_declarator( tree *t )
{
	t = pt_get_child( t, direct_declarator+5, 3 );
	if ( t != NULL && t->children != NULL )
	{
		if ( t->production == direct_declarator+5 )
			return get_unqualified_id( t );

		if ( t->production == direct_declarator+6 )
			return t->children[0]->t->text;

		if ( t->production == direct_declarator+7 )
			return get_unqualified_id( t->children[2] );

		if ( t->production == direct_declarator+8 )
			return t->children[2]->t->text;
	}
}


// Allocate space for parameters to populate function return types
void prepare_parameter_list()
{
	if ( parameters == NULL )
	{
		parameters = ( struct param** ) malloc( sizeof( struct param* ) );
		if ( parameters == NULL )
		{
			handle_semantic_error( "Failed to allocate memory for function parameters.", 2, -1 );
			exit( program_result_120 );
		}
	}
	else
	{
		parameters = ( struct param** ) realloc( parameters, sizeof( struct param* ) * (parameter_count+1) );
		if ( parameters == NULL )
		{
			handle_semantic_error( "Failed to reallocate memory for function parameters.", 2, -1 );
			exit( program_result_120 );
		}
	}
	parameters[ parameter_count ] = ( struct param* ) malloc( sizeof( struct param ) );
	if ( parameters[ parameter_count ] == NULL )
	{
		handle_semantic_error( "Failed to allocate memory for function parameters.", 2, -1 );
		exit( program_result_120 );
	}
}


// Get lineno from relevant token, if available
void handle_semantic_warning( char *msg, char *id, int type, int line_num )
{
	fprintf( stderr, "120++ Semantics Analysis > Warning: " );
	
	switch ( type )
	{
		case 1:
			fprintf( stderr, "%s\n\tIn file %s", msg, yyfiles->filename );
			break;
		case 2:
			fprintf( stderr, "For symbol %s: %s\n\tIn file %s", id, msg, yyfiles->filename );
			break;
		default:
			fprintf( stderr, "Unspecified warning: %s\n\tIn file %s", msg, yyfiles->filename );
			break;
	}
	if ( line_num > 0 )
		fprintf( stderr, " at line %d", line_num );
	fprintf( stderr, ".\n\n" );
}


int handle_semantic_error( char *msg, int type, int line_num )
{
	fprintf( stderr, "120++ Semantics Analysis > Error: " );
		
	switch ( type )
	{
		case 1:
			fprintf( stderr, "Semantics error in %s", yyfiles->filename );
			program_result_120 = EXIT_ERROR_SEMANTIC;
			break;
		case 2:
			fprintf( stderr, "Program error during semantic analysis for %s", yyfiles->filename );
			program_result_120 = EXIT_ERROR_PROGRAM;
			break;
		default:
			fprintf( stderr, "Unspecified program error during semantic analysis for %s", yyfiles->filename );
			program_result_120 = EXIT_ERROR_UNKNOWN;
			break;
	}
	if ( line_num > 0 )
		fprintf( stderr, " at line %d", line_num );
	fprintf( stderr, ":\n\t%s\n", msg );

	return program_result_120;
}
