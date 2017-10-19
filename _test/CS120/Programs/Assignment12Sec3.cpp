/*
 * Program Template
 *
 * Gabe Gibler
 * CS120-03
 * Assignment #12
 *
 */

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

string const hr = "* * * * * * * * * *";

void div();
int square(int);

int main()
{
	int x = -1;
	char a = 'y';
	
	div();
	cout << "Finding the Square (Recurrence Relations)" << endl;
	div();
	while(a == 'y') {
		while(x < 0) {
			cout << "Please enter an integer (must be greater than or equal to 0) to find its square: ";
			cin >> x;
			cin.ignore();
		}
		cout << x << " squared == " << square(x) << endl;
		x = -1;
		div();
		
		cout << "Do again (y/n)? ";
		cin >> a;
	}
	
	// Exit program
	cin.ignore();
	return 0;
}

int square(int x) {
	if (x < 1)
		return 0;
	else
		return ( (2*(x-1)) + 1 + square(x-1) );
}
	
// Print a visual divider for textual output
void div() {
	cout << endl << hr << endl;
}