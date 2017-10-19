/* 
 * Gabe Gibler
 * CS121 Sec 03
 * Lab #2 - Arguments Manipulation
 * 2015/01/29
 *
 * 1) I'm converting the 3rd argument to float, rather than the 2nd, in preparation for natural input as a "calculator".
 */

#include<iostream>
#include<cstdlib>

using namespace std;

void printMainArgs(int, char *[]);
int checkMainArgs(int, char *[], int);
void convertArgToInt(char[], int*);
void convertArgToFloat(char[], float*);

int main(int argc, char *argv[]) {
	const int MinArgc = 4;
	int arg1 = 0;
	float arg3 = 0.0;
	 
	cout << "\nCommand Line Arguments\n" << endl;
	
	printMainArgs(argc, argv);
	
	// Verbal feedback regarding number of command line arguments
	cout << (checkMainArgs(argc, argv, MinArgc) ? "Insufficient command line arguments provided." : "Minimum number of command line arguments provided.") << endl;
	cout << "(A minimum of " << MinArgc-1 << " arguments must be supplied.)" << endl;
	
	// Converting arguments to specific datatypes
	// But only if minimum number of arguments provided
	if (checkMainArgs(argc, argv, MinArgc) == 0) {
		convertArgToInt(argv[1], &arg1);
		cout << "Converted argument to int: " << arg1 << endl;
		convertArgToFloat(argv[3], &arg3);
		cout << "Converted argument to float: " << arg3 << endl;
	}
	return 0;
}

// Print command line arguments
void printMainArgs(int c, char *args[]) {
	for (int i=0; i < c; i++) {
		cout << "args[" << i << "]: " << args[i] << endl;
	}
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

void convertArgToInt(char a[], int* i) {
	*i = atoi(a);
}
void convertArgToFloat(char a[], float* f) {
	*f = atof(a);
}
