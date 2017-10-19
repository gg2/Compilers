
#include "120++.h"


// open file(s).
// for each file, call yyparse()
// recognize errors from yylex() or yyparse(), if none:
// print out compilation metadata: symbol tables.
int main( int argc, char **argv )
{
	int i = 0, j = 0, ct = 1;
	FILE *f;
	ctype ***filetypetables = NULL;
	tree **fileparsetrees = NULL;
	symbol ***filesymboltables = NULL;
	scope **filescopetrees = NULL;
	
	if ( argc > 1 )
	{

		/* SECTION: Initialization
		  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		// Initialize globals and other values
		stack_init( &yyfiles );
		handling_includes = 0;
		// Arrays for referencing a parse tree, symbol table, and type table
		//    for each file provided at the command line.
		// ! Yes, I am allocating space for multiple type tables + their associated pointers
		//    all at once.
		filetypetables = ( ctype*** ) malloc( ( sizeof( ctype** ) * (argc-1) ) + (( sizeof( ctype* ) * tt_size ) * (argc-1) ) );
		fileparsetrees = ( tree** ) malloc( sizeof( tree* ) * (argc-1) );
		filesymboltables = ( symbol*** ) malloc( sizeof( symbol** ) * (argc-1) );
		filescopetrees = ( scope** ) malloc( sizeof( scope* ) * (argc-1) );
		if ( filescopetrees == NULL || filesymboltables == NULL || fileparsetrees == NULL || filetypetables == NULL )
		{
			fprintf( stderr, "120++ Compiler > Error allocating space for structures during setup in main.\n\n" );
			return EXIT_ERROR_PROGRAM;
		}
		// Initialize each tree's root
		// Allocate each individual symbol table
		// Allocate each individual type table
		for ( i=0; i<argc-1; ++i )
		{
			pt_init( &(fileparsetrees[i]) );
			filesymboltables[i] = ( symbol** ) malloc( sizeof( symbol* ) * st_size );
			if ( filesymboltables[i] == NULL )
			{
				fprintf( stderr, "120++ Compiler > Error allocating space for structures during setup in main.\n\n" );
				return EXIT_ERROR_PROGRAM;
			}
			// Master symbol table for each file, for use by Flex and Bison.
			st_init( filesymboltables[i] );
			// And here's where we fetch references to space further within the allocation
			//    where each type table will be stored.
			filetypetables[i] = &(filetypetables[ argc-1 + ( i * tt_size ) ]);
			filetypetables[i] = tt_init( filetypetables[i] );
			if ( filetypetables[i] == NULL )
			{
				fprintf( stderr, "120++ Compiler > Error allocating space for structures during setup in main.\n\n" );
				return EXIT_ERROR_PROGRAM;
			}
		}

		/* END: Initialization
		  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
		/* SECTION: Main Procedure
		  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

		// Make sure filenames to parse are supplied from the command line
		// If so, parse on, brother!
		while ( ct < argc ) 
		{
			printf( "\nProcessing %s ...\n\n", argv[ct] );
			
			f = fopen( argv[ct], "r" );
			if ( f != NULL )
			{
				// Point the globals at the space allocated for them for each file
				// and set or reset other global flags
				yyparsetree = fileparsetrees[ ct-1 ];
				yysymboltable = filesymboltables[ ct-1 ];
				yyin = f;
				handling_includes = 0;
				defining_new_type = 0;
				stack_push( &yyfiles, argv[ct], f, 1 );
				program_result_120 = EXIT_NORMAL;
				
				/* Begin scanning and parsing 
				  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
				// yylex(); // Called by yyparse()
				yyparse();
				// Global program_result_120 may have been modified during yylex() or yyparse()
				
				// Close the file. We're done with it.
				fclose( f );
				yyfiles->file_ptr = NULL;
				// Fetch the current state of the globals, since they may have changed.
				fileparsetrees[ ct-1 ] = yyparsetree;
				filesymboltables[ ct-1 ] = yysymboltable;
				// Nullify the globals, whether used again or not
				yyparsetree = NULL;
				yysymboltable = NULL;
				
				/* Begin semantic analysis
				  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
				// Initialize scope tree, now that we have a parse tree
				filescopetrees[ ct-1 ] = scope_init( fileparsetrees[ ct-1 ] );
				if ( filescopetrees[ ct-1 ] == NULL )
				{
					fprintf( stderr, "120++ Compiler > Error allocating space for scope prior to semantic analysis in main.\n\n" );
					return EXIT_ERROR_PROGRAM;
				}
				analyze_semantics_1( fileparsetrees[ ct-1 ], filetypetables[ ct-1 ], filescopetrees[ ct-1 ] );

				stack_pop( &yyfiles );
			}
			else
			{
				fprintf( stderr, "120++ Compiler > Error opening %s from main.\n\n", argv[ct] );
				program_result_120 = EXIT_ERROR_FILE;
			}
			
			// yylex(), yyparse(), or other functions during compilation may have reported errors
			//   to global program_result_120.
			// If there were no problems reported, print out the results, 
			//   since everything should have scanned and parsed successfully.
			if ( program_result_120 == EXIT_NORMAL )
			{
				printf( "\n" );
				if ( PRINT_PARSE_TREES ) 
				{
					printf( "Parse Tree for %s:\n", argv[ct] );
					printf( "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n" );
					if ( fileparsetrees[ct-1] != NULL )
					{
						pt_print( fileparsetrees[ct-1], 0 );
					}
					else
					{
						printf( "[ ! Empty parse tree. ]\n" );
					}
					printf( "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n" );
				}
				
				if ( PRINT_SYMBOL_TABLES ) 
				{
					printf( "\"Master\" Symbol Table for %s:\n", argv[ct] );
					printf( "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n" );
					if ( filesymboltables[ct-1] != NULL )
					{
						st_print( filesymboltables[ct-1], 0 );
					}
					else
					{
						printf( "[ ! Empty symbol table. ]\n" );
					}
					printf( "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n" );
				}
				
				if ( PRINT_TYPE_TABLES ) 
				{
					printf( "Type Table for %s:\n", argv[ct] );
					printf( "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n" );
					if ( filetypetables[ct-1] != NULL )
					{
						tt_print( filetypetables[ct-1] );
					}
					else
					{
						printf( "[ ! Empty type table. ]\n" );
					}
					printf( "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n" );
				}

				if ( PRINT_SCOPE_SYMBOL_TABLES ) 
				{
					printf( "\"Symbol Tables for each scope in %s:\n", argv[ct] );
					printf( "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n" );
					if ( filescopetrees[ct-1] != NULL )
					{
						scope_print( filescopetrees[ct-1], 0 );
					}
					else
					{
						printf( "[ ! Empty symbol table. ]\n" );
					}
					printf( "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n\n" );
				}
				
			}
			// If a program-level problem or worse has been reported, clean up and stop.
			else if ( program_result_120 >= EXIT_ERROR_PROGRAM )
			{
				break;
			}
			// Continue on.
			++ct;
		}

		/* END: Main Procedure
		  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
		/* SECTION: Cleanup
		  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
		
		// Free up dynamically allocated memory
		for ( i=0; i<argc-1; ++i )
		{
			if ( filescopetrees[i] != NULL )
				scope_destruct( &(filescopetrees[i]) );
			if ( filesymboltables[i] != NULL )
				st_destruct( filesymboltables[i] );
			filesymboltables[i] = NULL;
			if ( fileparsetrees[i] != NULL )
				pt_destruct( &(fileparsetrees[i]) );
			if ( filetypetables[i] != NULL )
				tt_destruct( filetypetables[i] );
		}
		// Free up the remaining dynamically allocated memory
		free( filescopetrees );
		filescopetrees = NULL;
		free( filesymboltables );
		filesymboltables = NULL;
		free( fileparsetrees );
		fileparsetrees = NULL;
		free( filetypetables );
		filetypetables = NULL;
		stack_destruct( &yyfiles );

		/* END: Cleanup
		  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
	}
	else
	{
		printf( "Please provide a list of filenames to open as space-separated parameters.\n\n" );
	}
	
	return program_result_120;
}
