/* 
 * Lab #10
 *
 * CS 121 Sec 03 - Bolden
 * Gabe Gibler
 * 2015 Apr 9
 *
 * Filtering Functions - Linked Lists
 *---------------------
 */

#include"utility.h"
std::string hr = "* * * * * * * * * *";
#include"linkedlist.h"

void PopulateList( linkedlist*,int );
void PrintList( linkedlist* );
void FilterAbove( linkedlist*,int );
void FilterBelow( linkedlist*,int );
void FilterAbove2( linkedlist,linkedlist*,int );
void FilterBelow2( linkedlist,linkedlist*,int );

int main( int argc, char *argv[] )
{
	// Size of test array - whether default or from command line
	int i=0;
	int sizeA = 10;
  if( argc > 1 ) {
		sizeA = atoi(argv[1]);
  }
  linkedlist* DataList = new linkedlist;
  linkedlist* FilteredList = new linkedlist;
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
	std::cout << "Filtering Data" << std::endl;
	div(hr);
	
	// Filtering run: Filter Above, original list
	PopulateList( DataList, sizeA );
	std::cout << "List contains: ";
	PrintList( DataList );
	std::cout << "Filtering out values greater than " << limitA << " ... \n";
	FilterAbove( DataList, limitA );
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
	FilterBelow( DataList, limitB );
	std::cout << "Original list, post-filtering: ";
	PrintList( DataList );
	std::cout << "\n" << std::endl;
	// Refreshing the objects
	delete DataList;
  DataList = new linkedlist;
	
	// Filtering run: Filter Above, list returned
	PopulateList( DataList, sizeA );
	std::cout << "List contains: ";
	PrintList( DataList );
	std::cout << "Filtering out values greater than " << limitA << " ... \n";
	FilterAbove2( *DataList, FilteredList, limitA );
	std::cout << "List returned, post-filtering: ";
	PrintList( FilteredList );
	std::cout << "\n" << std::endl;
	// Refreshing the objects
	delete DataList;
	delete FilteredList;
  DataList = new linkedlist;
  FilteredList = new linkedlist;

	// Filtering run: Filter Below, list returned
	PopulateList( DataList, sizeA );
	std::cout << "List contains: ";
	PrintList( DataList );
	std::cout << "Filtering out values less than " << limitB << " ... \n";
	FilterBelow2( *DataList, FilteredList, limitB );
	std::cout << "List returned, post-filtering: ";
	PrintList( FilteredList );
	std::cout << "\n" << std::endl;
	// Clearing memory
	delete DataList;
	delete FilteredList;
	 
	// Exit program
	div(hr);	
	return 0;
}

void PopulateList( linkedlist* L, int s ) {
	for (int i=0; i < s; i++) {
		L->add(rand() % 10);
	}
}
void PrintList( linkedlist* L ) {
	std::cout << L->print() << std::endl;
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

void FilterAbove2( linkedlist L, linkedlist* Y, int max ) {
	while (L.size() > 0) {
		if (L.last() <= max) {
			Y->add(L.last());
		}
		L.remove(L.last());
	}
}

void FilterBelow2( linkedlist L, linkedlist* Y, int min ) {
	while (L.size() > 0) {
		if (L.last() >= min) {
			Y->add(L.last());
		}
		L.remove(L.last());
	}
}

