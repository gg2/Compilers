
#ifndef HASH_H
#define HASH_H

struct nList
{
	char *word;
	struct nList *next;
};

typedef struct nList *NListPtr;

unsigned Hash( char* );
NListPtr Lookup( char* );
NListPtr Insert( char* );

void PrintHashTable();

void PrintBucketCount();

#endif  /* HASH_H */