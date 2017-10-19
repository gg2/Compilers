/* 
 * filename.cpp
 *
 * CS 121 Sec 03 - Bolden.........Compiler version...........Your Name
 * Date .................Computer & CPU.............Your email address
 *
 * Brief description of program and objective.
 *---------------------------------------------------------------------
 */

#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

#include"stack.h"

string const hr = "* * * * * * * * * *";
int const COUT_PRECISION = 16;

void div();

int main()
{
	Stack Stk;
	double A = 999999999, B = 1010101010.1010101010, C = 12345678901.12345678901, D = 18.5, E = 1.0;
	
	cout.precision(COUT_PRECISION);
	
	div();
	cout << "Stack Test\n" << endl;
	div();
	
	cout << Stk.count() << " entries: " << Stk.print() << endl;;
	if (Stk.count() > 0) {
		cout << Stk.top() << " is the top of the stack.\n" << endl;
	}
	
	if (Stk.count() > 0) {
		double a = Stk.pop();
		cout << a << " removed. \n" << endl;
	} else {
		cout << "Nothing to remove yet.\n" << endl;
	}
	
	Stk.push(B);
	Stk.push(D * 1000000000000000000.000);
	Stk.push(C);
	Stk.push(A);

	cout << Stk.count() << " entries: " << Stk.print() << endl;;
	if (Stk.count() > 0) {
		cout << Stk.top() << " is the top of the stack.\n" << endl;
	}
	
	if (Stk.count() > 0) {
		double a = Stk.pop();
		cout << a << " removed. \n" << endl;
	} else {
		cout << "Nothing to remove yet.\n" << endl;
	}
	
	cout << Stk.count() << " entries: " << Stk.print() << endl;;
	if (Stk.count() > 0) {
		cout << Stk.top() << " is the top of the stack.\n" << endl;
	}
	
	// Exit program
	div();
 	cout << "Press enter to exit." << endl;
	cin.ignore();
	return 0;
}

// Print a visual divider for textual output
void div() {
	cout << endl << hr << endl;
}