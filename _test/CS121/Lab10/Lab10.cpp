/* 
 * Lab #10
 *
 * CS 121 Sec 03 - Bolden
 * Gabe Gibler
 * 2015 Apr 9
 *
 * Filtering Functions
 *---------------------
 */

#include"utility.h"
std::string hr = "* * * * * * * * * *";
#include"linkedlist.h"

void PopulateList( int[],int );
void PrintList( int[],int );
void FilterAbove( int[],int&,int );
void FilterBelow( int[],int&,int );
void FilterAbove2( int[],int[],int&,int );
void FilterBelow2( int[],int[],int&,int );

int main( int argc, char *argv[] )
{
	// Size of test array - whether default or from command line
	int i=0;
	int sizeA = 10;
  if( argc > 1 ) {
		sizeA = atoi(argv[1]);
  }
  int sizeF = sizeA;
  int DataList[sizeA];
  int FilteredList[sizeA];
  // Thresholds for filtering above and below
	int limitA, limitB;
	limitA = limitB = sizeA/2;
  if( argc > 2 ) {
		limitA = atoi(argv[2]);
  }
  if( argc > 3 ) {
		limitB = atoi(argv[3]);
  }

	
	div(hr);
	std::cout << "Filtering Data" << std::endl;
	div(hr);
	
	PopulateList( DataList, sizeF );
	std::cout << "List contains: ";
	PrintList( DataList, sizeF );
	std::cout << "\nFiltering list ... \n";
	FilterAbove( DataList, sizeF, limitA );
	std::cout << "List, post-filtering: ";
	PrintList( DataList, sizeF );
	std::cout << std::endl;

	// Resetting list sizes
	sizeF = sizeA;
	PopulateList( DataList, sizeF );
	std::cout << "List contains: ";
	PrintList( DataList, sizeF );
	std::cout << "\nFiltering list ... \n";
	FilterBelow( DataList, sizeF, limitB );
	std::cout << "List, post-filtering: ";
	PrintList( DataList, sizeF );
	std::cout << std::endl;
	
	// Beginning version that returns array
	// Resetting list sizes
	sizeF = sizeA;	
	PopulateList( DataList, sizeF );
	std::cout << "List contains: ";
	PrintList( DataList, sizeF );
	std::cout << "\nFiltering list ... \n";
	DataList = FilterAbove2( DataList, FilteredList, sizeF, limitA );
	std::cout << "List, post-filtering: ";
	PrintList( FilteredList, sizeF );
	std::cout << std::endl;

	// Resetting list sizes
	sizeF = sizeA;
	PopulateList( DataList, sizeF );
	std::cout << "List contains: ";
	PrintList( DataList, sizeF );
	std::cout << "\nFiltering list ... \n";
	DataList = FilterBelow2( DataList, FilteredList, sizeF, limitB );
	std::cout << "List, post-filtering: ";
	PrintList( FilteredList, sizeF );
	std::cout << std::endl;
	 
	// Exit program
	div(hr);
 	std::cout << "Press enter to exit." << std::endl;
	std::cin.ignore();
	return 0;
}

void PopulateList( int A[], int s ) {
	for (int i=0; i < s; i++) {
		A[i] = (rand() % 10);
	}
}
void PrintList( int A[], int s ) {
	for (int i=0; i < s; i++) {
		std::cout << A[i] << " ";
	}
}

void FilterAbove( int A[], int &s, int max ) {
	int i, c = 0;

	for (i=0; i < s; i++) {
		if (A[i] < max) {
			A[c] = A[i];
			c++;
		}
	}
	for (i = s-1; i > c-1; i--) {
		A[i] = '/0';
	}
	s = c;
}

void FilterBelow( int A[], int &s, int min ) {
	int i, c = 0;

	for (i=0; i < s; i++) {
		if (A[i] > min) {
			A[c] = A[i];
			c++;
		}
	}
	for (i = s-1; i > c-1; i--) {
		A[i] = '/0';
	}
	s = c;
}

void FilterAbove2( int A[], int Y[], int &s, int max ) {
	int i, c = 0;
	
	for (i=0; i < s; i++) {
		if (A[i] < max) {
			Y[c] = A[i];
			c++;
		}
	}
	for (i = s-1; i > c-1; i--) {
		Y[i] = '/0';
	}
	s = c;
}

void FilterBelow2( int A[], int Y[], int &s, int min ) {
	int i, c = 0;
	
	for (i=0; i < s; i++) {
		if (A[i] > min) {
			Y[c] = A[i];
			c++;
		}
	}
	for (i = s-1; i > c-1; i--) {
		Y[i] = '/0';
	}
	s = c;
}

