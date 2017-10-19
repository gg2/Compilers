/* 
 * Lab #13
 *
 * CS 121 Sec 03 - Bruce Bolden
 * Gabe Gibler
 * 2015 Apr 30
 *
 * Filtering with Function Pointers - Arrays
 *---------------------
 */

#include"utility.h"
std::string hr = "* * * * * * * * * *";

void PopulateList( int[],int );
void PrintList( int[],int );
void Filter( int[], int&, int, void (*)(int[],int&,int) );
void FilterAbove( int[],int&,int );
void FilterBelow( int[],int&,int );

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
	
	PopulateList( DataList, sizeF );
	std::cout << "Array contains: ";
	PrintList( DataList, sizeF );
	std::cout << "\nFiltering out values greater than " << limitA << " ... \n";
	Filter( DataList, sizeF, limitA, &FilterAbove );
	std::cout << "Original array, post-filtering: ";
	PrintList( DataList, sizeF );
	std::cout << "\n" << std::endl;

	// Resetting list sizes
	sizeF = sizeA;
	PopulateList( DataList, sizeF );
	std::cout << "Array contains: ";
	PrintList( DataList, sizeF );
	std::cout << "\nFiltering out values less than " << limitB << " ... \n";
	Filter( DataList, sizeF, limitB, &FilterBelow );
	std::cout << "Original array, post-filtering: ";
	PrintList( DataList, sizeF );
	std::cout << "\n" << std::endl;
	
	// Exit program
	div(hr);
	return 0;
}

void PopulateList( int A[], int s ) {
	const int MAX_VALUE = 9;
	
	for (int i=0; i < s; i++) {
		A[i] = ( rand() % (MAX_VALUE+1) );
	}
}
void PrintList( int A[], int s ) {
	for (int i=0; i < s; i++) {
		std::cout << A[i] << " ";
	}
}

void Filter( int A[], int &s, int threshold, void (*FF)(int[],int&,int) ) {
	FF( A, s, threshold );
}

void FilterAbove( int A[], int &s, int max ) {
	int i, c = 0;

	for (i=0; i < s; i++) {
		if (A[i] <= max) {
			A[c] = A[i];
			c++;
		}
	}
	for (i = s-1; i > c-1; i--) {
		A[i] = '\0';
	}
	s = c;
}

void FilterBelow( int A[], int &s, int min ) {
	int i, c = 0;

	for (i=0; i < s; i++) {
		if (A[i] >= min) {
			A[c] = A[i];
			c++;
		}
	}
	for (i = s-1; i > c-1; i--) {
		A[i] = '\0';
	}
	s = c;
}

