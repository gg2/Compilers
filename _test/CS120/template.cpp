/*
 * Program Template
 *
 * Gabe Gibler
 * CS120-03
 * Assignment #XX
 * Lab #XX
 *
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

	cin.ignore();
	
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