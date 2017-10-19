/* 
 * Lab 04
 * Reverse Polish Notation (RPN) Calculator
 *
 * CS 121 Sec 03 - Bolden
 * Gabe Gibler
 * gibl3465@vandals.uidaho.edu
 * Feb 16, 2015
 *
 *---------------------------------------------------------------------
 */
 
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstring>

using namespace std;

#include"RPNCalc.h"
bool processInput(RPNCalc&,string);
bool isNumber(string);

int main()
{
	bool proceed = true;
	string input;
	RPNCalc RPN;
	 
	cout << "\nReverse Polish Notation (RPN) Calculator\n" << endl;
	
	while (proceed) {
		// Display top of stack
		cout << "\n" << RPN.result() << " > ";
		// Get the command
		std::getline(cin, input);
		// Process the command
		proceed = processInput(RPN, input);
	}
	
	// Exit program
	cout << "\n" << endl;
	return 0;
}

bool processInput(RPNCalc &RPN, string str) {
	bool proceed = true;
	string chunk[str.length()];
	char delimiter = ' ';
	
	// Cycle through input string and parse out segments
	int j = 0;
	for (int i=0; i < str.length(); i++) {
		chunk[i] = ""; // Making sure every spot in the array is at least empty.
		if (str[i] != delimiter) {
			chunk[j] += str[i];
		} else {
			j++;
		}
	}
	// Cycle through the segments and act on valid input
	for (int i=0; i < str.length(); i++) {
		if (chunk[i] != "") {
		// Available operators: +, -, *, x, /
		// Available commands: sq, sqrt, dup, swap, ps, quit
			if (chunk[i] == "quit") {
				proceed = false;
			}
			else if (chunk[i] == "+") {
				RPN.add();
			}
			else if (chunk[i] == "-") {
				RPN.subtract();
			}
			else if (chunk[i] == "*" || chunk[i] == "x") {
				RPN.multiply();
			}
			else if (chunk[i] == "/") {
				RPN.divide();
			}
			else if (chunk[i] == "sq") {
				RPN.sq();
			}
			else if (chunk[i] == "sqrt") {
				RPN.sqrt();
			}
			else if (chunk[i] == "dup") {
				RPN.dup();
			}
			else if (chunk[i] == "swap") {
				RPN.swap();
			}
			else if (chunk[i] == "ps") {
				cout << "Stack contents: " << RPN.ps();
			} else {
				// If it is a number, push it to the stack; 
				// Otherwise it gets discarded.
				if (isNumber(chunk[i])) {
					RPN.store(strtod(chunk[i].c_str(),NULL));
				}
			}
		}
	}
	return proceed;
}

bool isNumber(string s) {
	bool valid = true;
	char a;
	for (int i=0; i < s.length(); i++) {
		a = s[i];
		// ASCII 48-57 [0-9], 46 [.]
		if (!((i == 0 && a == 45) || (a == 46) || (a > 47 && a < 58))) {
			valid = false;
		}
	}
	return valid;
}
