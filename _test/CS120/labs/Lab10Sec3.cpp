/*
 * Functions Review
 *
 * Gabe Gibler
 * CS120-03
 * Lab #10
 *
 */

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<time.h>

using namespace std;

string const hr = "* * * * * * * * * *";
const double PI = 3.1417;

void div();
int sum(int,int);
int min(int,int);
double circumference(double);
void swap(double&,double&);
void swap(int[]);
void increment(int[],int);

int main()
{
	srand(time(NULL));

	div();
	cout << "Functions Review" << endl;
	div();
	
	int sumA = 1000000000, sumB = 1000000000;
	int minA = 0, minB = -255;
	double rad = PI;
	double swapA = 1.2, swapB = 3.4;
	int lenA = 2;
	int swapArr[lenA];
	int len = 7;
	int incr[len];
	
	cout << endl;
	cout << "sum(" << sumA << "," << sumB << ") == " << sum(sumA,sumB) << endl << endl;
	cout << "min(" << minA << "," << minB << ") == ";
		if (min(minA,minB) == 0 && minA == minB)
			cout << "[the values are equal]" << endl;
		else
			cout << min(minA,minB) << endl;
		cout << endl;
	cout << "The circumference of a circle of radius " << rad << " is " << circumference(rad) << endl << endl;
	cout << "Swapping " << swapA << " and " << swapB << " ... " << endl;
		swap(swapA,swapB);
		cout << "Result: " << swapA << " and " << swapB << endl << endl;
	cout << "Swapping the values of an array: " << endl;
		cout << "Originally {";
		for (int i=0; i < lenA; i++) {
			swapArr[i] = rand() % 100;
			cout << swapArr[i];
			if (i != lenA-1)
				cout << ", ";
		}
		cout << "}" << endl;
		swap(swapArr);
		cout << "Finally {";
		for (int i=0; i < lenA; i++) {
			cout << swapArr[i];
			if (i != lenA-1)
				cout << ", ";
		}
		cout << "}" << endl << endl;
	cout << "Incrementing the values of an array: " << endl;
		cout << "Originally {";
		for (int i=0; i < len; i++) {
			incr[i] = rand() % 100;
			cout << incr[i];
			if (i != len-1)
				cout << ", ";
		}
		cout << "}" << endl;
		increment(incr,len);
		cout << "Finally {";
		for (int i=0; i < len; i++) {
			cout << incr[i];
			if (i != len-1)
				cout << ", ";
		}
		cout << "}" << endl << endl;
	
	// Exit program
	div();
 	cout << "Press enter to exit." << endl;
	cin.ignore();
	return 0;
}


// A function named sum() that returns the sum of two integers that are passed to the function as arguments.
int sum(int a, int b) {
	return a + b;
}
// A function named min() that returns the smaller of two integers that are passed to the function as arguments. If both arguments are the same the function should return zero
int min(int a, int b) {
	if (a < b)
		return a;
	else if (b < a)
		return b;
	else
		return 0;
}
// A function named circumference() that takes one double as an argument and returns the circumference of a circles with a radius that is equal to the value passed in as an argument. The function should use 3.1417 for PI and that value should be stored as a global constant.
double circumference(double r) {
	return 2.0 * PI * r;
}
// A function named swap() that swaps the values of two arguments of type double. The arguments should be passed to the function using pass-by-reference.
void swap(double &a, double &b) {
	double tmp = a;
	a = b;
	b = tmp;
}
// A function named swap() that is passed an array of size two and swaps the two values in the array.
void swap(int array[]) {
	int tmp = array[0];
	array[0] = array[1];
	array[1] = tmp;
}
// A function named increment() that adds one to every element of an array. The function takes two arguments: an array of integers (the array can be of any size) and a single integer representing the length of the array.
void increment(int array[], int len) {
	for (int i = 0; i < len; i++)
		array[i]++;
}

// Print a visual divider for textual output
void div() {
	cout << endl << hr << endl;
}