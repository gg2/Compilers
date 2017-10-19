/*
 * Point & Swap
 *
 * Gabe Gibler
 * CS120-03
 * Lab #13
 *
 * Part 1:
 * swap1, the function that only passes by value (not by reference, and not pointers), will not work; 
 *    Not without calling the function multiple times, anyway, and even then ... ; 
 *    Or interpreting and dissecting a different sort of result, and assigning those pieces to x and y; 
 *    In which case, you might as well just swap the variables directly.
 * And the results are ... correct! swap1 no works.
 *
 * Part 2:
 * When outputting beyond the upper bound of the array, we get some other "random" integers (or values interpreted as integers).
 * Similar thing when traversing negative lower bounds for the array -- start getting other numbers not assigned to the 10 slots of the array.
 * The increment operator appears to continue jumping 4 blocks of memory in either case.
 * 
 */

#include<iostream>
#include<cstdlib>

using namespace std;

string const hr = "* * * * * * * * * *";
// Function declarations
void div();
void inFloat(float &);
void results(float, float);
float swap1(float, float);
void swap2(float *, float *);
void swap3(float &, float &);

int main()
{
	div();
	cout << "Lab 13: Point & Swap" << endl;
	div();

	cout.precision(3);
	float x = 12;
	float y = 34;
	//float tmpx = x;
	//float tmpy = y;
	//inFloat(x);
	//inFloat(y);
	results(x,y); // to show the initial values
	cout << endl << "Swap 1: Begin!" << endl;
	swap1(x,y); // call the swap function
	results(x,y); // The values should be reversed, but are they?
	//tmpx = swap1(tmpy,tmpx); // call the swap function
	//results(tmpx,tmpy); // The values should be reversed, but are they?
	cout << endl << "Swap 2: Begin!" << endl;
	swap2(&x,&y); // call the swap function 
	results(x,y); // now the values should be reversed
	cout << endl << "Swap 3: Begin!" << endl;
	swap3(x,y); // call the swap function 
	results(x,y); // now the values should be reversed
	
	div();
	cout << endl << "Traversing int myArray[10] Using a Pointer" << endl << endl;
	
	int myArray[10] = {0,2,4,6,8,10,12,14,16,18};
	int *p_myArray = myArray;
	for (int ub=10; ub<14; ub++) {
		cout << "Outputting to upper bound: " << ub << endl;
		p_myArray = &myArray[0];
		for (int i=0; i<ub; i++) {
			cout << "Address: " << p_myArray << "; Value: " << *p_myArray++ << endl;
		}
	}
	p_myArray = myArray;
	for (int lb=0; lb>-4; lb--) {
		cout << "Outputting with lower bound: " << lb << endl;
		p_myArray = &myArray[lb];
		for (int i=lb; i<10; i++) {
			cout << "Address: " << p_myArray << "; Value: " << *p_myArray++ << endl;
		}
	}
	
	// Exit program
	div();
 	cout << "Press enter to exit." << endl;
	cin.ignore();
	return 0;
}

float swap1(float a, float b) {
	float tmp = a;
	a = b;
	b = tmp;
	return tmp;
}
void swap2(float *a, float *b) {
	float tmp = *a;
	*a = *b;
	*b = tmp;
}
void swap3(float &a, float &b) {
	float tmp = a;
	a = b;
	b = tmp;
}

void inFloat(float &var) {
	bool valid = true;
	cout << "Enter a value (float): ";
	cin >> var;
	cin.ignore();
	while (!valid) {
		valid = true;
	}
}
void results(float x, float y) {
	cout << "x == " << x << "; y == " << y << ";" << endl;
}
// Print a visual divider for textual output
void div() {
	cout << endl << hr << endl;
}