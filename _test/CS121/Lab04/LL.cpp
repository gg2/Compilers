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

#include"linkedlist.h"

string const hr = "* * * * * * * * * *";

void div();

int main()
{
	linkedlist LL;
	double A = 999999999.999999999, B = 1010101010.1010101010, C = 12345678901.12345678901, D = 18.5;
	
	div();
	cout << "Linked List Test\n" << endl;
	div();
	
	cout << LL.getCount() << " entries: " << LL.getList() << endl;

	if (LL.getCount() > 0) {
		LL.remove(LL.getLast());
		cout << A << " removed. " << LL.getCount() << " entries remaining: " << LL.getList() << endl;
	} else {
		cout << "Nothing to remove yet.\n" << endl;
	}
	
	LL.insert(B);
	LL.insert(D * 1000000000000000000.000);
	LL.insert(C);
	LL.insert(A);

	cout << LL.getCount() << " entries: " << LL.getList() << endl;

	if (LL.getCount() > 0) {
		double X = LL.getLast();
		LL.remove(X);
		cout << X << " removed. " << LL.getCount() << " entries remaining: " << LL.getList() << endl;
	} else {
		cout << "Nothing to remove yet.\n" << endl;
	}
	
	cout << LL.getCount() << " entries: " << LL.getList() << endl;

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