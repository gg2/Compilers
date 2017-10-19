/*
 * Recursive Functions
 *
 * Gabe Gibler
 * CS120-03
 * Lab #14
 *
 */

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

string const hr = "* * * * * * * * * *";

void div();
int formula(int);

int main(int argc, char *argv[])
{
	div();
	cout << "Recurrence Relations" << endl;
	div();
	cout << endl;
	
	if (argc > 1) {
		for (int i=1; i<argc; i++) {
			cout << formula(atoi(argv[i]));
			div();
			cout << endl;
		}
	} else {
		cout << "No command line arguments provided." << endl;
		cout << "The program will end." << endl;
		div();
	}
	
	// Exit program
	return 0;
}

int formula(int x) {
	if (x <= 0) {
		return 0;
	} else {
		if (x % 2 == 0) {
			return formula(x/2);
		} else {
			return (1 + formula(x-1));
		}
	}
}

// Print a visual divider for textual output
void div() {
	cout << endl << hr << endl;
}