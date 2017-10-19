
#ifndef GG_120_TYPES
#define GG_120_TYPES

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Base type enumerators.
static const short t_VOID    =  0;
static const short t_BOOL    =  1;
static const short t_CHAR    =  2;
static const short t_INT     =  3;
static const short t_SHORT   =  3;
static const short t_LONG    =  3;
static const short t_DOUBLE  =  4;
static const short t_FLOAT   =  4;
static const short t_NAMESPC =  5;
static const short t_ARRAY   =  6;
static const short t_STRUCT  =  7;
static const short t_FUNC    =  8;
static const short t_CLASS   =  9;
static const short t_POINTER = 10;
static const short t_MISC    = 11;

// Size to make type tables.
static const size_t tt_size  = 12;


typedef struct c_type
{
	short base_type;
	
	union 
	{
		struct c_type *ptr;
		struct array 
		{
			int size;
			struct c_type *of;
		} array;
		struct func 
		{
			char *func_name;
			struct c_type *return_type;
			int ct_params;
			struct param **params;
		} func;
		struct clss 
		{
			char *clss_name;
		} clss;
		struct strct 
		{
			char *label;
			int ct_fields;
			struct field **fields;
		} strct;
		struct misc
		{
			char *name_of_type;
		} misc;
	} u;
	
	struct c_type *next;
} ctype;

struct field 
{
	char *name;
	ctype *type;
};

struct param 
{
	char *name;
	ctype *type;
};


ctype** tt_init(ctype **tt_table);
size_t tt_count_at(ctype **tt_table,int index);
ctype* tt_insert(ctype **tt_table,const short base_index);
ctype* tt_get_type_basic(ctype **tt_table,const short base_index);
int tt_compare_types(ctype *t1,ctype *t2);
void tt_print(ctype **tt_table);
void tt_print_depth(ctype *n);
const char* tt_print_base_name(short t_type);
void tt_print_function_signature(ctype *f);
void tt_destruct(ctype **tt_table);


#endif /* GG_120_TYPES */