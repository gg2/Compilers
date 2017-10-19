/*
 * Grammar for 120++, a subset of C++ used in CS 120 at University of Idaho
 *
 * Adaptation by Clinton Jeffery, with help from Matthew Brown, Ranger
 * Adams, and Shea Newton.
 *
 * Based on Sandro Sigala's transcription of the ISO C++ 1996 draft standard.
 * 
 */

/*	$Id: parser.y,v 1.3 1997/11/19 15:13:16 sandro Exp $	*/

/*
 * Copyright (c) 1997 Sandro Sigala <ssigala@globalnet.it>.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
 * ISO C++ parser.
 *
 * Based on the ISO C++ draft standard of December '96.
 */

%{

//#define YYDEBUG 1

#include <stdio.h>
#include <string.h>
#include "120++nonterms.h"
#include "globals.h"

int yydebug=0;
static const short W_PARSE_UNSUPPORTED = 1;
static const short W_PARSE_UNHANDLED = 2;

extern int yylex(void);
void handle_parse_warning(char *msg,short warning_type);
static void yyerror(char *msg);

%}


%define api.value.type { tree* }
/*
%union {
	tree *node;
}
*/

%token IDENTIFIER INTEGER FLOATING CHARACTER STRING
%token TYPEDEF_NAME NAMESPACE_NAME CLASS_NAME ENUM_NAME TEMPLATE_NAME

%token ELLIPSIS COLONCOLON DOTSTAR 
%token ADDEQ SUBEQ MULEQ DIVEQ MODEQ ANDEQ OREQ XOREQ SL SLEQ SR SREQ 
%token EQ LTEQ GTEQ NOTEQ ANDAND OROR
%token PLUSPLUS MINUSMINUS ARROWSTAR ARROW

%token ALIGNAS ALIGNOF ASM AUTO 
%token BOOL BREAK 
%token CASE CATCH CHAR CHAR16_T CHAR32_T CLASS CONST CONST_CAST CONST_EXPR CONTINUE
%token DECLTYPE DEFAULT DELETE DO DOUBLE DYNAMIC_CAST 
%token ELSE ENUM EXPLICIT EXPORT EXTERN
%token FALSE FLOAT FOR FRIEND 
%token GOTO IF INLINE INT LONG 
%token MUTABLE 
%token NAMESPACE NEW NOEXCEPT NULLPTR
%token OPERATOR PRIVATE PROTECTED PUBLIC REGISTER REINTERPRET_CAST RETURN
%token SHORT SIGNED SIZEOF STATIC STATIC_ASSERT STATIC_CAST STRUCT SWITCH 
%token TEMPLATE THIS THREAD_LOCAL THROW TRUE TRY TYPEDEF TYPEID TYPENAME 
%token UNION UNSIGNED USING 
%token VIRTUAL VOID VOLATILE WCHAR_T WHILE

%start program_start

%%

/*----------------------------------------------------------------------
 * Context-dependent identifiers.
 *----------------------------------------------------------------------*/

typedef_name:
	/* identifier */
	TYPEDEF_NAME { yylval->production = typedef_name; $$ = $1; }
	;

namespace_name:
	original_namespace_name { $$ = pt_generate_node( namespace_name, "namespace_name", 1, $1 ); }
	;

original_namespace_name:
	/* identifier */
	NAMESPACE_NAME { yylval->production = original_namespace_name; $$ = $1; }
	;

class_name:
	/* identifier */
	CLASS_NAME { yylval->production = class_name; $$ = $1; }
	| template_id { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( class_name+2, "class_name_2", 1, $1 ); }
	;

enum_name:
	/* identifier */
	ENUM_NAME { yylval->production = enum_name; $$ = $1; }
	;

template_name:
	/* identifier */
	TEMPLATE_NAME { /* !Not 120++! */ yylval->production = template_name; $$ = $1; }
	;

/*----------------------------------------------------------------------
 * Lexical elements.
 *----------------------------------------------------------------------*/

identifier:
	IDENTIFIER { yylval->production = identifier; $$ = $1; }
	;

literal:
	integer_literal { $$ = pt_generate_node( literal+1, "literal_1", 1, $1 ); }
	| character_literal { $$ = pt_generate_node( literal+2, "literal_2", 1, $1 ); }
	| floating_literal { $$ = pt_generate_node( literal+3, "literal_3", 1, $1 ); }
	| string_literal { $$ = pt_generate_node( literal+4, "literal_4", 1, $1 ); }
	| boolean_literal { $$ = pt_generate_node( literal+5, "literal_5", 1, $1 ); }
	;

integer_literal:
	INTEGER { yylval->production = integer_literal; $$ = $1; }
	;

character_literal:
	CHARACTER { yylval->production = character_literal; $$ = $1; }
	;

floating_literal:
	FLOATING { yylval->production = floating_literal; $$ = $1; }
	;

string_literal:
	STRING { yylval->production = string_literal; $$ = $1; }
	;

boolean_literal:
	TRUE { yylval->production = boolean_literal+1; $$ = $1; }
	| FALSE { yylval->production = boolean_literal+2; $$ = $1; }
	;

/*----------------------------------------------------------------------
 * Program start.
 *----------------------------------------------------------------------*/

program_start:
	declaration_seq_opt { yyparsetree = pt_generate_node( program_start, "program_start", 1, $1 ); }
	;

/*----------------------------------------------------------------------
 * Epsilon (optional) definitions.
 *     (Unsupported optional rules are not warned, though their specific target may be.)
 *----------------------------------------------------------------------*/

declaration_seq_opt:
	/* epsilon */ { $$ = NULL; }
	| declaration_seq { $$ = pt_generate_node( declaration_seq_opt+1, "declaration_seq_opt", 1, $1 ); }
	;

statement_seq_opt:
	/* epsilon */ { $$ = NULL; }
	| statement_seq { $$ = pt_generate_node( statement_seq_opt+1, "statement_seq_opt", 1, $1 ); }
	;

expression_list_opt:
	/* epsilon */ { $$ = NULL; }
	| expression_list { $$ = pt_generate_node( expression_list_opt+1, "expression_list_opt", 1, $1 ); }
	;

constant_expression_opt:
	/* epsilon */ { $$ = NULL; }
	| constant_expression { $$ = pt_generate_node( constant_expression_opt+1, "constant_expression_opt", 1, $1 ); }
	;

condition_opt:
	/* epsilon */ { $$ = NULL; }
	| condition { $$ = pt_generate_node( condition_opt+1, "condition_opt", 1, $1 ); }
	;

assignment_expression_opt:
	/* epsilon */ { $$ = NULL; }
	| assignment_expression { /* !Not 120++! */ $$ = pt_generate_node( assignment_expression_opt+1, "assignment_expression_opt", 1, $1 ); }
	;

new_placement_opt:
	/* epsilon */ { $$ = NULL; }
	| new_placement { $$ = pt_generate_node( new_placement_opt+1, "new_placement_opt", 1, $1 ); }
	;

new_initializer_opt:
	/* epsilon */ { $$ = NULL; }
	| new_initializer { $$ = pt_generate_node( new_initializer_opt+1, "new_initializer_opt", 1, $1 ); }
	;

new_declarator_opt:
	/* epsilon */ { $$ = NULL; }
	| new_declarator { $$ = pt_generate_node( new_declarator_opt+1, "new_declarator_opt", 1, $1 ); }
	;

nested_name_specifier_opt:
	/* epsilon */ { $$ = NULL; }
	| nested_name_specifier { $$ = pt_generate_node( nested_name_specifier_opt+1, "nested_name_specifier_opt", 1, $1 ); }
	;

initializer_opt:
	/* epsilon */ { $$ = NULL; }
	| initializer { $$ = pt_generate_node( initializer_opt+1, "initializer_opt", 1, $1 ); }
	;

ctor_initializer_opt:
	/* epsilon */ { $$ = NULL; }
	| ctor_initializer { /* !Not 120++! */ $$ = pt_generate_node( ctor_initializer_opt+1, "ctor_initializer_opt", 1, $1 ); }
	;

type_specifier_seq_opt:
	/* epsilon */ { $$ = NULL; }
	| type_specifier_seq { $$ = pt_generate_node( type_specifier_seq_opt+1, "type_specifier_seq_opt", 1, $1 ); }
	;

type_id_list_opt:
	/* epsilon */ { $$ = NULL; }
	| type_id_list { /* !Not 120++! */ $$ = pt_generate_node( type_id_list_opt+1, "type_id_list_opt", 1, $1 ); }
	;

abstract_declarator_opt:
	/* epsilon */ { $$ = NULL; }
	| abstract_declarator { $$ = pt_generate_node( abstract_declarator_opt+1, "abstract_declarator_opt", 1, $1 ); }
	;

direct_abstract_declarator_opt:
	/* epsilon */ { $$ = NULL; }
	| direct_abstract_declarator { $$ = pt_generate_node( direct_abstract_declarator_opt+1, "direct_abstract_declarator_opt", 1, $1 ); }
	;

parameter_declaration_clause_opt:
	/* epsilon */ { $$ = NULL; }
	| parameter_declaration_clause { $$ = pt_generate_node( parameter_declaration_clause_opt+1, "parameter_declaration_clause_opt", 1, $1 ); }
	;

enumerator_list_opt:
	/* epsilon */ { $$ = NULL; }
	| enumerator_list { /* !Not 120++! */ $$ = pt_generate_node( enumerator_list_opt+1, "enumerator_list_opt", 1, $1 ); }
	;

member_specification_opt:
	/* epsilon */ { $$ = NULL; }
	| member_specification { $$ = pt_generate_node( member_specification_opt+1, "member_specification_opt", 1, $1 ); }
	;

handler_seq_opt:
	/* epsilon */ { $$ = NULL; }
	| handler_seq { /* !Not 120++! */ $$ = pt_generate_node( handler_seq_opt+1, "handler_seq_opt", 1, $1 ); }
	;

conversion_declarator_opt:
	/* epsilon */ { $$ = NULL; }
	| conversion_declarator { /* !Not 120++! */ $$ = pt_generate_node( conversion_declarator_opt+1, "conversion_declarator_opt", 1, $1 ); }
	;

EXPORT_opt:
	/* epsilon */ { $$ = NULL; }
	| EXPORT { /* !Not 120++! */ $$ = pt_generate_node( EXPORT_opt+1, "EXPORT_opt", 1, $1 ); }
	;

COMMA_opt:
	/* epsilon */ { $$ = NULL; }
	| ',' { $$ = pt_generate_node( COMMA_opt+1, "COMMA_opt", 1, $1 ); }
	;
	
COLONCOLON_opt:
	/* epsilon */ { $$ = NULL; }
	| COLONCOLON { /* !Not 120++! */ $$ = pt_generate_node( COLONCOLON_opt+1, "COLONCOLON_opt", 1, $1 ); }
	;

SEMICOLON_opt:
	/* epsilon */ { $$ = NULL; }
	| ';' { $$ = pt_generate_node( SEMICOLON_opt+1, "SEMICOLON_opt", 1, $1 ); }
	;

/*----------------------------------------------------------------------
 * Expressions.
 *----------------------------------------------------------------------*/

primary_expression:
	literal { $$ = pt_generate_node( primary_expression+1, "primary_expression_1", 1, $1 ); }
	| THIS { $$ = pt_generate_node( primary_expression+2, "primary_expression_2", 1, $1 ); }
	| '(' expression_list ')' { $$ = pt_generate_node( primary_expression+3, "primary_expression_3", 3, $1, $2, $3 ); }
	| id_expression { $$ = pt_generate_node( primary_expression+4, "primary_expression_4", 1, $1 ); }
	;

id_expression:
	unqualified_id { $$ = pt_generate_node( id_expression+1, "id_expression_1", 1, $1 ); }
	| qualified_id { $$ = pt_generate_node( id_expression+2, "id_expression_2", 1, $1 ); }
	;

unqualified_id:
	identifier { $$ = pt_generate_node( unqualified_id+1, "unqualified_id_1", 1, $1 ); }
	| operator_function_id { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( unqualified_id+2, "unqualified_id_2", 1, $1 ); }
	| conversion_function_id { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( unqualified_id+3, "unqualified_id_3", 1, $1 ); }
	| '~' class_name { /* !Not 120++! */ handle_parse_warning( "Class destructor operator is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( unqualified_id+4, "unqualified_id_4", 2, $1, $2 ); }
	;

qualified_id:
	nested_name_specifier unqualified_id { $$ = pt_generate_node( qualified_id+1, "qualified_id_1", 2, $1, $2 ); }
	| nested_name_specifier TEMPLATE unqualified_id { /* !Not 120++! */ handle_parse_warning( "Templates are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( qualified_id+2, "qualified_id_2", 3, $1, $2, $3 ); }
	;

nested_name_specifier:
	class_name COLONCOLON nested_name_specifier { $$ = pt_generate_node( nested_name_specifier+1, "nested_name_specifier_1", 3, $1, $2, $3 ); }
	| namespace_name COLONCOLON nested_name_specifier { $$ = pt_generate_node( nested_name_specifier+2, "nested_name_specifier_2", 3, $1, $2, $3 ); }
	| class_name COLONCOLON { $$ = pt_generate_node( nested_name_specifier+3, "nested_name_specifier_3", 2, $1, $2 ); }
	| namespace_name COLONCOLON { $$ = pt_generate_node( nested_name_specifier+4, "nested_name_specifier_4", 2, $1, $2 ); }
	;

postfix_expression:
	primary_expression { $$ = pt_generate_node( postfix_expression+1, "postfix_expression_1", 1, $1 ); }
	| postfix_expression '[' expression_list ']' { $$ = pt_generate_node( postfix_expression+2, "postfix_expression_2", 4, $1, $2, $3, $4 ); }
	| postfix_expression '(' expression_list_opt ')' { $$ = pt_generate_node( postfix_expression+3, "postfix_expression_3", 4, $1, $2, $3, $4 ); }
	| BOOL '(' expression_list_opt ')' { $$ = pt_generate_node( postfix_expression+4, "postfix_expression_4", 4, $1, $2, $3, $4 ); }
	| CHAR '(' expression_list_opt ')' { $$ = pt_generate_node( postfix_expression+5, "postfix_expression_5", 4, $1, $2, $3, $4 ); }
	| SHORT '(' expression_list_opt ')' { $$ = pt_generate_node( postfix_expression+6, "postfix_expression_6", 4, $1, $2, $3, $4 ); }
	| INT '(' expression_list_opt ')' { $$ = pt_generate_node( postfix_expression+7, "postfix_expression_7", 4, $1, $2, $3, $4 ); }
	| LONG '(' expression_list_opt ')' { $$ = pt_generate_node( postfix_expression+8, "postfix_expression_8", 4, $1, $2, $3, $4 ); }
	| DOUBLE '(' expression_list_opt ')' { $$ = pt_generate_node( postfix_expression+9, "postfix_expression_9", 4, $1, $2, $3, $4 ); }
	| FLOAT '(' expression_list_opt ')' { $$ = pt_generate_node( postfix_expression+10, "postfix_expression_10", 4, $1, $2, $3, $4 ); }
	| postfix_expression '.' TEMPLATE COLONCOLON id_expression { /* !Not 120++! */ handle_parse_warning( "Templates are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( postfix_expression+12, "postfix_expression_12", 5, $1, $2, $3, $4, $5 ); }
	| postfix_expression '.' TEMPLATE id_expression { /* !Not 120++! */ handle_parse_warning( "Templates are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( postfix_expression+13, "postfix_expression_13", 4, $1, $2, $3, $4 ); }
	| postfix_expression '.' COLONCOLON id_expression { /* !Not 120++! */ handle_parse_warning( ":: is not a supported feature in this context in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( postfix_expression+14, "postfix_expression_14", 4, $1, $2, $3, $4 ); }
	| postfix_expression '.' id_expression { $$ = pt_generate_node( postfix_expression+15, "postfix_expression_15", 3, $1, $2, $3 ); }
	| postfix_expression ARROW TEMPLATE COLONCOLON id_expression { /* !Not 120++! */ handle_parse_warning( "Templates are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( postfix_expression+16, "postfix_expression_16", 5, $1, $2, $3, $4, $5 ); }
	| postfix_expression ARROW TEMPLATE id_expression { /* !Not 120++! */ handle_parse_warning( "Templates are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( postfix_expression+17, "postfix_expression_17", 4, $1, $2, $3, $4 ); }
	| postfix_expression ARROW COLONCOLON id_expression { /* !Not 120++! */ handle_parse_warning( ":: is not a supported feature in this context in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( postfix_expression+18, "postfix_expression_18", 4, $1, $2, $3, $4 ); }
	| postfix_expression ARROW id_expression { $$ = pt_generate_node( postfix_expression+19, "postfix_expression_19", 3, $1, $2, $3 ); }
	| postfix_expression PLUSPLUS { $$ = pt_generate_node( postfix_expression+20, "postfix_expression_20", 2, $1, $2 ); }
	| postfix_expression MINUSMINUS { $$ = pt_generate_node( postfix_expression+21, "postfix_expression_21", 2, $1, $2 ); }
	| DYNAMIC_CAST '<' type_id '>' '(' expression_list ')' { /* !Not 120++! */ handle_parse_warning( "dynamic_cast is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( postfix_expression+22, "postfix_expression_22", 7, $1, $2, $3, $4, $5, $6, $7 ); }
	| STATIC_CAST '<' type_id '>' '(' expression_list ')' { /* !Not 120++! */ handle_parse_warning( "static_cast is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( postfix_expression+23, "postfix_expression_23", 7, $1, $2, $3, $4, $5, $6, $7 ); }
	| REINTERPRET_CAST '<' type_id '>' '(' expression_list ')' { /* !Not 120++! */ handle_parse_warning( "reinterpret_cast is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( postfix_expression+24, "postfix_expression_24", 7, $1, $2, $3, $4, $5, $6, $7 ); }
	| CONST_CAST '<' type_id '>' '(' expression_list ')' { /* !Not 120++! */ handle_parse_warning( "const_cast is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( postfix_expression+25, "postfix_expression_25", 7, $1, $2, $3, $4, $5, $6, $7 ); }
	| TYPEID '(' expression_list ')' { /* !Not 120++! */ handle_parse_warning( "typeid is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( postfix_expression+26, "postfix_expression_26", 4, $1, $2, $3, $4 ); }
	| TYPEID '(' type_id ')' { /* !Not 120++! */ handle_parse_warning( "typeid is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( postfix_expression+27, "postfix_expression_27", 4, $1, $2, $3, $4 ); }
	;

unary_expression:
	postfix_expression { $$ = pt_generate_node( unary_expression+1, "unary_expression_1", 1, $1 ); }
	| PLUSPLUS cast_expression { $$ = pt_generate_node( unary_expression+2, "unary_expression_2", 2, $1, $2 ); }
	| MINUSMINUS cast_expression { $$ = pt_generate_node( unary_expression+3, "unary_expression_3", 2, $1, $2 ); }
	| '*' cast_expression { $$ = pt_generate_node( unary_expression+4, "unary_expression_4", 2, $1, $2 ); }
	| '&' cast_expression { $$ = pt_generate_node( unary_expression+5, "unary_expression_5", 2, $1, $2 ); }
	| unary_operator cast_expression { $$ = pt_generate_node( unary_expression+6, "unary_expression_6", 2, $1, $2 ); }
	| SIZEOF unary_expression { $$ = pt_generate_node( unary_expression+7, "unary_expression_7", 2, $1, $2 ); }
	| SIZEOF '(' type_id ')' { $$ = pt_generate_node( unary_expression+8, "unary_expression_8", 4, $1, $2, $3, $4 ); }
	| new_expression { $$ = pt_generate_node( unary_expression+9, "unary_expression_9", 1, $1 ); }
	| delete_expression { $$ = pt_generate_node( unary_expression+10, "unary_expression_10", 1, $1 ); }
	;

unary_operator:
	'+' { yylval->production = unary_operator+1; $$ = $1; }
	| '-' { yylval->production = unary_operator+2; $$ = $1; }
	| '!' { yylval->production = unary_operator+3; $$ = $1; }
	| '~' { yylval->production = unary_operator+4; $$ = $1; }
	;

new_expression:
	NEW new_placement_opt new_type_id new_initializer_opt { $$ = pt_generate_node( new_expression+1, "new_expression_1", 4, $1, $2, $3, $4 ); }
	| COLONCOLON NEW new_placement_opt new_type_id new_initializer_opt { /* !Not 120++! */ handle_parse_warning( "This usage of new is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( new_expression+2, "new_expression_2", 5, $1, $2, $3, $4, $5 ); }
	| NEW new_placement_opt '(' type_id ')' new_initializer_opt { $$ = pt_generate_node( new_expression+3, "new_expression_3", 6, $1, $2, $3, $4, $5, $6 ); }
	| COLONCOLON NEW new_placement_opt '(' type_id ')' new_initializer_opt { /* !Not 120++! */ handle_parse_warning( "This usage of new is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( new_expression+4, "new_expression_4", 7, $1, $2, $3, $4, $5, $6, $7 ); }
	;

new_placement:
	'(' expression_list ')' { $$ = pt_generate_node( new_placement, "new_placement", 3, $1, $2, $3 ); }
	;

new_type_id:
	type_specifier_seq new_declarator_opt { $$ = pt_generate_node( new_type_id, "new_type_id", 2, $1, $2 ); }
	;

new_declarator:
	ptr_operator new_declarator_opt { $$ = pt_generate_node( new_declarator+1, "new_declarator_1", 2, $1, $2 ); }
	| direct_new_declarator { /* ?Not 120++? */ $$ = pt_generate_node( new_declarator+2, "new_declarator_2", 1, $1 ); }
	;

direct_new_declarator:
	'[' expression_list ']' { /* ?Not 120++? */ /* Warned above */ $$ = pt_generate_node( direct_new_declarator+1, "direct_new_declarator_1", 3, $1, $2, $3 ); }
	| direct_new_declarator '[' constant_expression ']' { /* ?Not 120++? */ /* Warned above */ $$ = pt_generate_node( direct_new_declarator+2, "direct_new_declarator_2", 4, $1, $2, $3, $4 ); }
	;

new_initializer:
	'(' expression_list_opt ')' { $$ = pt_generate_node( new_initializer, "new_initializer", 3, $1, $2, $3 ); }
	;

delete_expression:
	DELETE cast_expression { $$ = pt_generate_node( delete_expression+1, "delete_expression_1", 2, $1, $2 ); }
	| COLONCOLON DELETE cast_expression { /* !Not 120++! */ handle_parse_warning( "This usage of delete is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( delete_expression+2, "delete_expression_2", 3, $1, $2, $3 ); }
	| DELETE '[' ']' cast_expression { $$ = pt_generate_node( delete_expression+3, "delete_expression_3", 4, $1, $2, $3, $4 ); }
	| COLONCOLON DELETE '[' ']' cast_expression { /* !Not 120++! */ handle_parse_warning( "This usage of delete is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( delete_expression+4, "delete_expression_4", 5, $1, $2, $3, $4, $5 ); }
	;

cast_expression:
	unary_expression { $$ = pt_generate_node( cast_expression+1, "cast_expression_1", 1, $1 ); }
	| '(' type_id ')' cast_expression { $$ = pt_generate_node( cast_expression+2, "cast_expression_2", 4, $1, $2, $3, $4 ); }
	;

pm_expression:
	cast_expression { $$ = pt_generate_node( pm_expression+1, "pm_expression_1", 1, $1 ); }
	| pm_expression DOTSTAR cast_expression { /* !Not 120++! */ handle_parse_warning( "Pointer-to-member operators are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( pm_expression+2, "pm_expression_2", 3, $1, $2, $3 ); }
	| pm_expression ARROWSTAR cast_expression { /* !Not 120++! */ handle_parse_warning( "Pointer-to-member operators are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( pm_expression+3, "pm_expression_3", 3, $1, $2, $3 ); }
	;

multiplicative_expression:
	pm_expression { $$ = pt_generate_node( multiplicative_expression+1, "multiplicative_expression_1", 1, $1 ); }
	| multiplicative_expression '*' pm_expression { $$ = pt_generate_node( multiplicative_expression+2, "multiplicative_expression_2", 3, $1, $2, $3 ); }
	| multiplicative_expression '/' pm_expression { $$ = pt_generate_node( multiplicative_expression+3, "multiplicative_expression_3", 3, $1, $2, $3 ); }
	| multiplicative_expression '%' pm_expression { $$ = pt_generate_node( multiplicative_expression+4, "multiplicative_expression_4", 3, $1, $2, $3 ); }
	;

additive_expression:
	multiplicative_expression { $$ = pt_generate_node( additive_expression+1, "additive_expression_1", 1, $1 ); }
	| additive_expression '+' multiplicative_expression { $$ = pt_generate_node( additive_expression+2, "additive_expression_2", 3, $1, $2, $3 ); }
	| additive_expression '-' multiplicative_expression { $$ = pt_generate_node( additive_expression+3, "additive_expression_3", 3, $1, $2, $3 ); }
	;

shift_expression:
	additive_expression { $$ = pt_generate_node( shift_expression+1, "shift_expression_1", 1, $1 ); }
	| shift_expression SL additive_expression { /* !Not 120++! */ /* Might be overloaded for cout, but still warned */ handle_parse_warning( "Shift operators are not supported in 120++ specs. (If using them for cout, you're fine.)", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( shift_expression+2, "shift_expression_2", 3, $1, $2, $3 ); }
	| shift_expression SR additive_expression { /* !Not 120++! */ /* Might be overloaded for cin, but still warned */ handle_parse_warning( "Shift operators are not supported in 120++ specs. (If using them for cin, you're fine.)", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( shift_expression+3, "shift_expression_3", 3, $1, $2, $3 ); }
	;

relational_expression:
	shift_expression { $$ = pt_generate_node( relational_expression+1, "relational_expression_1", 1, $1 ); }
	| relational_expression '<' shift_expression { $$ = pt_generate_node( relational_expression+2, "relational_expression_2", 3, $1, $2, $3 ); }
	| relational_expression '>' shift_expression { $$ = pt_generate_node( relational_expression+3, "relational_expression_3", 3, $1, $2, $3 ); }
	| relational_expression LTEQ shift_expression { $$ = pt_generate_node( relational_expression+4, "relational_expression_4", 3, $1, $2, $3 ); }
	| relational_expression GTEQ shift_expression { $$ = pt_generate_node( relational_expression+5, "relational_expression_5", 3, $1, $2, $3 ); }
	;

equality_expression:
	relational_expression { $$ = pt_generate_node( equality_expression+1, "equality_expression_1", 1, $1 ); }
	| equality_expression EQ relational_expression { $$ = pt_generate_node( equality_expression+2, "equality_expression_2", 3, $1, $2, $3 ); }
	| equality_expression NOTEQ relational_expression { $$ = pt_generate_node( equality_expression+3, "equality_expression_3", 3, $1, $2, $3 ); }
	;

and_expression:
	equality_expression { $$ = pt_generate_node( and_expression+1, "and_expression_1", 1, $1 ); }
	| and_expression '&' equality_expression { /* !Not 120++! */ handle_parse_warning( "Bitwise operators are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( and_expression+2, "and_expression_2", 3, $1, $2, $3 ); }
	;

exclusive_or_expression:
	and_expression { $$ = pt_generate_node( exclusive_or_expression+1, "exclusive_or_expression_1", 1, $1 ); }
	| exclusive_or_expression '^' and_expression { /* !Not 120++! */ handle_parse_warning( "Bitwise operators are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( exclusive_or_expression+2, "exclusive_or_expression_2", 3, $1, $2, $3 ); }
	;

inclusive_or_expression:
	exclusive_or_expression { $$ = pt_generate_node( inclusive_or_expression+1, "inclusive_or_expression_1", 1, $1 ); }
	| inclusive_or_expression '|' exclusive_or_expression { /* !Not 120++! */ handle_parse_warning( "Bitwise operators are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( inclusive_or_expression+2, "inclusive_or_expression_2", 3, $1, $2, $3 ); }
	;

logical_and_expression:
	inclusive_or_expression { $$ = pt_generate_node( logical_and_expression+1, "logical_and_expression_1", 1, $1 ); }
	| logical_and_expression ANDAND inclusive_or_expression { $$ = pt_generate_node( logical_and_expression+2, "logical_and_expression_2", 3, $1, $2, $3 ); }
	;

logical_or_expression:
	logical_and_expression { $$ = pt_generate_node( logical_or_expression+1, "logical_or_expression_1", 1, $1 ); }
	| logical_or_expression OROR logical_and_expression { $$ = pt_generate_node( logical_or_expression+2, "logical_or_expression_2", 3, $1, $2, $3 ); }
	;

conditional_expression:
	logical_or_expression { $$ = pt_generate_node( conditional_expression+1, "conditional_expression_1", 1, $1 ); }
	| logical_or_expression '?' expression_list ':' assignment_expression { $$ = pt_generate_node( conditional_expression+2, "conditional_expression_2", 5, $1, $2, $3, $4, $5 ); }
	;

constant_expression:
	conditional_expression { $$ = pt_generate_node( constant_expression, "constant_expression", 1, $1 ); }
	;

assignment_expression:
	conditional_expression { $$ = pt_generate_node( assignment_expression+1, "assignment_expression_1", 1, $1 ); }
	| logical_or_expression assignment_operator assignment_expression { $$ = pt_generate_node( assignment_expression+2, "assignment_expression_2", 3, $1, $2, $3 ); }
	| throw_expression { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( assignment_expression+3, "assignment_expression_3", 1, $1 ); }
	;

assignment_operator:
	'=' { yylval->production = assignment_operator+1; $$ = $1; }
	| MULEQ { yylval->production = assignment_operator+2; $$ = $1; }
	| DIVEQ { yylval->production = assignment_operator+3; $$ = $1; }
	| MODEQ { yylval->production = assignment_operator+4; $$ = $1; }
	| ADDEQ { yylval->production = assignment_operator+5; $$ = $1; }
	| SUBEQ { yylval->production = assignment_operator+6; $$ = $1; }
	| SREQ { /* !Not 120++! */ handle_parse_warning( "Operator is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = assignment_operator+7; $$ = $1; }
	| SLEQ { /* !Not 120++! */ handle_parse_warning( "Operator is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = assignment_operator+8; $$ = $1; }
	| ANDEQ { /* !Not 120++! */ handle_parse_warning( "Operator is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = assignment_operator+9; $$ = $1; }
	| XOREQ { /* !Not 120++! */ handle_parse_warning( "Operator is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = assignment_operator+10; $$ = $1; }
	| OREQ { /* !Not 120++! */ handle_parse_warning( "Operator is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = assignment_operator+11; $$ = $1; }
	;

expression_list:
	assignment_expression { $$ = pt_generate_node( expression_list+1, "expression_list_1", 1, $1 ); }
	| expression_list ',' assignment_expression { $$ = pt_generate_node( expression_list+2, "expression_list_2", 3, $1, $2, $3 ); }
	;

/*----------------------------------------------------------------------
 * Statements.
 *----------------------------------------------------------------------*/

statement:
	labeled_statement { $$ = pt_generate_node( statement+1, "statement_1", 1, $1 ); }
	| expression_statement { $$ = pt_generate_node( statement+2, "statement_2", 1, $1 ); }
	| compound_statement { $$ = pt_generate_node( statement+3, "statement_3", 1, $1 ); }
	| selection_statement { $$ = pt_generate_node( statement+4, "statement_4", 1, $1 ); }
	| iteration_statement { $$ = pt_generate_node( statement+5, "statement_5", 1, $1 ); }
	| jump_statement { $$ = pt_generate_node( statement+6, "statement_6", 1, $1 ); }
	| declaration_statement { $$ = pt_generate_node( statement+7, "statement_7", 1, $1 ); }
	| try_block { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( statement+8, "statement_8", 1, $1 ); }
	;

labeled_statement:
	identifier ':' statement { /* !Not 120++! */ handle_parse_warning( "This labeled statement syntax is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( labeled_statement+1, "labeled_statement_1", 3, $1, $2, $3 ); }
	| CASE constant_expression ':' statement { $$ = pt_generate_node( labeled_statement+2, "labeled_statement_2", 4, $1, $2, $3, $4 ); }
	| DEFAULT ':' statement { $$ = pt_generate_node( labeled_statement+3, "labeled_statement_3", 3, $1, $2, $3 ); }
	;

expression_statement:
	expression_list_opt ';' { $$ = pt_generate_node( expression_statement, "expression_statement", 2, $1, $2 ); }
	;

compound_statement:
	'{' statement_seq_opt '}' { $$ = pt_generate_node( compound_statement, "compound_statement", 3, $1, $2, $3 ); }
	;

statement_seq:
	statement { $$ = pt_generate_node( statement_seq+1, "statement_seq_1", 1, $1 ); }
	| statement_seq statement { $$ = pt_generate_node( statement_seq+2, "statement_seq_2", 2, $1, $2 ); }
	;

selection_statement:
	IF '(' condition ')' statement { $$ = pt_generate_node( selection_statement+1, "selection_statement_1", 5, $1, $2, $3, $4, $5 ); }
	| IF '(' condition ')' statement ELSE statement { $$ = pt_generate_node( selection_statement+2, "selection_statement_2", 7, $1, $2, $3, $4, $5, $6, $7 ); }
	| SWITCH '(' condition ')' statement { $$ = pt_generate_node( selection_statement+3, "selection_statement_3", 5, $1, $2, $3, $4, $5 ); }
	;

condition:
	expression_list { $$ = pt_generate_node( condition+1, "condition_1", 1, $1 ); }
	| type_specifier_seq declarator '=' assignment_expression { $$ = pt_generate_node( condition+2, "condition_2", 4, $1, $2, $3, $4 ); }
	;

iteration_statement:
	WHILE '(' condition ')' statement { $$ = pt_generate_node( iteration_statement+1, "iteration_statement_1", 5, $1, $2, $3, $4, $5 ); }
	| DO statement WHILE '(' expression_list ')' ';' { $$ = pt_generate_node( iteration_statement+2, "iteration_statement_2", 7, $1, $2, $3, $4, $5, $6, $7 ); }
	| FOR '(' for_init_statement condition_opt ';' expression_list_opt ')' statement { $$ = pt_generate_node( iteration_statement+3, "iteration_statement_3", 8, $1, $2, $3, $4, $5, $6, $7, $8 ); }
	;

for_init_statement:
	expression_statement { $$ = pt_generate_node( for_init_statement+1, "for_init_statement_1", 1, $1 ); }
	| simple_declaration { $$ = pt_generate_node( for_init_statement+2, "for_init_statement_2", 1, $1 ); }
	;

jump_statement:
	BREAK ';' { $$ = pt_generate_node( jump_statement+1, "jump_statement_1", 2, $1, $2 ); }
	| CONTINUE ';' { $$ = pt_generate_node( jump_statement+2, "jump_statement_2", 2, $1, $2 ); }
	| RETURN expression_list_opt ';' { $$ = pt_generate_node( jump_statement+3, "jump_statement_3", 3, $1, $2, $3 ); }
	| GOTO identifier ';' { /* !Not 120++! */ handle_parse_warning( "goto is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( jump_statement+4, "jump_statement_4", 3, $1, $2, $3 ); }
	;

declaration_statement:
	block_declaration { $$ = pt_generate_node( declaration_statement, "declaration_statement", 1, $1 ); }
	;

/*----------------------------------------------------------------------
 * Declarations.
 *----------------------------------------------------------------------*/

declaration_seq:
	declaration { $$ = pt_generate_node( declaration_seq+1, "declaration_seq_1", 1, $1 ); }
	| declaration_seq declaration { $$ = pt_generate_node( declaration_seq+2, "declaration_seq_2", 2, $1, $2 ); }
	;

declaration:
	block_declaration { $$ = pt_generate_node( declaration+1, "declaration_1", 1, $1 ); }
	| function_definition { $$ = pt_generate_node( declaration+2, "declaration_2", 1, $1 ); }
	| template_declaration { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( declaration+3, "declaration_3", 1, $1 ); }
	| explicit_instantiation { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( declaration+4, "declaration_4", 1, $1 ); }
	| explicit_specialization { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( declaration+5, "declaration_5", 1, $1 ); }
	| linkage_specification { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( declaration+6, "declaration_6", 1, $1 ); }
	| namespace_definition { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( declaration+7, "declaration_7", 1, $1 ); }
	;

block_declaration:
	simple_declaration { $$ = pt_generate_node( block_declaration+1, "block_declaration_1", 1, $1 ); }
	| asm_definition { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( block_declaration+2, "block_declaration_2", 1, $1 ); }
	| namespace_alias_definition { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( block_declaration+3, "block_declaration_3", 1, $1 ); }
	| using_declaration { /* !Not 120++! */ handle_parse_warning( "This usage of using is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( block_declaration+4, "block_declaration_4", 1, $1 ); }
	| using_directive { $$ = pt_generate_node( block_declaration+5, "block_declaration_5", 1, $1 ); }
	;

simple_declaration:
	  decl_specifier_seq init_declarator_list ';' { $$ = pt_generate_node( simple_declaration+1, "simple_declaration_1", 3, $1, $2, $3 ); }
	|  decl_specifier_seq ';' { $$ = pt_generate_node( simple_declaration+2, "simple_declaration_2", 2, $1, $2 ); }
	;

decl_specifier:
	storage_class_specifier { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( decl_specifier+1, "decl_specifier_1", 1, $1 ); }
	| type_specifier { $$ = pt_generate_node( decl_specifier+2, "decl_specifier_2", 1, $1 ); }
	| function_specifier { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( decl_specifier+3, "decl_specifier_3", 1, $1 ); }
	| FRIEND { /* !Not 120++! */ handle_parse_warning( "friend is not supported in 120++ specs.", W_PARSE_UNHANDLED ); $$ = NULL; }
	| TYPEDEF { /* !Not 120++! */ handle_parse_warning( "typedef is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = decl_specifier+5; $$ = $1; }
	;

decl_specifier_seq:
	decl_specifier { $$ = pt_generate_node( decl_specifier_seq+1, "decl_specifier_seq_1", 1, $1 ); }
	| decl_specifier_seq decl_specifier { $$ = pt_generate_node( decl_specifier_seq+2, "decl_specifier_seq_2", 2, $1, $2 ); }
	;

storage_class_specifier:
	AUTO { /* !Not 120++! */ handle_parse_warning( "auto is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = storage_class_specifier+1; $$ = $1; }
	| REGISTER { /* !Not 120++! */ handle_parse_warning( "register is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = storage_class_specifier+2; $$ = $1; }
	| STATIC { /* !Not 120++! */ handle_parse_warning( "static is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = storage_class_specifier+3; $$ = $1; }
	| EXTERN { /* !Not 120++! */ handle_parse_warning( "extern is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = storage_class_specifier+4; $$ = $1; }
	| MUTABLE { /* !Not 120++! */ handle_parse_warning( "mutable is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = storage_class_specifier+5; $$ = $1; }
	;

function_specifier:
	INLINE { /* !Not 120++! */ handle_parse_warning( "inline is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = function_specifier+1; $$ = $1; }
	| VIRTUAL { /* !Not 120++! */ handle_parse_warning( "virtual is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = function_specifier+2; $$ = $1; }
	| EXPLICIT { /* !Not 120++! */ handle_parse_warning( "explicit is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = function_specifier+3; $$ = $1; }
	;

type_specifier:
	simple_type_specifier { $$ = pt_generate_node( type_specifier+1, "type_specifier_1", 1, $1 ); }
	| class_specifier { $$ = pt_generate_node( type_specifier+2, "type_specifier_2", 1, $1 ); }
	| enum_specifier { /* !Not 120++! */ handle_parse_warning( "enum is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( type_specifier+3, "type_specifier_3", 1, $1 ); }
	| elaborated_type_specifier { /* !Not 120++! */ handle_parse_warning( "Elaborated type specifiers are not supported in 120++ specs.", W_PARSE_UNHANDLED ); $$ = NULL; }
	| cv_qualifier { $$ = pt_generate_node( type_specifier+5, "type_specifier_5", 1, $1 ); }
	;

simple_type_specifier:
	type_name { $$ = pt_generate_node( simple_type_specifier+1, "simple_type_specifier_1", 1, $1 ); }
	| nested_name_specifier type_name { $$ = pt_generate_node( simple_type_specifier+2, "simple_type_specifier_2", 2, $1, $2 ); }
	| COLONCOLON nested_name_specifier_opt type_name { $$ = pt_generate_node( simple_type_specifier+3, "simple_type_specifier_3", 3, $1, $2, $3 ); }
	| VOID { yylval->production = simple_type_specifier+4; $$ = $1; }
	| BOOL { yylval->production = simple_type_specifier+5; $$ = $1; }
	| CHAR { yylval->production = simple_type_specifier+6; $$ = $1; }
	| CHAR16_T { /* !Not 120++! */ handle_parse_warning( "char16_t is not supported in 120++ specs.", W_PARSE_UNSUPPORTED );yylval->production = simple_type_specifier+7; $$ = $1; }
	| CHAR32_T { /* !Not 120++! */ handle_parse_warning( "char32_t is not supported in 120++ specs.", W_PARSE_UNSUPPORTED );yylval->production = simple_type_specifier+8; $$ = $1; }
	| WCHAR_T { /* !Not 120++! */ handle_parse_warning( "wchar_t is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = simple_type_specifier+9; $$ = $1; }
	| SHORT { yylval->production = simple_type_specifier+10; $$ = $1; }
	| INT { yylval->production = simple_type_specifier+11; $$ = $1; }
	| LONG { yylval->production = simple_type_specifier+12; $$ = $1; }
	| FLOAT { yylval->production = simple_type_specifier+13; $$ = $1; }
	| DOUBLE { yylval->production = simple_type_specifier+14; $$ = $1; }
	| SIGNED { yylval->production = simple_type_specifier+15; $$ = $1; }
	| UNSIGNED { yylval->production = simple_type_specifier+16; $$ = $1; }
	;

type_name:
	class_name { $$ = pt_generate_node( type_name+1, "type_name_1", 1, $1 ); }
	| enum_name { $$ = pt_generate_node( type_name+2, "type_name_2", 1, $1 ); }
	| typedef_name { $$ = pt_generate_node( type_name+3, "type_name_3", 1, $1 ); }
	;

elaborated_type_specifier:
	class_key COLONCOLON nested_name_specifier identifier { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( elaborated_type_specifier+1, "elaborated_type_specifier_1", 4, $1, $2, $3, $4 ); }
	| class_key COLONCOLON identifier { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( elaborated_type_specifier+2, "elaborated_type_specifier_2", 3, $1, $2, $3 ); }
	| ENUM COLONCOLON nested_name_specifier identifier { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( elaborated_type_specifier+3, "elaborated_type_specifier_3", 4, $1, $2, $3, $4 ); }
	| ENUM COLONCOLON identifier { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( elaborated_type_specifier+4, "elaborated_type_specifier_4", 3, $1, $2, $3 ); }
	| ENUM nested_name_specifier identifier { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( elaborated_type_specifier+5, "elaborated_type_specifier_5", 3, $1, $2, $3 ); }
	| TYPENAME COLONCOLON_opt nested_name_specifier identifier { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( elaborated_type_specifier+6, "elaborated_type_specifier_6", 4, $1, $2, $3, $4 ); }
	| TYPENAME COLONCOLON_opt nested_name_specifier identifier '<' template_argument_list '>' { /* !Not 120++! */ /* Warned above */ handle_parse_warning( "Template features are not supported in 120++ specs.", W_PARSE_UNHANDLED ); $$ = pt_generate_node( elaborated_type_specifier+7, "elaborated_type_specifier_7", 7, $1, $2, $3, $4, $5, $6, $7 ); }
	;

enum_specifier:
	ENUM identifier '{' enumerator_list_opt '}' { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( enum_specifier, "enum_specifier", 5, $1, $2, $3, $4, $5 ); }
	;

enumerator_list:
	enumerator_definition { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( enumerator_list+1, "enumerator_list_1", 1, $1 ); }
	| enumerator_list ',' enumerator_definition { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( enumerator_list+2, "enumerator_list_2", 3, $1, $2, $3 ); }
	;

enumerator_definition:
	enumerator { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( enumerator_definition+1, "enumerator_definition_1", 1, $1 ); }
	| enumerator '=' constant_expression { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( enumerator_definition+2, "enumerator_definition_2", 3, $1, $2, $3 ); }
	;

enumerator:
	identifier { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( enumerator, "enumerator", 1, $1 ); }
	;

namespace_definition:
	named_namespace_definition { /* !Not 120++! */ handle_parse_warning( "Namespaces (except for std) are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( namespace_definition+1, "namespace_definition_1", 1, $1 ); }
	| unnamed_namespace_definition { /* !Not 120++! */ handle_parse_warning( "Namespaces (except for std) are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( namespace_definition+2, "namespace_definition_2", 1, $1 ); }
	;

named_namespace_definition:
	original_namespace_definition { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( named_namespace_definition+1, "named_namespace_definition_1", 1, $1 ); }
	| extension_namespace_definition { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( named_namespace_definition+2, "named_namespace_definition_2", 1, $1 ); }
	;

original_namespace_definition:
	NAMESPACE identifier '{' namespace_body '}' { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( original_namespace_definition, "original_namespace_definition", 5, $1, $2, $3, $4, $5 ); }
	;

extension_namespace_definition:
	NAMESPACE original_namespace_name '{' namespace_body '}' { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( extension_namespace_definition, "extension_namespace_definition", 5, $1, $2, $3, $4, $5 ); }
	;

unnamed_namespace_definition:
	NAMESPACE '{' namespace_body '}' { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( unnamed_namespace_definition, "unnamed_namespace_definition", 4, $1, $2, $3, $4 ); }
	;

namespace_body:
	declaration_seq_opt { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( namespace_body, "namespace_body", 1, $1 ); }
	;

namespace_alias_definition:
	NAMESPACE identifier '=' qualified_namespace_specifier ';' { /* !Not 120++! */ handle_parse_warning( "Namespaces (except for std) are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( namespace_alias_definition, "namespace_alias_definition", 5, $1, $2, $3, $4, $5 ); }
	;

qualified_namespace_specifier:
	COLONCOLON nested_name_specifier namespace_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( qualified_namespace_specifier+1, "qualified_namespace_specifier_1", 3, $1, $2, $3 ); }
	| COLONCOLON namespace_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( qualified_namespace_specifier+2, "qualified_namespace_specifier_2", 2, $1, $2 ); }
	| nested_name_specifier namespace_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( qualified_namespace_specifier+3, "qualified_namespace_specifier_3", 2, $1, $2 ); }
	| namespace_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( qualified_namespace_specifier+4, "qualified_namespace_specifier_4", 1, $1 ); }
	;

using_declaration:
	USING TYPENAME COLONCOLON nested_name_specifier unqualified_id ';' { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( using_declaration+1, "using_declaration_1", 6, $1, $2, $3, $4, $5, $6 ); }
	| USING TYPENAME nested_name_specifier unqualified_id ';' { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( using_declaration+2, "using_declaration_2", 5, $1, $2, $3, $4, $5 ); }
	| USING COLONCOLON nested_name_specifier unqualified_id ';' { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( using_declaration+3, "using_declaration_3", 5, $1, $2, $3, $4, $5 ); }
	| USING nested_name_specifier unqualified_id ';' { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( using_declaration+4, "using_declaration_4", 4, $1, $2, $3, $4 ); }
	| USING COLONCOLON unqualified_id ';' { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( using_declaration+5, "using_declaration_5", 4, $1, $2, $3, $4 ); }
	;

using_directive:
	USING NAMESPACE COLONCOLON nested_name_specifier namespace_name ';' { /* !Not 120++! */ handle_parse_warning( "This usage of using is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( using_directive+1, "using_directive_1", 6, $1, $2, $3, $4, $5, $6 ); }
	| USING NAMESPACE COLONCOLON namespace_name ';' { /* !Not 120++! */ handle_parse_warning( "This usage of using is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( using_directive+2, "using_directive_2", 5, $1, $2, $3, $4, $5 ); }
	| USING NAMESPACE nested_name_specifier namespace_name ';' { /* !Not 120++! */ handle_parse_warning( "This usage of using is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( using_directive+3, "using_directive_3", 5, $1, $2, $3, $4, $5 ); }
	| USING NAMESPACE namespace_name ';' { handle_parse_warning( "120++ specs only support usage of the namespace std.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( using_directive+4, "using_directive_4", 4, $1, $2, $3, $4 ); }
	;

asm_definition:
	ASM '(' string_literal ')' ';' { /* !Not 120++! */ handle_parse_warning( "asm is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( asm_definition, "asm_definition", 5, $1, $2, $3, $4, $5 ); }
	;

linkage_specification:
	EXTERN string_literal '{' declaration_seq_opt '}' { /* !Not 120++! */ handle_parse_warning( "extern is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( linkage_specification+1, "linkage_specification_1", 5, $1, $2, $3, $4, $5 ); }
	| EXTERN string_literal declaration { /* !Not 120++! */ handle_parse_warning( "extern is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( linkage_specification+2, "linkage_specification_2", 3, $1, $2, $3 ); }
	;

/*----------------------------------------------------------------------
 * Declarators.
 *----------------------------------------------------------------------*/

init_declarator_list:
	init_declarator { $$ = pt_generate_node( init_declarator_list+1, "init_declarator_list_1", 1, $1 ); }
	| init_declarator_list ',' init_declarator { $$ = pt_generate_node( init_declarator_list+2, "init_declarator_list_2", 3, $1, $2, $3 ); }
	;

init_declarator:
	declarator initializer_opt { $$ = pt_generate_node( init_declarator, "init_declarator", 2, $1, $2 ); }
	;

declarator:
	direct_declarator { $$ = pt_generate_node( declarator+1, "declarator_1", 1, $1 ); }
	| ptr_operator declarator { $$ = pt_generate_node( declarator+2, "declarator_2", 2, $1, $2 ); }
	;

direct_declarator:
	declarator_id { $$ = pt_generate_node( direct_declarator+1, "direct_declarator_1", 1, $1 ); }
	| direct_declarator '(' parameter_declaration_clause_opt ')' cv_qualifier_seq exception_specification { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( direct_declarator+2, "direct_declarator_2", 6, $1, $2, $3, $4, $5, $6 ); }
	| direct_declarator '(' parameter_declaration_clause_opt ')' cv_qualifier_seq { $$ = pt_generate_node( direct_declarator+3, "direct_declarator_3", 5, $1, $2, $3, $4, $5 ); }
	| direct_declarator '(' parameter_declaration_clause_opt ')' exception_specification { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( direct_declarator+4, "direct_declarator_4", 5, $1, $2, $3, $4, $5 ); }
	| direct_declarator '(' parameter_declaration_clause_opt ')' { $$ = pt_generate_node( direct_declarator+5, "direct_declarator_5", 4, $1, $2, $3, $4 ); }
	| class_name '(' parameter_declaration_clause_opt ')' { $$ = pt_generate_node( direct_declarator+6, "direct_declarator_6", 4, $1, $2, $3, $4 ); }
	| class_name COLONCOLON declarator_id '(' parameter_declaration_clause_opt ')' { $$ = pt_generate_node( direct_declarator+7, "direct_declarator_7", 6, $1, $2, $3, $4, $5, $6 ); }
	| class_name COLONCOLON class_name '(' parameter_declaration_clause_opt ')' { $$ = pt_generate_node( direct_declarator+8, "direct_declarator_8", 6, $1, $2, $3, $4, $5, $6 ); }
	| direct_declarator '[' constant_expression_opt ']' { $$ = pt_generate_node( direct_declarator+9, "direct_declarator_9", 4, $1, $2, $3, $4 ); }
	| '(' declarator ')' { $$ = pt_generate_node( direct_declarator+10, "direct_declarator_10", 3, $1, $2, $3 ); }
	;

ptr_operator:
	'*' { $$ = pt_generate_node( ptr_operator+1, "ptr_operator_1", 1, $1 ); }
	| '*' cv_qualifier_seq { $$ = pt_generate_node( ptr_operator+2, "ptr_operator_2", 2, $1, $2 ); }
	| '&' { $$ = pt_generate_node( ptr_operator+3, "ptr_operator_3", 1, $1 ); }
	| nested_name_specifier '*' { $$ = pt_generate_node( ptr_operator+4, "ptr_operator_4", 2, $1, $2 ); }
	| nested_name_specifier '*' cv_qualifier_seq { $$ = pt_generate_node( ptr_operator+5, "ptr_operator_5", 3, $1, $2, $3 ); }
	| COLONCOLON nested_name_specifier '*' { /* !Not 120++! */ handle_parse_warning( "This usage of :: is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( ptr_operator+6, "ptr_operator_6", 3, $1, $2, $3 ); }
	| COLONCOLON nested_name_specifier '*' cv_qualifier_seq { /* !Not 120++! */ handle_parse_warning( "This usage of :: is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( ptr_operator+7, "ptr_operator_7", 4, $1, $2, $3, $4 ); }
	;

cv_qualifier_seq:
	cv_qualifier { $$ = pt_generate_node( cv_qualifier_seq+1, "cv_qualifier_seq_1", 1, $1 ); }
	| cv_qualifier cv_qualifier_seq { $$ = pt_generate_node( cv_qualifier_seq+2, "cv_qualifier_seq_2", 2, $1, $2 ); }
	;

cv_qualifier:
	CONST { yylval->production = cv_qualifier+1; $$ = $1; }
	| VOLATILE { /* !Not 120++! */ handle_parse_warning( "volatile is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = cv_qualifier+2; $$ = $1; }
	;

declarator_id:
	id_expression { $$ = pt_generate_node( declarator_id+1, "declarator_id_1", 1, $1 ); }
	| COLONCOLON id_expression { /* !Not 120++! */ handle_parse_warning( "This usage of :: is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( declarator_id+2, "declarator_id_2", 2, $1, $2 ); }
	| COLONCOLON nested_name_specifier type_name { /* !Not 120++! */ $$ = pt_generate_node( declarator_id+3, "declarator_id_3", 3, $1, $2, $3 ); }
	| COLONCOLON type_name { /* !Not 120++! */ handle_parse_warning( "This usage of :: is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( declarator_id+4, "declarator_id_4", 2, $1, $2 ); }
	;

type_id:
	type_specifier_seq abstract_declarator_opt { $$ = pt_generate_node( type_id, "type_id", 2, $1, $2 ); }
	;

type_specifier_seq:
	type_specifier type_specifier_seq_opt { $$ = pt_generate_node( type_specifier_seq, "type_specifier_seq", 2, $1, $2 ); }
	;

abstract_declarator:
	ptr_operator abstract_declarator_opt { $$ = pt_generate_node( abstract_declarator+1, "abstract_declarator_1", 2, $1, $2 ); }
	| direct_abstract_declarator { $$ = pt_generate_node( abstract_declarator+2, "abstract_declarator_2", 1, $1 ); }
	;

direct_abstract_declarator:
	direct_abstract_declarator_opt '(' parameter_declaration_clause_opt ')' cv_qualifier_seq exception_specification { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( direct_abstract_declarator+1, "direct_abstract_declarator_1", 6, $1, $2, $3, $4, $5, $6 ); }
	| direct_abstract_declarator_opt '(' parameter_declaration_clause_opt ')' cv_qualifier_seq { $$ = pt_generate_node( direct_abstract_declarator+2, "direct_abstract_declarator_2", 5, $1, $2, $3, $4, $5 ); }
	| direct_abstract_declarator_opt '(' parameter_declaration_clause_opt ')' exception_specification { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( direct_abstract_declarator+3, "direct_abstract_declarator_3", 5, $1, $2, $3, $4, $5 ); }
	| direct_abstract_declarator_opt '(' parameter_declaration_clause_opt ')' { $$ = pt_generate_node( direct_abstract_declarator+4, "direct_abstract_declarator_4", 4, $1, $2, $3, $4 ); }
	| direct_abstract_declarator_opt '[' constant_expression_opt ']' { $$ = pt_generate_node( direct_abstract_declarator+5, "direct_abstract_declarator_5", 4, $1, $2, $3, $4 ); }
	| '(' abstract_declarator ')' { $$ = pt_generate_node( direct_abstract_declarator+6, "direct_abstract_declarator_6", 3, $1, $2, $3 ); }
	;

parameter_declaration_clause:
	parameter_declaration_list ELLIPSIS { /* !Not 120++! */ handle_parse_warning( "Variable arguments (ellipsis) is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( parameter_declaration_clause+1, "parameter_declaration_clause_1", 2, $1, $2 ); }
	| parameter_declaration_list ',' ELLIPSIS { /* !Not 120++! */ handle_parse_warning( "Variable arguments (ellipsis) is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( parameter_declaration_clause+2, "parameter_declaration_clause_2", 3, $1, $2, $3 ); }
	| parameter_declaration_list { $$ = pt_generate_node( parameter_declaration_clause+3, "parameter_declaration_clause_3", 1, $1 ); }
	| ELLIPSIS { /* !Not 120++! */ handle_parse_warning( "Variable arguments (ellipsis) is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( parameter_declaration_clause+4, "parameter_declaration_clause_4", 1, $1 ); }
	;

parameter_declaration_list:
	parameter_declaration { $$ = pt_generate_node( parameter_declaration_list+1, "parameter_declaration_list_1", 1, $1 ); }
	| parameter_declaration_list ',' parameter_declaration { $$ = pt_generate_node( parameter_declaration_list+2, "parameter_declaration_list_2", 3, $1, $2, $3 ); }
	;

parameter_declaration:
	decl_specifier_seq declarator { $$ = pt_generate_node( parameter_declaration+1, "parameter_declaration_1", 2, $1, $2 ); }
	| decl_specifier_seq declarator '=' assignment_expression { $$ = pt_generate_node( parameter_declaration+2, "parameter_declaration_2", 4, $1, $2, $3, $4 ); }
	| decl_specifier_seq abstract_declarator_opt { $$ = pt_generate_node( parameter_declaration+3, "parameter_declaration_3", 2, $1, $2 ); }
	| decl_specifier_seq abstract_declarator_opt '=' assignment_expression { $$ = pt_generate_node( parameter_declaration+4, "parameter_declaration_4", 4, $1, $2, $3, $4 ); }
	;

function_definition:
	declarator ctor_initializer_opt function_body { $$ = pt_generate_node( function_definition+1, "function_definition_1", 3, $1, $2, $3 ); }
	| decl_specifier_seq declarator ctor_initializer_opt function_body { $$ = pt_generate_node( function_definition+2, "function_definition_2", 4, $1, $2, $3, $4 ); }
	| declarator function_try_block { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( function_definition+3, "function_definition_3", 2, $1, $2 ); }
	| decl_specifier_seq declarator function_try_block { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( function_definition+4, "function_definition_4", 3, $1, $2, $3 ); }
	;

function_body:
	compound_statement { $$ = pt_generate_node( function_body, "function_body", 1, $1 ); }
	;

initializer:
	'=' initializer_clause { $$ = pt_generate_node( initializer+1, "initializer_1", 2, $1, $2 ); }
	| '(' expression_list ')' { $$ = pt_generate_node( initializer+2, "initializer_2", 3, $1, $2, $3 ); }
	;

initializer_clause:
	assignment_expression { $$ = pt_generate_node( initializer_clause+1, "initializer_clause_1", 1, $1 ); }
	| '{' initializer_list COMMA_opt '}' { $$ = pt_generate_node( initializer_clause+2, "initializer_clause_2", 4, $1, $2, $3, $4 ); }
	| '{' '}' { $$ = pt_generate_node( initializer_clause+3, "initializer_clause_3", 2, $1, $2 ); }
	;

initializer_list:
	initializer_clause { $$ = pt_generate_node( initializer_list+1, "initializer_list_1", 1, $1 ); }
	| initializer_list ',' initializer_clause { $$ = pt_generate_node( initializer_list+2, "initializer_list_2", 3, $1, $2, $3 ); }
	;

/*----------------------------------------------------------------------
 * Classes.
 *----------------------------------------------------------------------*/

class_specifier:
	class_head '{' member_specification_opt '}' { $$ = pt_generate_node( class_specifier, "class_specifier", 4, $1, $2, $3, $4 ); }
	;

class_head:
	class_key identifier { $$ = pt_generate_node( class_head+1, "class_head_1", 2, $1, $2 ); }
	| class_key identifier base_clause { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( class_head+2, "class_head_2", 3, $1, $2, $3 ); }
	| class_key nested_name_specifier identifier { $$ = pt_generate_node( class_head+3, "class_head_3", 3, $1, $2, $3 ); }
	| class_key nested_name_specifier identifier base_clause { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( class_head+4, "class_head_4", 4, $1, $2, $3, $4 ); }
	;

class_key:
	CLASS { yylval->production = class_key+1; $$ = $1; }
	| STRUCT { yylval->production = class_key+2; $$ = $1; }
	| UNION { yylval->production = class_key+3; $$ = $1; }
	;

member_specification:
	member_declaration member_specification_opt { $$ = pt_generate_node( member_specification+1, "member_specification_1", 2, $1, $2 ); }
	| access_specifier ':' member_specification_opt { $$ = pt_generate_node( member_specification+2, "member_specification_2", 3, $1, $2, $3 ); }
	;

member_declaration:
	decl_specifier_seq member_declarator_list ';' { $$ = pt_generate_node( member_declaration+1, "member_declaration_1", 3, $1, $2, $3 ); }
	| decl_specifier_seq ';' { $$ = pt_generate_node( member_declaration+2, "member_declaration_2", 2, $1, $2 ); }
	| member_declarator_list ';' { $$ = pt_generate_node( member_declaration+3, "member_declaration_3", 2, $1, $2 ); }
	| ';' { $$ = pt_generate_node( member_declaration+4, "member_declaration_4", 1, $1 ); }
	| function_definition SEMICOLON_opt { $$ = pt_generate_node( member_declaration+5, "member_declaration_5", 2, $1, $2 ); }
	| qualified_id ';' { $$ = pt_generate_node( member_declaration+6, "member_declaration_6", 2, $1, $2 ); }
	| using_declaration { /* !Not 120++! */ handle_parse_warning( "This usage of using is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( member_declaration+7, "member_declaration_7", 1, $1 ); }
	| template_declaration { /* !Not 120++! */ /* Warned below */ $$ = pt_generate_node( member_declaration+8, "member_declaration_8", 1, $1 ); }
	;

member_declarator_list:
	member_declarator { $$ = pt_generate_node( member_declarator_list+1, "member_declarator_list_1", 1, $1 ); }
	| member_declarator_list ',' member_declarator { $$ = pt_generate_node( member_declarator_list+2, "member_declarator_list_2", 3, $1, $2, $3 ); }
	;

member_declarator:
	declarator { $$ = pt_generate_node( member_declarator+1, "member_declarator_1", 1, $1 ); }
	| declarator pure_specifier { /* !Not 120++! */ handle_parse_warning( "Whatever the fuck a \"pure specifier\" is, it is not supported in 120++ specs.", W_PARSE_UNHANDLED ); $$ = pt_generate_node( member_declarator+2, "member_declarator_2", 2, $1, $2 ); }
	| declarator constant_initializer { $$ = pt_generate_node( member_declarator+3, "member_declarator_3", 2, $1, $2 ); }
	| identifier ':' constant_expression { /* !Not 120++! */ handle_parse_warning( "This member declarator syntax is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( member_declarator+4, "member_declarator_4", 3, $1, $2, $3 ); }
	;

/*
 * This rule need a hack for working around the ``= 0'' pure specifier.
 * 0 is returned as an ``INTEGER'' by the lexical analyzer, 
 * but in this context is different.
 */
pure_specifier:
	'=' '0' { /* !Not 120++! */ $$ = NULL; }
	;

constant_initializer:
	'=' constant_expression { $$ = pt_generate_node( constant_initializer, "constant_initializer", 2, $1, $2 ); }
	;

/*----------------------------------------------------------------------
 * Derived classes.
 *----------------------------------------------------------------------*/

base_clause:
	':' base_specifier_list { /* !Not 120++! */ handle_parse_warning( "This class declaration syntax is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( base_clause, "base_clause", 2, $1, $2 ); }
	;

base_specifier_list:
	base_specifier { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( base_specifier_list+1, "base_specifier_list_1", 1, $1 ); }
	| base_specifier_list ',' base_specifier { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( base_specifier_list+2, "base_specifier_list_2", 3, $1, $2, $3 ); }
	;

base_specifier:
	COLONCOLON nested_name_specifier class_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( base_specifier+1, "base_specifier_1", 3, $1, $2, $3 ); }
	| COLONCOLON class_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( base_specifier+2, "base_specifier_2", 2, $1, $2 ); }
	| nested_name_specifier class_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( base_specifier+3, "base_specifier_3", 2, $1, $2 ); }
	| class_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( base_specifier+4, "base_specifier_4", 1, $1 ); }
	| VIRTUAL access_specifier COLONCOLON nested_name_specifier_opt class_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( base_specifier+5, "base_specifier_5", 5, $1, $2, $3, $4, $5 ); }
	| VIRTUAL access_specifier nested_name_specifier_opt class_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( base_specifier+6, "base_specifier_6", 4, $1, $2, $3, $4 ); }
	| VIRTUAL COLONCOLON nested_name_specifier_opt class_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( base_specifier+7, "base_specifier_7", 4, $1, $2, $3, $4 ); }
	| VIRTUAL nested_name_specifier_opt class_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( base_specifier+8, "base_specifier_8", 3, $1, $2, $3 ); }
	| access_specifier VIRTUAL COLONCOLON nested_name_specifier_opt class_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( base_specifier+9, "base_specifier_9", 5, $1, $2, $3, $4, $5 ); }
	| access_specifier VIRTUAL nested_name_specifier_opt class_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( base_specifier+10, "base_specifier_10", 4, $1, $2, $3, $4 ); }
	| access_specifier COLONCOLON nested_name_specifier_opt class_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( base_specifier+11, "base_specifier_11", 4, $1, $2, $3, $4 ); }
	| access_specifier nested_name_specifier_opt class_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( base_specifier+12, "base_specifier_12", 3, $1, $2, $3 ); }
	;

access_specifier:
	PRIVATE { yylval->production = access_specifier+1; $$ = $1; }
	| PROTECTED { /* !Not 120++! */ handle_parse_warning( "protected member access is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); yylval->production = access_specifier+2; $$ = $1; }
	| PUBLIC { yylval->production = access_specifier+3; $$ = $1; }
	;

/*----------------------------------------------------------------------
 * Special member functions.
 *----------------------------------------------------------------------*/

conversion_function_id:
	OPERATOR conversion_type_id { /* !Not 120++! */ handle_parse_warning( "Operator conversion functions are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( conversion_function_id, "conversion_function_id", 2, $1, $2 ); }
	;

conversion_type_id:
	type_specifier_seq conversion_declarator_opt { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( conversion_type_id, "conversion_type_id", 2, $1, $2 ); }
	;

conversion_declarator:
	ptr_operator conversion_declarator_opt { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( conversion_declarator, "conversion_declarator", 2, $1, $2 ); }
	;

ctor_initializer:
	':' mem_initializer_list { /* !Not 120++! */ handle_parse_warning( "Constructor initializations are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( ctor_initializer, "ctor_initializer", 2, $1, $2 ); }
	;

mem_initializer_list:
	mem_initializer { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( mem_initializer_list+1, "mem_initializer_list_1", 1, $1 ); }
	| mem_initializer ',' mem_initializer_list { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( mem_initializer_list+2, "mem_initializer_list_2", 3, $1, $2, $3 ); }
	;

mem_initializer:
	mem_initializer_id '(' expression_list_opt ')' { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( mem_initializer, "mem_initializer", 4, $1, $2, $3, $4 ); }
	;

mem_initializer_id:
	COLONCOLON nested_name_specifier class_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( mem_initializer_id+1, "mem_initializer_id_1", 3, $1, $2, $3 ); }
	| COLONCOLON class_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( mem_initializer_id+2, "mem_initializer_id_2", 2, $1, $2 ); }
	| nested_name_specifier class_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( mem_initializer_id+3, "mem_initializer_id_3", 2, $1, $2 ); }
	| class_name { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( mem_initializer_id+4, "mem_initializer_id_4", 1, $1 ); }
	| identifier { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( mem_initializer_id+5, "mem_initializer_id_5", 1, $1 ); }
	;

/*----------------------------------------------------------------------
 * Overloading.
 *----------------------------------------------------------------------*/

operator_function_id:
	OPERATOR operator { /* !Not 120++! */ handle_parse_warning( "Operator overloading is not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( operator_function_id, "operator_function_id", 2, $1, $2 ); }
	;

operator:
	NEW { /* !Not 120++! */ /* Warned above */ yylval->production = operator+1; $$ = $1; }
	| DELETE { /* !Not 120++! */ /* Warned above */ yylval->production = operator+2; $$ = $1; }
	| NEW '[' ']' { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( operator+3, "operator_3", 3, $1, $2, $3 ); }
	| DELETE '[' ']' { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( operator+4, "operator_4", 3, $1, $2, $3 ); }
	| '+' { /* !Not 120++! */ yylval->production = operator+5; $$ = $1; }
	| '_' { /* !Not 120++! */ yylval->production = operator+6; $$ = $1; }
	| '*' { /* !Not 120++! */ yylval->production = operator+7; $$ = $1; }
	| '/' { /* !Not 120++! */ yylval->production = operator+8; $$ = $1; }
	| '%' { /* !Not 120++! */ yylval->production = operator+9; $$ = $1; }
	| '^' { /* !Not 120++! */ yylval->production = operator+10; $$ = $1; }
	| '&' { /* !Not 120++! */ yylval->production = operator+11; $$ = $1; }
	| '|' { /* !Not 120++! */ yylval->production = operator+12; $$ = $1; }
	| '~' { /* !Not 120++! */ yylval->production = operator+13; $$ = $1; }
	| '!' { /* !Not 120++! */ yylval->production = operator+14; $$ = $1; }
	| '=' { /* !Not 120++! */ yylval->production = operator+15; $$ = $1; }
	| '<' { /* !Not 120++! */ yylval->production = operator+16; $$ = $1; }
	| '>' { /* !Not 120++! */ yylval->production = operator+17; $$ = $1; }
	| ADDEQ { /* !Not 120++! */ yylval->production = operator+18; $$ = $1; }
	| SUBEQ { /* !Not 120++! */ yylval->production = operator+19; $$ = $1; }
	| MULEQ { /* !Not 120++! */ yylval->production = operator+20; $$ = $1; }
	| DIVEQ { /* !Not 120++! */ yylval->production = operator+21; $$ = $1; }
	| MODEQ { /* !Not 120++! */ yylval->production = operator+22; $$ = $1; }
	| XOREQ { /* !Not 120++! */ yylval->production = operator+23; $$ = $1; }
	| ANDEQ { /* !Not 120++! */ yylval->production = operator+24; $$ = $1; }
	| OREQ { /* !Not 120++! */ yylval->production = operator+25; $$ = $1; }
	| SL { /* !Not 120++! */ yylval->production = operator+26; $$ = $1; }
	| SR { /* !Not 120++! */ yylval->production = operator+27; $$ = $1; }
	| SREQ { /* !Not 120++! */ yylval->production = operator+28; $$ = $1; }
	| SLEQ { /* !Not 120++! */ yylval->production = operator+29; $$ = $1; }
	| EQ { /* !Not 120++! */ yylval->production = operator+30; $$ = $1; }
	| NOTEQ { /* !Not 120++! */ yylval->production = operator+31; $$ = $1; }
	| LTEQ { /* !Not 120++! */ yylval->production = operator+32; $$ = $1; }
	| GTEQ { /* !Not 120++! */ yylval->production = operator+33; $$ = $1; }
	| ANDAND { /* !Not 120++! */ yylval->production = operator+34; $$ = $1; }
	| OROR { /* !Not 120++! */ yylval->production = operator+35; $$ = $1; }
	| PLUSPLUS { /* !Not 120++! */ yylval->production = operator+36; $$ = $1; }
	| MINUSMINUS { /* !Not 120++! */ yylval->production = operator+37; $$ = $1; }
	| ',' { /* !Not 120++! */ yylval->production = operator+38; $$ = $1; }
	| ARROWSTAR { /* !Not 120++! */ yylval->production = operator+39; $$ = $1; }
	| ARROW { /* !Not 120++! */ yylval->production = operator+40; $$ = $1; }
	| '(' ')' { /* !Not 120++! */ $$ = pt_generate_node( operator+41, "operator_41", 2, $1, $2 ); }
	| '[' ']' { /* !Not 120++! */ $$ = pt_generate_node( operator+42, "operator_42", 2, $1, $2 ); }
	;

/*----------------------------------------------------------------------
 * Templates.
 *----------------------------------------------------------------------*/

template_declaration:
	EXPORT_opt TEMPLATE '<' template_parameter_list '>' declaration { /* !Not 120++! */ handle_parse_warning( "Template features are not supported in 120++ specs.", W_PARSE_UNHANDLED ); $$ = NULL; }
	;

template_parameter_list:
	template_parameter { /* !Not 120++! */ /* Warned above */ $$ = NULL; }
	| template_parameter_list ',' template_parameter { /* !Not 120++! */ /* Warned above */ $$ = NULL; }
	;

template_parameter:
	type_parameter { /* !Not 120++! */ /* Warned above */ $$ = NULL; }
	| parameter_declaration { /* !Not 120++! */ /* Warned above */ $$ = NULL; }
	;

type_parameter:
	  CLASS identifier { /* !Not 120++! */ /* Warned above */ $$ = NULL; }
	| CLASS identifier '=' type_id { /* !Not 120++! */ /* Warned above */ $$ = NULL; }
	| TYPENAME identifier { /* !Not 120++! */ /* Warned above */ $$ = NULL; }
	| TYPENAME identifier '=' type_id { /* !Not 120++! */ /* Warned above */ $$ = NULL; }
	| TEMPLATE '<' template_parameter_list '>' CLASS identifier { /* !Not 120++! */ /* Warned above */ $$ = NULL; }
	| TEMPLATE '<' template_parameter_list '>' CLASS identifier '=' template_name { /* !Not 120++! */ /* Warned above */ $$ = NULL; }
	;

template_id:
	template_name '<' template_argument_list '>' { /* !Not 120++! */ handle_parse_warning( "Template features are not supported in 120++ specs.", W_PARSE_UNHANDLED ); $$ = NULL; }
	;

template_argument_list:
	template_argument { /* !Not 120++! */ /* Warned above */ $$ = NULL; }
	| template_argument_list ',' template_argument { /* !Not 120++! */ /* Warned above */ $$ = NULL; }
	;

template_argument:
	assignment_expression { /* !Not 120++! */ /* Warned above */ $$ = NULL; }
	| type_id { /* !Not 120++! */ /* Warned above */ $$ = NULL; }
	| template_name { /* !Not 120++! */ /* Warned above */ $$ = NULL; }
	;

explicit_instantiation:
	TEMPLATE declaration { /* !Not 120++! */ handle_parse_warning( "Template features are not supported in 120++ specs.", W_PARSE_UNHANDLED ); $$ = NULL; }
	;

explicit_specialization:
	TEMPLATE '<' '>' declaration { /* !Not 120++! */ handle_parse_warning( "Template features are not supported in 120++ specs.", W_PARSE_UNHANDLED ); $$ = NULL; }
	;

/*----------------------------------------------------------------------
 * Exception handling.
 *----------------------------------------------------------------------*/

try_block:
	TRY compound_statement handler_seq { /* !Not 120++! */ handle_parse_warning( "Exception handling features are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( try_block, "try_block", 3, $1, $2, $3 ); }
	;

function_try_block:
	TRY ctor_initializer_opt function_body handler_seq { /* !Not 120++! */ handle_parse_warning( "Exception handling features are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( function_try_block, "function_try_block", 4, $1, $2, $3, $4 ); }
	;

handler_seq:
	handler handler_seq_opt { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( handler_seq, "handler_seq", 2, $1, $2 ); }
	;

handler:
	CATCH '(' exception_declaration ')' compound_statement { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( handler, "handler", 5, $1, $2, $3, $4, $5 ); }
	;

exception_declaration:
	type_specifier_seq declarator { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( exception_declaration+1, "exception_declaration_1", 2, $1, $2 ); }
	| type_specifier_seq abstract_declarator { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( exception_declaration+2, "exception_declaration_2", 2, $1, $2 ); }
	| type_specifier_seq { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( exception_declaration+3, "exception_declaration_3", 1, $1 ); }
	| ELLIPSIS { /* !Not 120++! */ /* Warned above */ yylval->production = exception_declaration+4; $$ = $1; }
	;

throw_expression:
	THROW assignment_expression_opt { /* !Not 120++! */ handle_parse_warning( "Exception handling features are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( throw_expression, "throw_expression", 2, $1, $2 ); }
	;

exception_specification:
	THROW '(' type_id_list_opt ')' { /* !Not 120++! */ handle_parse_warning( "Exception handling features are not supported in 120++ specs.", W_PARSE_UNSUPPORTED ); $$ = pt_generate_node( exception_specification, "exception_specification", 4, $1, $2, $3, $4 ); }
	;

type_id_list:
	type_id { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( type_id_list+1, "type_id_list_1", 1, $1 ); }
	| type_id_list ',' type_id { /* !Not 120++! */ /* Warned above */ $$ = pt_generate_node( type_id_list+2, "type_id_list_2", 3, $1, $2, $3 ); }

%%


static void yyerror( char *msg )
{
	if ( program_result_120 == EXIT_NORMAL || program_result_120 == EXIT_ERROR_PARSE  ) 
	{
		fprintf( stderr, "In %s, line %d: %s\n", yyfiles->filename, yyfiles->line_num, msg );
		program_result_120 = EXIT_ERROR_PARSE;
	}
}


void handle_parse_warning( char *msg, short warning_type )
{
	switch ( warning_type )
	{
		fprintf( stderr, "Bison > Warning: " );
		case 1:
			fprintf( stderr, "%s\n\tIn file %s at line %d.\n", msg, yyfiles->filename, yyfiles->line_num );
			break;
		case 2:
			fprintf( stderr, "%s%s\n\tIn file %s at line %d.\n", msg, " The unhandled syntax has been dropped and ignored by this compiler.", yyfiles->filename, yyfiles->line_num );
			break;
		default:
			fprintf( stderr, "%s\n\tIn file %s at line %d.\n", msg, yyfiles->filename, yyfiles->line_num );
			break;
	}
}