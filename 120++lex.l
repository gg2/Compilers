O					[0-7]
D					[0-9]
L					[a-zA-Z_]
H					[a-fA-F0-9]
F					({D}*\.{D}+)|({D}+\.)
E					[eE][+-]?{D}+
FS				[fFlL]
IS				([uU][lL]?)|([lL][uU]?)
CHAR			'(\\.|[^\\'])'
CONST			\"(\\.|[^\\"])*\"

%{

#ifndef GG_LEX_L
#define GG_LEX_L


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "globals.h"
#include "120++parse.tab.h"


int i = 0;
char *w_msg_alttokens = "Converted an alternative token per C++14 to its primary token.";
char *yyincludefilename = NULL;
extern YYSTYPE yylval;

static void skip_comment_multiline(void);
static void skip_comment_singleline(void);
int store_token(int cat_def);
char* check_symbol(symbol **table,char *s_o);
char* store_symbol(symbol **table,char *s_o);
symbol* store_type(symbol **table,char *s_o,int token_id);
int fetch_type(symbol **table,char *s_o);
void handle_include();
void handle_custom_include();
void handle_system_include(const char *file_name);
void handle_scan_warning(char *msg,int type);
int handle_scan_error(char *msg,int type);

#endif /* GG_LEX_L */

%}

%%

[\n\v]                  { ++(yyfiles->line_num); }
[ \t\f\r]+            	{ }

(#|%:)"include"[ \t]*\"[^"\n]+\"		{
																			if ( yytext[0] == '%' && yyfiles->w_digraphs )
																				handle_scan_warning( w_msg_alttokens, 4 );
																			handle_custom_include();
																		}
(#|%:)"include"[ \t]*"<iostream>"		{
																			if ( yytext[0] == '%' && yyfiles->w_digraphs )
																				handle_scan_warning( w_msg_alttokens, 4 );
																			if ( included_iostream == 0 )
																			{
																				included_iostream = 1;
																				handle_system_include( "incl_iostream.h" );
																			}
																		}
(#|%:)"include"[ \t]*"<fstream>"		{
																			if ( yytext[0] == '%' && yyfiles->w_digraphs )
																				handle_scan_warning( w_msg_alttokens, 4 );
																			if ( included_fstream == 0 )
																			{
																				included_fstream = 1;
																				handle_system_include( "incl_fstream.h" );
																			}
																		}
(#|%:)"include"[ \t]*"<string>"			{
																			if ( yytext[0] == '%' && yyfiles->w_digraphs )
																				handle_scan_warning( w_msg_alttokens, 4 );
																			if ( included_string == 0 )
																			{
																				included_string = 1;
																				handle_system_include( "incl_string.h" );
																			}
																		}
(#|%:)"include"[ \t]*"<string.h>"		{
																			if ( yytext[0] == '%' && yyfiles->w_digraphs )
																				handle_scan_warning( w_msg_alttokens, 4 );
																			if ( included_cstdlib == 0 )
																			{
																				included_cstdlib = 1;
																				handle_system_include( "incl_c.h" );
																			}
																		}
(#|%:)"include"[ \t]*"<cstdlib>"		{
																			if ( yytext[0] == '%' && yyfiles->w_digraphs )
																				handle_scan_warning( w_msg_alttokens, 4 );
																			if ( included_cstdlib == 0 )
																			{
																				included_cstdlib = 1;
																				handle_system_include( "incl_c.h" );
																			}
																		}
(#|%:)"include"[ \t]*"<ctime>"			{
																			if ( yytext[0] == '%' && yyfiles->w_digraphs )
																				handle_scan_warning( w_msg_alttokens, 4 );
																			if ( included_cstdlib == 0 )
																			{
																				included_cstdlib = 1;
																				handle_system_include( "incl_c.h" );
																			}
																		}
(#|%:)"include"[ \t]*"<"[^>\n]+">"	{ 
																			if ( yytext[0] == '%' && yyfiles->w_digraphs )
																				handle_scan_warning( w_msg_alttokens, 4 );
																			if ( yyfiles->w_include ) 
																		 		handle_scan_warning( "Ignored #include not specified in 120++ specs.", 1 ); 
																		}
("##"|"%:%:")							      		{ 
																	  	if ( yyfiles->w_preprocdirective ) 
																		 		handle_scan_warning( "Ignored preprocessor directive not specified in 120++ specs.", 2 ); 
																		}
(#|%:).* 											      { 
																			if ( yytext[0] == '%' && yyfiles->w_digraphs )
																				handle_scan_warning( w_msg_alttokens, 4 );
																	  	if ( yyfiles->w_preprocdirective ) 
																		 		handle_scan_warning( "Ignored preprocessor directive not specified in 120++ specs.", 2 ); 
																		}


"<%"										{ 
													if ( yyfiles->w_digraphs )
														handle_scan_warning( w_msg_alttokens, 4 );
													return store_token( '{' );
												}
"%>"										{ 
													if ( yyfiles->w_digraphs )
														handle_scan_warning( w_msg_alttokens, 4 );
													return store_token( '}' );
												}
"<:"										{ 
													if ( yyfiles->w_digraphs )
														handle_scan_warning( w_msg_alttokens, 4 );
													return store_token( '[' );
												}
":>"										{ 
													if ( yyfiles->w_digraphs )
														handle_scan_warning( w_msg_alttokens, 4 );
													return store_token( ']' );
												}
"and"										{ 
													if ( yyfiles->w_digraphs )
														handle_scan_warning( w_msg_alttokens, 4 );
													return store_token( ANDAND );
												}
"or"										{ 
													if ( yyfiles->w_digraphs )
														handle_scan_warning( w_msg_alttokens, 4 );
													return store_token( OROR );
												}
"not"										{ 
													if ( yyfiles->w_digraphs )
														handle_scan_warning( w_msg_alttokens, 4 );
													return store_token( '!' );
												}
"xor"										{ 
													if ( yyfiles->w_digraphs )
														handle_scan_warning( w_msg_alttokens, 4 );
													return store_token( '^' );
												}
"compl"									{ 
													if ( yyfiles->w_digraphs )
														handle_scan_warning( w_msg_alttokens, 4 );
													return store_token( '~' );
												}
"bitand"								{ 
													if ( yyfiles->w_digraphs )
														handle_scan_warning( w_msg_alttokens, 4 );
													return store_token( '&' );
												}
"bitor"									{ 
													if ( yyfiles->w_digraphs )
														handle_scan_warning( w_msg_alttokens, 4 );
													return store_token( '|' );
												}
"and_eq"								{ 
													if ( yyfiles->w_digraphs )
														handle_scan_warning( w_msg_alttokens, 4 );
													return store_token( ANDEQ );
												}
"or_eq"									{ 
													if ( yyfiles->w_digraphs )
														handle_scan_warning( w_msg_alttokens, 4 );
													return store_token( OREQ );
												}
"xor_eq"								{ 
													if ( yyfiles->w_digraphs )
														handle_scan_warning( w_msg_alttokens, 4 );
													return store_token( XOREQ );
												}
"not_eq"								{ 
													if ( yyfiles->w_digraphs )
														handle_scan_warning( w_msg_alttokens, 4 );
													return store_token( NOTEQ );
												}
"bool"									{ return store_token( BOOL ); }
"break"                 { return store_token( BREAK ); }
"case"                  { return store_token( CASE ); }
"char"                  { return store_token( CHAR ); }
"class"                 { return store_token( CLASS ); }
"const"                 { return store_token( CONST ); }
"default"               { return store_token( DEFAULT ); }
"delete"                { return store_token( DELETE ); }
"do"                    { return store_token( DO ); }
"double"                { return store_token( DOUBLE ); }
"else"                  { return store_token( ELSE ); }
"extern"                { return store_token( EXTERN ); }
"float"                 { return store_token( FLOAT ); }
"for"                   { return store_token( FOR ); }
"if"                    { return store_token( IF ); }
"int"                   { return store_token( INT ); }
"long"                  { return store_token( LONG ); }
"namespace"             { return store_token( NAMESPACE ); }
"new"										{ return store_token( NEW ); }
"private"               { return store_token( PRIVATE ); }
"protected"							{ return store_token( PROTECTED ); }
"public"                { return store_token( PUBLIC ); }
"return"                { return store_token( RETURN ); }
"short"                 { return store_token( SHORT ); }
"struct"                { return store_token( STRUCT ); }
"switch"                { return store_token( SWITCH ); }
"typedef"               { return store_token( TYPEDEF ); }
"unsigned"              { return store_token( UNSIGNED ); }
"using"                 { return store_token( USING ); }
"void"                  { return store_token( VOID ); }
"while"                 { return store_token( WHILE ); }

"alignas"								{
													handle_scan_warning( "The identifier \"alignas\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( ALIGNAS );
												}
"alignof"								{
													handle_scan_warning( "The identifier \"alignof\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( ALIGNOF );
												}
"asm"										{
													handle_scan_warning( "The identifier \"asm\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( ASM );
												}
"auto"									{
													handle_scan_warning( "The identifier \"auto\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( AUTO );
												}
"catch"									{
													handle_scan_warning( "The identifier \"catch\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( CATCH );
												}
"char16_t"							{
													handle_scan_warning( "The identifier \"char16_t\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( CHAR16_T );
												}
"char32_t"							{
													handle_scan_warning( "The identifier \"char32_t\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( CHAR32_T );
												}
"const_cast"						{
													handle_scan_warning( "The identifier \"const_cast\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( CONST_CAST );
												}
"constexpr"							{
													handle_scan_warning( "The identifier \"constexpr\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( CONST_EXPR );
												}
"continue"							{
													handle_scan_warning( "The identifier \"continue\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( CONTINUE );
												}
"decltype"							{
													handle_scan_warning( "The identifier \"decltype\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( DECLTYPE );
												}
"dynamic_cast"					{
													handle_scan_warning( "The identifier \"dynamic_cast\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( DYNAMIC_CAST );
												}
"enum"									{
													handle_scan_warning( "The identifier \"enum\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( ENUM );
												}
"explicit"							{
													handle_scan_warning( "The identifier \"explicit\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( EXPLICIT );
												}
"export"								{
													handle_scan_warning( "The identifier \"export\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( EXPORT );
												}
"friend"								{
													handle_scan_warning( "The identifier \"friend\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( FRIEND );
												}
"goto"									{
													handle_scan_warning( "The identifier \"goto\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( GOTO );
												}
"inline"								{
													handle_scan_warning( "The identifier \"inline\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( INLINE );
												}
"mutable"								{
													handle_scan_warning( "The identifier \"mutable\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( MUTABLE );
												}
"noexcept"							{
													handle_scan_warning( "The identifier \"noexcept\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( NOEXCEPT );
												}
"nullptr"								{
													handle_scan_warning( "The identifier \"nullptr\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( NULLPTR );
												}
"operator"							{
													handle_scan_warning( "The identifier \"operator\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( OPERATOR );
												}
"register"							{
													handle_scan_warning( "The identifier \"register\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( REGISTER );
												}
"reinterpret_cast"			{
													handle_scan_warning( "The identifier \"reinterpret_cast\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( REINTERPRET_CAST );
												}
"signed"								{
													handle_scan_warning( "The identifier \"signed\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( SIGNED );
												}
"sizeof"								{
													handle_scan_warning( "The identifier \"sizeof\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( SIZEOF );
												}
"static"								{
													handle_scan_warning( "The identifier \"static\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( STATIC );
												}
"static_assert"					{
													handle_scan_warning( "The identifier \"static_assert\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( STATIC_ASSERT );
												}
"static_cast"						{
													handle_scan_warning( "The identifier \"static_cast\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( STATIC_CAST );
												}
"template"							{
													handle_scan_warning( "The identifier \"template\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( TEMPLATE );
												}
"this"									{
													handle_scan_warning( "The identifier \"this\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( THIS );
												}
"thread_local"					{
													handle_scan_warning( "The identifier \"thread_local\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( THREAD_LOCAL );
												}
"throw"									{
													handle_scan_warning( "The identifier \"throw\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( THROW );
												}
"try"										{
													handle_scan_warning( "The identifier \"try\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( TRY );
												}
"typeid"								{
													handle_scan_warning( "The identifier \"typeid\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( TYPEID );
												}
"typename"							{
													handle_scan_warning( "The identifier \"typename\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( TYPENAME );
												}
"union"									{
													handle_scan_warning( "The identifier \"union\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( UNION );
												}
"virtual"								{
													handle_scan_warning( "The identifier \"virtual\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( VIRTUAL );
												}
"volatile"							{
													handle_scan_warning( "The identifier \"volatile\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( VOLATILE );
												}
"wchar_t"								{
													handle_scan_warning( "The identifier \"wchar_t\" is a keyword in C++14 specs, but is not specified in 120++ specs.", 5 );
													return store_token( WCHAR_T );
												}

("TRUE"|"true")         { return store_token( TRUE ); }
("FALSE"|"false")       { return store_token( FALSE ); }

{L}({L}|{D})*           { return store_token( IDENTIFIER ); }

0[xX]{H}+{IS}?          { 
													//if ( yyfiles->w_numberformats )
														handle_scan_warning( "Hexadecimal number format not specified in 120++ specs.", 3 );
													return store_token( INTEGER );
												}
0{O}+{IS}?              { 
													//if ( yyfiles->w_numberformats )
														handle_scan_warning( "Octal number format not specified in 120++ specs.", 3 );
													return store_token( INTEGER ); 
												}
{D}+{IS}?             	{ return store_token( INTEGER ); }

{F}{E}?{FS}?						{ return store_token( FLOATING ); }
{D}+{E}{FS}?						{ return store_token( FLOATING ); }

[L]?{CHAR}							{ return store_token( CHARACTER ); }
[L]?{CONST} 	          { return store_token( STRING ); }



"("                     { return store_token( '(' ); }
")"                     { return store_token( ')' ); }
"{"                     { return store_token( '{' ); }
"}"                     { return store_token( '}' ); }
"["                     { return store_token( '[' ); }
"]"                     { return store_token( ']' ); }
","                     { return store_token( ',' ); }
":"                     { return store_token( ':' ); }
";"                     { return store_token( ';' ); }
"..."										{ return store_token( ELLIPSIS ); }
"?"											{ return store_token( '?' ); }
"::"                    { return store_token( COLONCOLON ); }
"."                     { return store_token( '.' ); }
".*"										{ return store_token( DOTSTAR ); }
"="                     { return store_token( '=' ); }
"+"                     { return store_token( '+' ); }
"-"                     { return store_token( '-' ); }
"*"                     { return store_token( '*' ); }
"/"                     { return store_token( '/' ); }
"%"                     { return store_token( '%' ); }
"+="                    { return store_token( ADDEQ ); }
"-="                    { return store_token( SUBEQ ); }
"*="										{ return store_token( MULEQ ); }
"/="										{ return store_token( DIVEQ ); }
"%="										{ return store_token( MODEQ ); }
"&&"                    { return store_token( ANDAND ); }
"||"                    { return store_token( OROR ); }
"&"                     { return store_token( '&' ); }
"&="										{ return store_token( ANDEQ ); }
"|"											{ return store_token( '|' ); }
"|="										{ return store_token( OREQ ); }
"^"											{ return store_token( '^' ); }
"^="										{ return store_token( XOREQ ); }
"~"                     { return store_token( '~' ); }
"!"                     { return store_token( '!' ); }
"<<"                    { return store_token( SL ); }
"<<="										{ return store_token( SLEQ ); }
">>"                    { return store_token( SR ); }
">>="										{ return store_token( SREQ ); }
"=="                    { return store_token( EQ ); }
"<"                     { return store_token( '<' ); }
"<="                    { return store_token( LTEQ ); }
">"                     { return store_token( '>' ); }
">="                    { return store_token( GTEQ ); }
"!="                    { return store_token( NOTEQ ); }
"++"                    { return store_token( PLUSPLUS ); }
"--"                    { return store_token( MINUSMINUS ); }
"->*"										{ return store_token( ARROWSTAR ); }
"->"                    { return store_token( ARROW ); }

"/*"([^*]|[*]+[^*/])*\*+\/   { skip_comment_multiline(); }
"//".*\n                { ++(yyfiles->line_num); }

.                      { return handle_scan_error( "Unidentified token.", 1 ); }
%%


// Increment line count for each \n in multiline comments
static void skip_comment_multiline( void )
{
	int i = 0;
	
	for ( i = 0; yytext[i] != '\0'; ++i )
	{
		if ( yytext[i] == '\n' )
		{
			++(yyfiles->line_num);
		}
	}
}


// Comment skipping function from CS445 sample lexer.
// Avoid buffering comments in yytext buffer.
// !!! Needs fixed. Causes Bison the line following the comment to be skipped.
static void skip_comment_singleline( void )
{
	int c;

	while ((c = input()) != EOF && c != '\n')
	{
		// Do nothing.
	}
	++(yyfiles->line_num);
}


// Store the token information within a token struct
//    and enclose the token struct within a tree node
//    for passing off to Bison.
// Returns: pointer to the new tree node
int store_token( int cat_def )
{
	tree *leaf = NULL;
	token *t = NULL;
	int i = 0, j = 0;
	
	// Allocate memory for the new token in the linked list
	leaf = ( tree* ) malloc( sizeof( tree ) );
	if ( leaf != NULL )
	{
		// Save the filename where this token came from
		t = ( token* ) malloc( sizeof( token ) );
		if ( t != NULL )
		{
			// Save the filename where this token came from
			t->filename = ( char* ) malloc( sizeof( char ) * ( strlen( yyfiles->filename ) + 1 ) );
			if ( t->filename != NULL )
			{
				strcpy( t->filename, yyfiles->filename );
			}
			else
			{
				return handle_scan_error( "Failed to allocate memory for filename within a token struct.", 3 );
			}
	
			// Save the token's line number
			t->lineno = (yyfiles->line_num);
	
			// Save the token itself
			// Check if identifiers of any sort already exist in the symbol table
			t->text = ( char* ) malloc( sizeof( char ) * ( yyleng + 1 ) );
			if ( t->text != NULL )
			{
				strncpy( t->text, yytext, yyleng );
				(t->text)[yyleng] = '\0';
			}	
			else
			{
				return handle_scan_error( "Failed to allocate memory for token within a token struct.", 3 );
			}
	
			// Process special actions for particular tokens (or sequences of tokens),
			//    such as recognizing new type definitions or namespace identifiers.
			switch ( cat_def )
			{
				case IDENTIFIER:
					// !!! Still have to come up with a way to 
					//   manage linking what's in the symbol table
					//   with the text that is stored in the token struct
					//   to avoid duplicate memory usage.
					// Store the new symbol in the symbol tree, 
					//   and exit immediately if there was a problem,
					//   because it's not worth messing with if there was.
					if ( ( store_symbol( yysymboltable, t->text ) ) == NULL )
					{
						return handle_scan_error( "Failed to allocate memory for a symbol table entry.", 3 );
					}
						
					switch ( defining_new_type )
					{
						case 1:
							store_type( yysymboltable, t->text, TYPEDEF_NAME );
							break;
						case 2:
							store_type( yysymboltable, t->text, NAMESPACE_NAME );
							cat_def = NAMESPACE_NAME;
							break;
						case 3:
							store_type( yysymboltable, t->text, CLASS_NAME );
							break;
						case 4:
							store_type( yysymboltable, t->text, ENUM_NAME );
							break;
						case 5:
							store_type( yysymboltable, t->text, TEMPLATE_NAME );
							break;
						default:
							cat_def = fetch_type( yysymboltable, t->text );
							break;
					}
					defining_new_type = 0;
					break;
				case TYPEDEF:
					defining_new_type = 1;
					break;
				case NAMESPACE:
					defining_new_type = 2;
					break;
				case CLASS:
					defining_new_type = 3;
					break;
				case ENUM:
					defining_new_type = 4;
					break;
				case TEMPLATE:
					defining_new_type = 5;
					break;
				default:
					break;
			}
			// Save the token's categorization, 
			//    now that we've had an opportunity to modify it.
			t->category = cat_def;
	
			// Save a numeric representation of the token for constant numeric literals,
			// Or the literal with its enclosing quotes removed and 
			//    escaped characters replaced for constant character literals.
			switch ( cat_def )
			{
				case TRUE:
				{
					t->ival = 1;
					t->rval = 1.0;
					t->sval = NULL;
					break;
				}
				case FALSE:
				{
					t->ival = 0;
					t->rval = 0.0;
					t->sval = NULL;
					break;
				}
				case INTEGER:
				{
					t->ival = atoi( yytext );
					t->rval = 0.0;
					t->sval = NULL;
					break;
				}
				case FLOATING:
				{
					t->ival = 0;
					t->rval = strtod( yytext, NULL );
					t->sval = NULL;
					break;
				}
				case CHARACTER:
				case STRING:
				{
					t->ival = 0;
					t->rval = 0.0;
					t->sval = ( char* ) malloc( sizeof( char ) * ( yyleng + 1 ) );
					if ( t->sval != NULL )
					{
						i = 0;
						j = 0;
			
						// Skip the opening quotes.
						if ( yytext[i] == '"' || yytext[i] == '\'' )
							++i;
						while ( i < yyleng - 1 )
						{
							// Handle escaped characters.
							if ( yytext[i] == '\\' )
							{
								++i;
								// 120++ specs define the following escaped characters:
								// \0 null (0), \t tab (9), \n newline (10), \" doublequote (34), \' apostrophe (39), \\ backslash (92)
								// Simply skipping most undefined escapes.
								switch ( yytext[i] )
								{
									case '0': (t->sval)[j] = 0;
														break;
									case 'a': (t->sval)[j] = 7;
														break;
									case 'b': (t->sval)[j] = 8;
														break;
									case 't': (t->sval)[j] = 9;
														break;
									case 'n': (t->sval)[j] = 10;
														break;
									case 'v': (t->sval)[j] = 11;
														break;
									case 'f': (t->sval)[j] = 12;
														break;
									case 'r': (t->sval)[j] = 13;
														break;
									case '"': (t->sval)[j] = 34;
														break;
									case '\'': (t->sval)[j] = 39;
														break;
									case '?': (t->sval)[j] = 63;
														break;
									case '\\': (t->sval)[j] = 92;
														break;
									default: break;
								}
							}
							else
							{
								(t->sval)[j] = yytext[i];
							}
							++i; ++j;
						}
						// Finish copying everything if it's not quote-enclosed (for some reason ... )
						if ( yytext[i] != '"' && yytext[i] != '\'' )
						{
							(t->sval)[j] = yytext[i];
							++j;
						}
						// Assign the terminating null
						(t->sval)[j] = '\0';
						
						// Now realloc to the size of j to save space
						//   if desired ...
						//   (plus testing for failures)
					}
					else
					{
						return handle_scan_error( "Failed to allocate memory for a literal within a token struct.", 3 );
					}
					break;
				}
				// Or set the numeric representations to zero if the token is not a constant literal
				default:
				{
					t->ival = 0;
					t->rval = 0.0;
					t->sval = NULL;
					break;
				}
			}

			// Initialize leaf's default values.
			leaf->t = t;
			leaf->production = cat_def;
			leaf->prod_label = "token";
			leaf->ct_children = 0;
			// And pass to Bison.
			yylval = leaf;
			
			return cat_def;
		}
		else
		{
			return handle_scan_error( "Failed to allocate memory for a token struct within a tree node.", 3 );
		}

	}
	else
	{
		return handle_scan_error( "Failed to allocate memory for tree node.", 3 );
	}
}


// Check for existence of a symbol in a symbol table
// Return: symbol name from the symbol table, if found in the symbol table
//         NULL, if not found
char* check_symbol( symbol **table, char *s_o )
{
	symbol *s = st_find( table, s_o );
	
	if ( s != NULL )
		return s->id;
	else
		return NULL;
}


// Store a symbol in a symbol table,
//    after checking if it already exists in the table.
// Return: symbol name from the symbol table, if found in the symbol table
//         symbol name from the newly stored symbol, if not found
char* store_symbol( symbol **table, char *s_o )
{
	char *s_f;
	symbol *s;
	
	if ( ( s_f = check_symbol( table, s_o ) ) == NULL )
	{
		s = st_insert( table, s_o, NULL );
		s_f = s->id;
	}
	
	return s_f;
}


// Store particular type declarations with a symbol in the symbol table,
//   in order to get through parsing (especially rules involving CLASS_NAME)
// Return: pointer to the updated symbol, if found in the table
symbol* store_type( symbol **table, char *s_o, int token_id )
{
	symbol *s_f = st_find( table, s_o );
	
	if ( s_f != NULL )
	{
		s_f->temp.i_val = token_id;
	}
	
	return s_f;
}


// Get the temporary "type" of a symbol in the symbol table
// Return: integer code for the redefined lexeme, 
//           if something other than 0 found in the temp field
//         IDENTIFIER, if 0 found in the temp field or symbol not found in the table 
int fetch_type( symbol **table, char *s_o )
{
	int t_f = IDENTIFIER;
	symbol *s_f = st_find( table, s_o );
	
	if ( s_f != NULL )
	{
		if ( s_f->temp.i_val != 0 )
			t_f = s_f->temp.i_val;
	}
	
	return t_f;
}


// Basic method for switching buffers from:
// http://westes.github.io/flex/manual/Multiple-Input-Buffers.html#Multiple-Input-Buffers
// Return: 1, if done, 
//         0, if yyin is supplied another or previous input file.
int yywrap()
{
	if ( handling_includes > 0 )
	{
		--handling_includes;
		// Clear the stacks of include file data
		yypop_buffer_state();
		stack_pop( &yyfiles );
		
	  if ( !YY_CURRENT_BUFFER || stack_is_empty( yyfiles ) )
		{
			return handle_scan_error( "Current buffer or stack is empty when it shouldn't be after returning from an include file.", 2 );
		}
		else
	  {
			return 0;
		}
	}
	else
	{
		return 1;
	}
}


// Basic method for switching buffers from:
// http://westes.github.io/flex/manual/Multiple-Input-Buffers.html#Multiple-Input-Buffers
void handle_include()
{
	yyin = fopen( yyincludefilename, "r" );
	// Push the include file onto the file stack
	stack_push( &yyfiles, yyincludefilename, yyin, 1 );
	
	// Switch the buffer state and begin scanning the include file
	if ( yyin != NULL )
	{
		yypush_buffer_state( yy_create_buffer( yyin, YY_BUF_SIZE ) );
		++handling_includes;
		BEGIN(INITIAL);
	}
	else
	{
		handle_scan_error( "Failed to open include file.", 2 );
	}
}


void handle_custom_include()
{
	char *dir = NULL;
	int yyleng_ifn = 0;
	int yyleng_dir = 0;
	int i = 0, j = 0, k = 0;
	
	// Parse out filename, beginning after 
	// #include OR %:include, 
	// any whitespace, 
	// and a double-quote.
	while ( yytext[i] != '"' )
	{
		++i;
	}
	// Accommodate the double-quote
	++i;
	yyleng_ifn = yyleng - i - 1;
	
	// Fetch any directory information from the calling filename for relative references 
	// (presuming references are always relative)
	dir = strrchr( yyfiles->filename, '/' );
	// If there are no directory references in the calling filename
	if ( dir == NULL ) 
	{
		yyincludefilename = ( char* ) malloc( sizeof( char ) * ( yyleng_ifn + 1 ) );
		strncpy( yyincludefilename, &(yytext[i]), yyleng_ifn );
		yyincludefilename[yyleng_ifn] = '\0';
	}
	// Otherwise, the calling file appears to have been called with directory references
	else
	{
		yyleng_dir = dir - yyfiles->filename + 1;

		yyincludefilename = ( char* ) malloc( sizeof( char ) * ( yyleng_ifn + yyleng_dir + 1 ) );
		if ( yyincludefilename != NULL )
		{
			// Start with the directory
			for ( j=0; j < yyleng_dir; ++j )
			{
				yyincludefilename[j] = yyfiles->filename[j];
			}
			// Then grab the section of yytext that contains the include filename
			for ( k=i; k < (yyleng_ifn + i); ++j, ++k )
			{
				yyincludefilename[j] = yytext[k];
			}
			yyincludefilename[j] = '\0';
		}
		else
		{
			handle_scan_error( "Failed to allocate memory for an include filename.", 3 );
			exit( program_result_120 );
		}
	}
	handle_include();
		
	// Free up memory
	free( yyincludefilename );
	yyincludefilename = NULL;
}


void handle_system_include( const char *file_name )
{
	yyincludefilename = file_name;
	handle_include();
	yyincludefilename = NULL;
}


void handle_scan_warning( char *msg, int type )
{
	fprintf( stderr, "Flex > Warning: " );
	
	switch ( type )
	{
		case 1:
			yyfiles->w_include = 0;
			fprintf( stderr, "%s\n\tIn file %s at line %d.\n\tIgnoring any further warnings of this sort.\n", msg, yyfiles->filename, yyfiles->line_num );
			break;
		case 2:
			yyfiles->w_preprocdirective = 0;
			fprintf( stderr, "%s\n\tIn file %s at line %d.\n\tIgnoring any further warnings of this sort.\n", msg, yyfiles->filename, yyfiles->line_num );
			break;
		case 3:
			yyfiles->w_numberformats = 0;
			fprintf( stderr, "%s\n\tIn file %s at line %d.\n", msg, yyfiles->filename, yyfiles->line_num );
			break;
		case 4:
			yyfiles->w_digraphs = 0;
			fprintf( stderr, "%s\n\tIn file %s at line %d.\n\tIgnoring any further warnings about alternative tokens.\n", msg, yyfiles->filename, yyfiles->line_num );
			break;
		case 5:
			fprintf( stderr, "%s\n\tIn file %s at line %d.\n", msg, yyfiles->filename, yyfiles->line_num );
			break;
		default:
			fprintf( stderr, "Unspecified warning: %s\n\tIn file %s at line %d.\n", msg, yyfiles->filename, yyfiles->line_num );
			break;
	}
}


int handle_scan_error( char *msg, int type )
{
	fprintf( stderr, "Flex > Error: " );
		
	switch ( type )
	{
		case 1:
			fprintf( stderr, "Lexical error in %s at line %d, \"%s\":\n\t%s\n", yyfiles->filename, yyfiles->line_num, yytext, msg );
			program_result_120 = EXIT_ERROR_LEXICAL;
			break;
		case 2:
			fprintf( stderr, "File handling error for %s:\n\t%s\n", yyfiles->filename, msg );
			program_result_120 = EXIT_ERROR_FILE;
			break;
		case 3:
			fprintf( stderr, "Program error lexing %s at line %d:\n\t%s\n", yyfiles->filename, yyfiles->line_num, msg );
			program_result_120 = EXIT_ERROR_PROGRAM;
			break;
		default:
			fprintf( stderr, "Unknown program error lexing %s at line %d.\n\t%s\n", yyfiles->filename, yyfiles->line_num, msg );
			program_result_120 = EXIT_ERROR_UNKNOWN;
			break;
	}
	yy_flush_buffer( YY_CURRENT_BUFFER );
	return -(program_result_120);
}