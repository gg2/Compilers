/*
 * CS 121 Class Examples
 *
 */

#include<iostream>
#include<cstdlib>
#include<cstring>

using namespace std;

void SwapTwoInts(int, int);
void SwapTwoIntsC(int, int);


void main() 
{
	int x, y;
	SwapTwoInts(x,y);
	SwapTwoIntsC(&x,&y);
	
	// 20150116 (Fri)
	// Pointers
	int a;
	int *aPtr;
	
	a = 5;
	cout << a << endl;
	aPtr = &a;
	cout << *aPtr << endl; // contents of a 
	*aPtr = 6;
	cout << a << endl;
	cout << *aPtr << endl; // contents of a
	cout << &a << endl; // address of a
	
	// Arrays and Pointers
	int a[5] = { 5, 10, 15, 20, 25 };
	int *aPtr;
	
	aPtr = a;
	cout << *aPtr << endl;
	aPtr = &a[0];
	cout << *aPtr << endl;
	aPtr = &a[2];
	cout << *aPtr << endl;
	
	// Pointer arithmetic
	int a[5] = { 1, 3 , 5 , 7, 11 };
	int *aPtr;
	
	aPtr = a;
	cout << aPtr << endl;
	cout << *aPtr << endl;
	aPtr += 3; // Advance aPtr by 3 blocks
	cout << aPtr << endl;
	cout << *aPtr << endl;
	cout << a[3] << endl;
	
	
	return 0;
}

// C++
void SwapTwoInts(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}
// ... vs ...
// C
void SwapTwoIntsC(int *a, int *b) 
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}