/*
 * Loops to Calculate Pi
 *
 * Gabe Gibler
 * CS120-03
 * Lab #4Pi
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
	double sum = 0;
	double result = 0;
	
	cout.precision(16);
	
	cout << endl << hr << endl;
	cout << "Approximating Pi";
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
		cout << endl << "The approximation will be calculated using " << iterations << " iterations." << endl << endl;
		
		// Perform the calculation
		cout << "# of iterations: result" << endl;
		cout << hr << endl;
		for (i = 1; i <= iterations; i++) {
			sum = sum + ((pow(-1, i+1))/((2 * i) - 1));
			result = 4 * sum;
			cout << i << ": " << result << endl;
		}
		
		// Display the result, and ... repeat?
		cout << endl << hr << endl;
		cout << "The final approximation after " << i-1 << " iterations is: " << result;
		
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