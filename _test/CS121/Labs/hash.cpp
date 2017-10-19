/* 
 *  Hash table implementation from:
 *  Kernighan & Ritchie, The C Programming Language, Second Edition, Prentice-Hall, 1988.
 */

#include<iostream>
#include<iomanip>
#include<cstdlib>
#include<cstring>

using namespace std;

#include"hash.h"

const int HASH_TABLE_SIZE = 50031;
static NListPtr hashTable[HASH_TABLE_SIZE];

//  Prototypes
static char *Strdup( const char* );  //  in cstring, but....

/*  Hash
 *  Generate hash value for string s
 */
unsigned Hash( char *s )
{
	unsigned hashVal;
	
	for( hashVal = 0 ; *s != '\0' ; s++ )
		hashVal = *s + 31 * hashVal;
		
	return  hashVal % HASH_TABLE_SIZE;
}

/*  Lookup
 *  Look for s in hashTable
 */
NListPtr Lookup( char *s )
{
	NListPtr np;
	
	for( np = hashTable[Hash(s)] ; np != NULL ; np = np->next )
	{
		if( strcmp(s, np->word) == 0 )
			return np;    //  found
	}
	
	return NULL;   //  not found
}

/*  Insert
 *  Put (word) in hash table
 */
NListPtr Insert( char *word )
{
	unsigned hashVal;
	NListPtr np;
	
	if( (np = Lookup(word)) == NULL )  // not found
	{
		np = (NListPtr) malloc(sizeof(*np));
		if( np == NULL || (np->word = Strdup(word)) == NULL )
		    return NULL;
		hashVal = Hash(word);
		np->next = hashTable[hashVal];
		hashTable[hashVal] = np;
	
		return np;
	}
	else
	{
		return NULL;
	}
}

/*  PrintHashTable
 *  Print the hash table contents
 */
void PrintHashTable()
{
	NListPtr np;
	
	cout << "Hash table contents:" << endl;
	cout << "--------------------\n" << endl;
	
	for( int i=0; i < HASH_TABLE_SIZE; i++ )
	{
		np = hashTable[i];
		while( np != NULL )
		{
			cout << setw(3) << i << ":    ";
			cout << np->word << endl;
			np = np->next;
		}
	}
}

void PrintBucketCount() 
{
	NListPtr np;
	int ct[HASH_TABLE_SIZE], minSize = 1000000000, maxSize = -1;
	
	// Count bucket contents
	for( int i=0; i < HASH_TABLE_SIZE; i++ )
	{
		ct[i] = 0;
		np = hashTable[i];
		while( np != NULL )
		{
			ct[i]++;
			np = np->next;
		}
	}

	cout << "Bucket Counts:" << endl;
	cout << "--------------------\n" << endl;
	
	for( int i=0; i < HASH_TABLE_SIZE; i++ )
	{
		cout << setw(3) << i << ": " << ct[i] << endl;
		// Determine largest and smallest bucket
		if (ct[i] < minSize)
			minSize = ct[i];
		if (ct[i] > maxSize)
			maxSize = ct[i];
	}
	cout << "Smallest bucket: " << minSize << endl;
	cout << "Largest bucket: " << maxSize << endl;
}

/*  Strdup
 *  Make a duplicate copy of s
 */
static char *Strdup( const char *s )
{
	char *p;
	
	p = (char *) malloc(strlen(s)+1);  /*  +1 for '\0'  */
	if( p != NULL )
		strcpy(p,s);
	
	return p;
}