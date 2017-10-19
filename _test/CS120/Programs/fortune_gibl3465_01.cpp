/* The Fortune Teller -
 * a simple program introducing some
 * fundamental programming concepts.
 *
 * Modified 2014/08/29 by Gabe Gibler
 * CS120-03
 * Assignment #1
 *
 * 1) Modified the program to ask for and accept input from the user for their year of birth.
 * 2) Incorporated the birth year into the calculation of the "lucky number".
 * 3) Modified the conditionals to supply a message for 0 exactly, 1-6, 7 exactly, and 8-9; 
 *    plus a catch for >9, not that it should ever happen.
 * 4) Incorporated a 4th question that receives string input
 *    and uses the numeric value of its 1st letter in the calculation of the "lucky number".
 */
 
#include<iostream> // include a library
using namespace std;

int main()  // main() starts the program
{
	// -------------- Variable Declarations ------------------
 	int favorite;  // variable to store the favorite number
        int disliked;  // variable to store the disliked number
        int birthyear; // variable to store the year of birth
        string totemtext("gnu"); // variable to store their totem animal
        int totem;  // variable to store the char converted from totemtext
	int lucky;     // variable to store the lucky number
	// ------------- Get user input -------------------------
	cout << "Enter your favorite number (no decimals): ";  // output
	cin >> favorite;  		// user input
	cout << "Enter a number you don't like (no decimals): ";
	cin >> disliked;
	cout << "Now, what year were you born? (Like 1999, or 99. Numbers only!) ";
	cin >> birthyear;
	cout << "What is your spirit animal? ";
	cin >> totemtext;
	if(totemtext != ""){ // make sure we have some text
		char a = totemtext[0];
		totem = (int)a;
	}else{ // otherwise assign a default
		totem = 1;
	}
	lucky = ((favorite*disliked)+(birthyear*totem)) % 10;
	cout << endl << "Your secret, lucky number for today is: " << lucky << endl;
	if(lucky < 0){  // conditional, values less than 0
		cout << "Try to be less negative." << endl;
	}
	if(lucky == 0){ // exactly 0
		cout << "Aim for your dreams! You can't miss!" << endl;
	}
	if(lucky > 0 && lucky < 7){ // 1 to 6 inclusive
		cout << "Today is just a regular day. Keep on trucking." << endl;
	}
	if(lucky == 7){ // exactly 7
		cout << "Today is your lucky day! Hit the casinos!" << endl;
	}
	if(lucky > 7 && lucky <= 9){ // 8 to 9 inclusive
		cout << "Today you should embrace technology." << endl;
	}
	if(lucky > 9){ // should never happen
		cout << "You're gifted! You can do things nobody else can do." << endl;
	}
	// ---------- Code to help the program exit "gracefully" -----
	cin.ignore();
 	cout << "And there you have it. Press enter to quit." << endl;
	cin.ignore();
	return 0;
}
