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
#include<cstring>
#include<cmath>
#include<time.h>

using namespace std;

string const hr = "* * * * * * * * * *";

void div();

int main()
{
	srand(time(NULL));

	div();
	cout << "Program Template" << endl;
	div();

	string s = "0123456789ABCDEF.";
	for (int i=0; i < s.length(); i++) {
		char a = s[i];
		if ((a == 46) || (a > 47 && a < 58)) {
			cout << a << " is a number (or period)." << endl;
		} else {
			cout << a << " is not a number." << endl;
		}
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