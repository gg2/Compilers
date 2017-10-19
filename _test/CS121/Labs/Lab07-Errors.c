/* memerror.c -- try to find (and fix!) all the memory-related errors
                 in this program that

   Takes a string from the command line.  
   Makes a linked-list out of it in reverse order.  
   Traverses it to construct a string in reverse.  
   Clean up (release memory).
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct st_CharNode 
{
    char theChar;
    struct st_CharNode *next;
} CharNode;


void reverseIt( char *stringbuffer );


int main( int argc, char *argv[] )
{
    char *stringBuffer;

    //  Check number of user supplied arguments.  
    if( argc != 2 )
    {
        fprintf( stderr, "usage: %s string.  This reverses the string "
                 "given on the command line\n" );
        exit( -1 );
    }
		
    // Copy the argument so we can make changes to it
    stringBuffer = malloc( strlen(argv[1]) + 1 );
    strcpy( stringBuffer, argv[1] );
		printf("The provided string is '%s'\n", stringBuffer );

    // Reverse the string
    reverseIt( stringBuffer );
	
    // Print the reversed string
    printf( "The reversed string is '%s'\n", stringBuffer );
		
		free( stringBuffer );
		
    return 0;
}


// Build a linked list backwards, then traverse it.

void reverseIt( char *stringbuffer )
{
    CharNode *head, *node;
    char *scan, *stop;
    
    // initialize local vars
    head = node = NULL;

    // find the start and end of the string so we can walk it
    scan = stringbuffer;
    stop = stringbuffer + strlen(stringbuffer);
		
    // walk the string
    while (scan < stop)
    {
        if (head == NULL)
        {
            head = malloc( sizeof(CharNode*) );
            head->theChar = *scan;
            head->next = NULL;
        }
        else
        {
            node = malloc( sizeof(CharNode*) );
            node->theChar = *scan;
            node->next = head;
            head = node;
        }
        scan++;
    }

    // Re-point to the buffer so we can drop the characters
    scan = stringbuffer;

    //  Traverse the nodes and add them to the string
    while( head != NULL )
    {
        *scan = head->theChar;
        free( head );
        node = head->next;
        head = node;
        scan++;
    }

    // Release head
    free( head );
    free( node );
}
