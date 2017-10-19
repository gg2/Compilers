/* 
 * CS 121 Sec 03 - Bruce Bolden
 * Gabe Gibler
 * 2015 May 07
 *
 * Sorting Analysis
 *
 */

//#define DISPLAY_RESULTS

#include"utility.h"
std::string hr = "* * * * * * * * * *";
const int MAX_ARRAY = 10000;
/* 
 * Array of Analysis data: 
 * # of array sizes [3], 
 * # of array arrangements (random, asc, desc) [3], 
 * # of sorts performed on each arrangement (selection, quick, merge) [3]
 * # of operations tracked per sort { 0) declarations/initializations, 1) assignments/swaps, 2) comparisons, 5) branching } [6]
 */
int AnalysisData[3][3][3][6];
int ADISize;
int ADIArrangement;
int ADISort;

void HandlingRoutine(int[],int,std::string,void(*)(int[],int,int));
void DisplayResults();

void GenerateDataSets(std::string,int[],int);
void GenerateDataRandom(int[],int);
void GenerateDataAscending(int[],int);
void GenerateDataDescending(int[],int);
void ClearData(int[],int);
void PrintArray(int[],int);

void Mergesort(int[],int,int);
void Merge(int[],int,int,int,int);
void SelectionSort(int[],int,int);
int IndexOfSmallest(int[],int,int);
void Quicksort(int[],int,int);
int Pivot(int[],int,int);
void Swap(int&,int&);

int main( int argc, char *argv[] )
{
	srand(time(NULL));
	
	const int SIZE_A = 100;
	int Data[SIZE_A*100];
	std::string DataOrder;
	int DataSize = 0;
	
	ADISize = 0;
	ADIArrangement = 0;
	ADISort = 0;
	// Initialize AnalysisData array
	for( int i=0; i < 3; i++ ) {
		for( int j=0; j < 3; j++ ) {
			for( int k=0; k < 3; k++ ) {
				for( int n=0; n < 6; n++ ) {
					AnalysisData[i][j][k][n] = 0;
				}
			}
		}
	}
	
	div(hr);
	std::cout << "Analysis of Sort Routines" << std::endl;
	div(hr);
	
	std::cout << "Generating data sets and sorting now...\n";
	// Beginning of 100
	DataSize = SIZE_A;
	ADISize = 0;
	DataOrder = "rand";
	ADIArrangement = 0;
	std::cout << "Arrays of size " << DataSize << "..." << std::endl;
	// 100 unsorted, Selection Sort
	ADISort = 0;
	HandlingRoutine(Data, DataSize, DataOrder, &SelectionSort);
	// 100 unsorted, Quicksort
	ADISort++;
	HandlingRoutine(Data, DataSize, DataOrder, &Quicksort);
	// 100 unsorted, Mergesort
	ADISort++;
	HandlingRoutine(Data, DataSize, DataOrder, &Mergesort);
	
	DataOrder = "asc";
	ADIArrangement++;
	// 100 ascending, Selection Sort
	ADISort = 0;
	HandlingRoutine(Data, DataSize, DataOrder, &SelectionSort);
	// 100 ascending, Quicksort
	ADISort++;
	HandlingRoutine(Data, DataSize, DataOrder, &Quicksort);
	// 100 ascending, Mergesort
	ADISort++;
	HandlingRoutine(Data, DataSize, DataOrder, &Mergesort);
	
	DataOrder = "desc";
	ADIArrangement++;
	// 100 descending, Selection Sort
	ADISort = 0;
	HandlingRoutine(Data, DataSize, DataOrder, &SelectionSort);
	// 100 descending, Quicksort
	ADISort++;
	HandlingRoutine(Data, DataSize, DataOrder, &Quicksort);
	// 100 descending, Mergesort
	ADISort++;
	HandlingRoutine(Data, DataSize, DataOrder, &Mergesort);
	
	// Beginning of 1000
	DataSize *= 10;
	ADISize++;
	DataOrder = "rand";
	ADIArrangement = 0;
	std::cout << "Arrays of size " << DataSize << "..." << std::endl;
	// 1000 unsorted, Selection Sort
	ADISort = 0;
	HandlingRoutine(Data, DataSize, DataOrder, &SelectionSort);
	// 1000 unsorted, Quicksort
	ADISort++;
	HandlingRoutine(Data, DataSize, DataOrder, &Quicksort);
	// 1000 unsorted, Mergesort
	ADISort++;
	HandlingRoutine(Data, DataSize, DataOrder, &Mergesort);
	
	DataOrder = "asc";
	ADIArrangement++;
	// 1000 ascending, Selection Sort
	ADISort = 0;
	HandlingRoutine(Data, DataSize, DataOrder, &SelectionSort);
	// 1000 ascending, Quicksort
	ADISort++;
	HandlingRoutine(Data, DataSize, DataOrder, &Quicksort);
	// 1000 ascending, Mergesort
	ADISort++;
	HandlingRoutine(Data, DataSize, DataOrder, &Mergesort);
	
	DataOrder = "desc";
	ADIArrangement++;
	// 1000 descending, Selection Sort
	ADISort = 0;
	HandlingRoutine(Data, DataSize, DataOrder, &SelectionSort);
	// 1000 descending, Quicksort
	ADISort++;
	HandlingRoutine(Data, DataSize, DataOrder, &Quicksort);
	// 1000 descending, Mergesort
	ADISort++;
	HandlingRoutine(Data, DataSize, DataOrder, &Mergesort);

	// Beginning of 10000
	DataSize *=10;
	ADISize++;
	DataOrder = "rand";
	ADIArrangement = 0;
	std::cout << "Arrays of size " << DataSize << "..." << std::endl;
	// 10000 unsorted, Selection Sort
	ADISort = 0;
	HandlingRoutine(Data, DataSize, DataOrder, &SelectionSort);
	// 10000 unsorted, Quicksort
	ADISort++;
	HandlingRoutine(Data, DataSize, DataOrder, &Quicksort);
	// 10000 unsorted, Mergesort
	ADISort++;
	HandlingRoutine(Data, DataSize, DataOrder, &Mergesort);
	
	DataOrder = "asc";
	ADIArrangement++;
	// 10000 ascending, Selection Sort
	ADISort = 0;
	HandlingRoutine(Data, DataSize, DataOrder, &SelectionSort);
	// 10000 ascending, Quicksort
	ADISort++;
	HandlingRoutine(Data, DataSize, DataOrder, &Quicksort);
	// 10000 ascending, Mergesort
	ADISort++;
	HandlingRoutine(Data, DataSize, DataOrder, &Mergesort);
	
	DataOrder = "desc";
	ADIArrangement++;
	// 10000 descending, Selection Sort
	ADISort = 0;
	HandlingRoutine(Data, DataSize, DataOrder, &SelectionSort);
	// 10000 descending, Quicksort
	ADISort++;
	HandlingRoutine(Data, DataSize, DataOrder, &Quicksort);
	// 10000 descending, Mergesort
	ADISort++;
	HandlingRoutine(Data, DataSize, DataOrder, &Mergesort);

	// display results
	DisplayResults();

	// Exit program
	div(hr);
	return 0;
}

//////////////////////////////////////////////////////////////////////////////

// General process for populating, viewing, sorting, and clearing the data set
void HandlingRoutine(int A[], int size, std::string DataOrder, void (*SortF)(int[],int,int)) 
{
	GenerateDataSets(DataOrder, A, size);
	std::cout << "ADI Variables, w/i HandlingRoutine: " << ADISize << ", " << ADIArrangement << ", " << ADISort << std::endl; // DEBUG
	SortF(A, 0, size);
	#ifdef DISPLAY_RESULTS
	PrintArray(A, size);
	div(hr);
	std::cin.ignore();
	#endif
	ClearData(A, size);
}

// Accepts: sort == rand / asc / desc
void GenerateDataSets( std::string sort, int A[], int size ) 
{
	if ( sort == "rand") {
		GenerateDataRandom( A, size );
	} else if ( sort == "asc" ) {
		GenerateDataAscending( A, size );
	} else if ( sort == "desc" ) {
		GenerateDataDescending( A, size );
	} else {
		std::cout << "Invalid request for generating dataset." << std::endl;
	}
}

void GenerateDataRandom( int A[], int size ) 
{
	for ( int i=0; i < size; i++ ) {
		A[i] = ( rand() % size );
	}
}

void GenerateDataAscending( int A[], int size ) 
{
	for ( int i=0; i < size; i++ ) {
		A[i] = i;
	}
}

void GenerateDataDescending( int A[], int size ) 
{
	int j = size;
	for ( int i=0; i < size; i++ ) {
		A[i] = j;
		j--;
	}
}

void ClearData(int A[], int size) {
	for ( int i=0; i < size; i++ ) {
		A[i] = 0;
	}
}

//  PrintArray:  Print contents of an array.
void PrintArray( int A[], int size )
{
	std::cout << "{ ";
	
	for( int i=0; i < size; i++ )
	{
		std::cout << A[i] ;
		if( i < size-1 )
			std::cout << ", ";
	}
	
	std::cout << " }" << std::endl;
}


void DisplayResults() {
	div(hr);
	std::cout << "Analysis Results:\n\n" << std::endl;
	
	for (int i=0; i<3; i++) {
		std::cout << "Arrays of Size ";
		switch (i) {
			case 0:
				std::cout << "100" << std::endl;
				break;
			case 1:
				std::cout << "1000" << std::endl;
				break;
			case 2:
				std::cout << "10000" << std::endl;
				break;
		}
		for (int j=0; j<3; j++) {
			std::cout << "\tSorted ";
			switch (j) {
				case 0:
					std::cout << "randomly" << std::endl;
					break;
				case 1:
					std::cout << "ascending" << std::endl;
					break;
				case 2:
					std::cout << "descending" << std::endl;
					break;
			}
			for (int k=0; k<3; k++) {
				std::cout << "\t\tResults for ";
				switch (k) {
					case 0:
						std::cout << "Selection Sort" << std::endl;
						break;
					case 1:
						std::cout << "Quicksort" << std::endl;
						break;
					case 2:
						std::cout << "Mergesort" << std::endl;
						break;
				}
				// { 0) declarations/initializations, 1) assignments/swaps, 2) comparisons, 6) branching }
				std::cout << "\t\t\t# of variable declarations/initializations: " << AnalysisData[i][j][k][0] << std::endl;
				std::cout << "\t\t\t# of assignments and swaps: " << AnalysisData[i][j][k][1] << std::endl;
				std::cout << "\t\t\t# of comparisons (excl. for loop parameters): " << AnalysisData[i][j][k][2] << std::endl;
				std::cout << "\t\t\t# of branchings/recursive calls: " << AnalysisData[i][j][k][5] << std::endl;
				std::cout << "\n";
			}
		}
	}
	div(hr);
}


//////////////////////////////////////////////

void Mergesort( int a[], int first, int last ) 
{
	int  middle;
											AnalysisData[ADISize][ADIArrangement][ADISort][0]++; /// Analysis
	
	#ifdef DISPLAY_RESULTS
	std::cout << "------------------------" << std::endl;
	std::cout << "\nMergesort:" << std::endl;
	std::cout << "Mergesort::first: " << first << std::endl;
	std::cout << "Mergesort::last:  " << last  << std::endl;
	#endif
	
	if( first < last ) {
											AnalysisData[ADISize][ADIArrangement][ADISort][2]++; /// Analysis
		middle = (first + last)/2;
											AnalysisData[ADISize][ADIArrangement][ADISort][1]++; /// Analysis
		#ifdef DISPLAY_RESULTS
		std::cout << "Mergesort::middle:  " << middle << std::endl;
		#endif
		Mergesort( a, first, middle);
		Mergesort( a, middle+1, last );
		Merge( a, first, middle, middle+1, last );
											AnalysisData[ADISize][ADIArrangement][ADISort][5] += 3; /// Analysis
	}
}

// Merge two segments of an array together.
void Merge( int a[], int firstLeft, int lastLeft, int firstRight, int lastRight ) 
{
	int tmp[MAX_ARRAY];
	int index = firstLeft;
	int firstSave = firstLeft;
												AnalysisData[ADISize][ADIArrangement][ADISort][0] += 3; /// Analysis
	
	#ifdef DISPLAY_RESULTS
	std::cout << "Merge::firstLeft:  " << firstLeft   << std::endl;
	std::cout << "Merge::lastLeft:   " << lastLeft    << std::endl;
	std::cout << "Merge::firstRight: " << firstRight  << std::endl;
	std::cout << "Merge::lastRight:  " << lastRight   << std::endl;
	#endif
	
	//  Merge segments (array subsets)
	while( (firstLeft <= lastLeft) && (firstRight <= lastRight) )
	{
											AnalysisData[ADISize][ADIArrangement][ADISort][2]++; /// Analysis
		if( a[firstLeft] < a[firstRight] )
		{
											AnalysisData[ADISize][ADIArrangement][ADISort][2]++; /// Analysis
			tmp[index] = a[firstLeft];
			firstLeft++;
											AnalysisData[ADISize][ADIArrangement][ADISort][1] += 2; /// Analysis
		}
		else
		{
											AnalysisData[ADISize][ADIArrangement][ADISort][2]++; /// Analysis
			tmp[index] = a[firstRight];
			firstRight++;
											AnalysisData[ADISize][ADIArrangement][ADISort][1] += 2; /// Analysis
		}
		index++;
											AnalysisData[ADISize][ADIArrangement][ADISort][1]++; /// Analysis
	}
	//  Copy remainder of left array into tmp
	while( firstLeft <= lastLeft )
	{
											AnalysisData[ADISize][ADIArrangement][ADISort][2]++; /// Analysis
		tmp[index] = a[firstLeft];
		firstLeft++;
		index++;
											AnalysisData[ADISize][ADIArrangement][ADISort][1] += 3; /// Analysis
	}
	
	//  Copy remainder of right array into tempArray
	while( firstRight <= lastRight )
	{
											AnalysisData[ADISize][ADIArrangement][ADISort][2]++; /// Analysis
		tmp[index] = a[firstRight];
		firstRight++;
		index++;
											AnalysisData[ADISize][ADIArrangement][ADISort][1] += 3; /// Analysis
	}
	
	//  Copy back into original array
	for( index = firstSave ; index <= lastRight ; index++ )
		a[index] = tmp[index];
											AnalysisData[ADISize][ADIArrangement][ADISort][1]++; /// Analysis
}

//////////////////////////////////////////////////

// Sort an array using a selection sort algorithm.
void SelectionSort( int A[], int junk, int size )
{
	int iSmallest;
	int tmp;
											AnalysisData[ADISize][ADIArrangement][ADISort][0] += 2; /// Analysis
	
	#ifdef DISPLAY_RESULTS
	std::cout << "------------------------" << std::endl;
	std::cout << "SelectionSort:" << std::endl;
	#endif
	
	for( int i=0; i < size; i++ )
	{
		#ifdef DISPLAY_RESULTS
		std::cout << " Pass: " << i << std::endl;
		#endif
		
		iSmallest = IndexOfSmallest( A, i, size-1 );
											AnalysisData[ADISize][ADIArrangement][ADISort][5]++; /// Analysis
		// swap
		if( iSmallest > i )
		{
											AnalysisData[ADISize][ADIArrangement][ADISort][2]++; /// Analysis
			tmp = A[i];
			A[i] = A[iSmallest];
			A[iSmallest] = tmp;
											AnalysisData[ADISize][ADIArrangement][ADISort][1] += 3; /// Analysis
		}
		
		#ifdef DISPLAY_RESULTS
		PrintArray( A, size );
		#endif
	}
	
	#ifdef DISPLAY_RESULTS
	std::cout << "End SelectionSort" << std::endl;
	std::cout << "------------------------" << std::endl;
	#endif
}

// Find index of smallest value.
int IndexOfSmallest( int A[], int iStart, int iEnd )
{
	int index = -1;
	int aMin = A[iStart];
											AnalysisData[ADISize][ADIArrangement][ADISort][0] += 2; /// Analysis
	
	for( int i = iStart; i <= iEnd; i++ )
	{
		if( A[i] < aMin )
		{
											AnalysisData[ADISize][ADIArrangement][ADISort][2]++; /// Analysis
			aMin = A[i];
			index = i;
											AnalysisData[ADISize][ADIArrangement][ADISort][1] += 2; /// Analysis
		}
	}
	
	#ifdef DISPLAY_RESULTS
	std::cout << "IndexOfSmallest:  " << index << std::endl;
	#endif
	
	return index;
}

//////////////////////////////////////////////////

// Sort an array a, using the quicksort algorithm.
void Quicksort( int a[], int first, int last ) 
{
	int pivot;
											AnalysisData[ADISize][ADIArrangement][ADISort][0]++; /// Analysis
	
	if( first < last ) {
											AnalysisData[ADISize][ADIArrangement][ADISort][2]++; /// Analysis
		pivot = Pivot( a, first, last );
		Quicksort( a, first, pivot-1 );
		Quicksort( a, pivot+1, last );
											AnalysisData[ADISize][ADIArrangement][ADISort][5] += 3; /// Analysis
	}
}

// Find and return the index of pivot element.
int Pivot( int a[], int first, int last ) 
{
	int  p = first;
	int pivot = a[first];
											AnalysisData[ADISize][ADIArrangement][ADISort][0] += 2; /// Analysis
	
	for( int i = first+1 ; i <= last ; i++ ) {
		if( a[i] <= pivot ) {
											AnalysisData[ADISize][ADIArrangement][ADISort][2]++; /// Analysis
			p++;
											AnalysisData[ADISize][ADIArrangement][ADISort][1]++; /// Analysis
			Swap( a[i], a[p] );
											AnalysisData[ADISize][ADIArrangement][ADISort][5]++; /// Analysis
		}
	}
	
	Swap( a[p], a[first] );
											AnalysisData[ADISize][ADIArrangement][ADISort][5]++; /// Analysis
	
	return p;
}

// Swap two items (by reference).
void Swap( int &v1, int &v2 )
{
	int  tmp;
											AnalysisData[ADISize][ADIArrangement][ADISort][0]++; /// Analysis
	
	tmp = v1;
	v1 = v2;
	v2 = tmp;
											AnalysisData[ADISize][ADIArrangement][ADISort][1] += 3; /// Analysis
}
