/*
 * Loops to Calculate e
 *
 * Gabe Gibler
 * CS120-03
 * Lab #4e
 *
 * Enclosed the program in a while loop to easily run the approximation again.
 *
 */

#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int main()
{
	// Variable declarations
	string const hr = "* * * * * * * * * *";
	string confirm = "y";
	int iterations = 10;
	int i = 0;
	int j = 0;
	double sum = 0;
	double result = 0;

	cout.precision(16);
	
	cout << endl << hr << endl;
	cout << "Approximating e";
	cout << endl << hr << endl << endl;
	
	while (confirm == "y" || confirm == "Y") {
		// Reset values if repeating
		iterations = 10;
		sum = 0;
		result = 0;

		// Select the number of iterations (or not)
		cout << "Would you like to select the number of iterations? (y/n) ";
		cin >> confirm;
		
		if (confirm == "y" || confirm == "Y") {
			cin.ignore();
			cout << "Number of iterations (integer): ";
			cin >> iterations;
		}
		
		cin.ignore();
		cout << endl << "The approximation will be calculated using " << iterations << " iterations." << endl;
		
		// Perform the calculation
		cout << "# of iterations: result" << endl;
		cout << hr << endl;
		for (i = 0; i < iterations; i++) {
			double k = 1;
			if (i > 0) {
				for (j = 1; j <= i; j++) {
					k = k * j;
				}
			}
			sum = sum + (1/k);
			result = sum;
			cout << i << ": " << result << endl;
		}
		
		// Display the result, and ... repeat?
		cout << endl << hr << endl;
		cout << "The final approximation after " << i << " iterations is: " << result;
		
		cout << endl << endl << "Would you like to run through this approximation again? (y/n) ";
		cin >> confirm;
		cin.ignore();
	}

	// Exit program
	cout << endl << hr << endl;
 	cout << endl << "Press enter to exit." << endl;
	cin.ignore();
	return 0;
}