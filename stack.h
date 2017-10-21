
#ifndef GG_120_STACK
#define GG_120_STACK

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct stack
{
	char *filename;
	FILE *file_ptr;

	int line_num;
	int w_include;
	int w_preprocdirective;
	int w_numberformats;
	int w_digraphs;
	
	struct stack *next;
} stack;

void stack_init(stack **head);
int stack_is_empty(stack *head);
int stack_push(stack **head,char *val,FILE *fptr,int ln);
void stack_pop(stack **head);
void stack_destruct(stack **head);

#endif /* GG_120_STACK */