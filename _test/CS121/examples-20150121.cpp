/*
 *
 */

#include<iostream>
#include<cstdlib>

using namespace std;

void PrintArray(int*,int);

void main() {
	int sizeA;
	int *pArr;

	cout << "Array size: " << flush;
	cin >> sizeA;
	
	pArr = new int[sizeA];

	PrintArray(pArr, sizeA);

	return 0;
}

void PrintArray(int *A, int nA) {
	for (int i=0; i < nA; i++) {
		cout << A[i]o << " ";
	}
}