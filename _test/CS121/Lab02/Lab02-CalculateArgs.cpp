/* 
 * Gabe Gibler
 * CS121 Sec 03
 * Lab #2 - Calculation upon Arguments
 * 2015/01/29
 *
 */

#include<iostream>
#include<cstdlib>

using namespace std;

void printMainArgs(int, char *[]);
int checkMainArgs(int, char *[], int);
void convertArgToInt(char[], int*);
void convertArgToFloat(char[], float*);
float calculate(float, float, string);

int main(int argc, char *argv[]) {
	const int MinArgc = 4;
	float arg1 = 0.0;
	float arg3 = 0.0;
	 
	cout << "\nCommand Line Arguments: \nUsing in a Calculation\n" << endl;
	// Informing user what's happening
	// Skipped for lab output
	if (1 == 0)  {
		cout << "Arguments 1 and 3 are converted to float. \nArgument 2 is used as the operator.\n";
		cout << "e.g. ./Program.exe 2 * 3.0\n";
		cout << "Argument 3 may not be a zero if dividing.\n" << endl;
	}
	
	printMainArgs(argc, argv);
	
	// Performing calculations upon arguments provided
	// But only if minimum number of arguments provided
	if (checkMainArgs(argc, argv, MinArgc) == 1) {
		// Verbal feedback regarding number of command line arguments
		cout << "Insufficient command line arguments provided.\n";
		cout << "(A minimum of " << MinArgc-1 << " arguments must be supplied.)\n" << endl;
	} else {
		convertArgToFloat(argv[1], &arg1);
		convertArgToFloat(argv[3], &arg3);
		
		cout << arg1 << " " << argv[2] << " " << arg3 << " == " << calculate(arg1, arg3, argv[2]);
		cout << endl;
	}
	return 0;
}

// Print command line arguments
void printMainArgs(int c, char *args[]) {
	for (int i=0; i < c; i++) {
		cout << "args[" << i << "]: " << args[i] << "\n";
	}
	cout << endl;
}

// Check commandline arguments for desired quantity and data types
int checkMainArgs(int c, char *args[], int min) {
	int result = 0;
	
	if (c < min) {
		result = 1;
	}
	for (int i=1; i < c; i++) {
		// Check each command line argument for desired values
		// Not implemented
		switch (i) {
			default:
				// Nothing yet.
				break;
		}		
	}
	
	return result;
}

// Converts a c-style string command line argument to an integer
// Accepts: the variable for assigning the result to.
void convertArgToInt(char a[], int* i) {
	*i = atoi(a);
}

// Converts a c-style string command line argument to a float
// Accepts: the variable for assigning the result to.
void convertArgToFloat(char a[], float* f) {
	*f = atof(a);
}

// Performs a calculation on two floating point values
// Accepts: two floats, and the operator as a c-style string
// Returns: floating point value
float calculate(float x, float y, string o) {
	float result = 0.0;
	
	//cout << x << " " << o << " " << y << " ";
	if (o == "+" || o == "plus" || o == "add") {
		result = x + y;
	} else if (o == "-" || o == "minus" || o == "subtract") {
		result = x - y;
	} else if (o == "*" || o == "x" || o == "times" || o == "multiply") {
		result = x * y;
	} else if (o == "/" || o == "divide") {
		if (y == 0)
			cerr << "! division by zero >> Lab02-CalculateArgs.cpp, function calculate().";
		else
			result = x / y;
	} else {
		cerr << "! unsupported operator provided >> Lab02-CalculateArgs.cpp, function calculate().";
		// Do nothing.
	}
	
	return result;
}