/* The Fortune Teller -
 * a simple program introducing some
 * fundamental programming concepts.
 *
 * Gabe Gibler
 * CS120-03
 * Lab #1
 *
 * 1) Added comment header.
 * 2) Added an introductory message upon running the program.
 * 3) Modified the fortune outputs.
 */

#include<iostream> // include a library
using namespace std;

int main()  // main() starts the program
{
	// -------------- Variable Declarations ------------------
 	int favorite;  // create a variable to store the favorite number
        int disliked;  // create a variable to store the disliked number
	int lucky;     // create a variable to store the lucky number
	// ------------- Get user input -------------------------
	cout << "I am the Fortune Teller. I will tell you your (immediate) future." << endl;
	cout << "Please, have a seat... " << endl;
	cout << "Enter your favorite number (no decimals): ";  // output
	cin >> favorite;  		// user input
	cout << "Enter a number you don't like (no decimals): ";
	cin >> disliked;
	lucky = (favorite*disliked) % 10;
	cout << endl << "Today, your lucky number is: " << lucky << endl;
	if(lucky < 0){  // conditional, values less than 0
		cout << "I see a very dark future ahead for you." << endl;
	}
	if(lucky >= 0 && lucky < 5){ // 0 to 4 inclusive
		cout << "Today will be a day like every other. Don't let it get you down." << endl;
	}
	if(lucky >= 5 && lucky < 9){ // 5 to 8 inclusive
		cout << "Today, will be a very exciting day for you. Things are looking up!" << endl;
	}
	if(lucky == 9){ // exactly 9
		cout << "Pursue your dreams! You can't go wrong." << endl;
	}
	// ---------- Code to help the program exit "gracefully" -----
	cin.ignore();
 	cout << "Press enter to quit." << endl;
	cin.ignore();
	return 0;
}
