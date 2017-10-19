/* 
 * Lab #13
 *
 * CS 121 Sec 03 - Bruce Bolden
 * Gabe Gibler
 * 2015 Apr 30
 *
 * Filtering with Function Pointers - Linked Lists
 *---------------------
 */

#include"utility.h"
std::string hr = "* * * * * * * * * *";
#include"linkedlist.h"

void PopulateList( linkedlist*,int );
void PrintList( linkedlist* );
void Filter( linkedlist*, int, void (*)(linkedlist*,int) );
void FilterAbove( linkedlist*,int );
void FilterBelow( linkedlist*,int );

int main( int argc, char *argv[] )
{
	// Size of test array - whether default or from command line
	int i=0;
	int sizeA = 10;
  if( argc > 1 ) {
		sizeA = atoi(argv[1]);
  }
  linkedlist* DataList = new linkedlist;
  // Thresholds for filtering above and below
	int limitA, limitB;
	limitA = limitB = sizeA/2;
  if( argc > 2 ) {
		limitA = atoi(argv[2]);
  }
  if( argc > 3 ) {
		limitB = atoi(argv[3]);
  }
	srand(time(NULL));
	
	div(hr);
	std::cout << "Filtering Data Using Function Pointers" << std::endl;
	div(hr);
	
	// Filtering run: Filter Above, original list
	PopulateList( DataList, sizeA );
	std::cout << "List contains: ";
	PrintList( DataList );
	std::cout << "Filtering out values greater than " << limitA << " ... \n";
	Filter( DataList, limitA, &FilterAbove );
	std::cout << "Original list, post-filtering: ";
	PrintList( DataList );
	std::cout << "\n" << std::endl;

	// Refreshing the objects
	delete DataList;
  DataList = new linkedlist;

	// Filtering run: Filter Below, original list
	PopulateList( DataList, sizeA );
	std::cout << "List contains: ";
	PrintList( DataList );
	std::cout << "Filtering out values less than " << limitB << " ... \n";
	Filter( DataList, limitB, &FilterBelow );
	std::cout << "Original list, post-filtering: ";
	PrintList( DataList );
	std::cout << "\n" << std::endl;
	
	// Clearing memory
	delete DataList;
	 
	// Exit program
	div(hr);	
	return 0;
}

void PopulateList( linkedlist* L, int s ) {
	const int MAX_VALUE = 9;
	
	for (int i=0; i < s; i++) {
		L->add( rand() % (MAX_VALUE+1) );
	}
}
void PrintList( linkedlist* L ) {
	std::cout << L->print() << std::endl;
}

void Filter( linkedlist* L, int threshold, void (*FF)(linkedlist*,int) ) {
	FF( L, threshold );
}

void FilterAbove( linkedlist* L, int max ) {
	linkedlist Y;
	while (L->size() > 0) {
		if (L->last() <= max) {
			Y.add(L->last());
		}
		L->remove(L->last());
	}
	while (Y.size() > 0) {
		L->add(Y.last());
		Y.remove(Y.last());
	}
}

void FilterBelow( linkedlist* L, int min ) {
	linkedlist Y;
	while (L->size() > 0) {
		if (L->last() >= min) {
			Y.add(L->last());
		}
		L->remove(L->last());
	}
	while (Y.size() > 0) {
		L->add(Y.last());
		Y.remove(Y.last());
	}
}
