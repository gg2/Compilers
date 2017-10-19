/* The Fortune Teller -
 * a simple program introducing some
 * fundamental programming concepts.
 *
 * Modified 2014/09/10 by Gabe Gibler
 * CS120-03
 * Assignment #2
 *
 * 1) Added a welcome statement.
 * 2) Added input for first and last name.
 * 3) Utilized names in output.
 * 4) Modified the lucky number calculation to include length of first and last names
 * 5) Modified the fortunes, to (mostly) have one for every two results. (0 and 7 are still separate. Why not!?)
 * 6) Added a bit more to the graceful exit.
 * 
 */
 
#include<iostream> // include a library
#include <boost/algorithm/string.hpp>
using namespace std;
using namespace boost::algorithm;

int main()  // main() starts the program
{
	// -------------- Variable Declarations ------------------
	const string magical_mist = "* + * + * + * + * + * + * + * + * + * + ";  // 
	string firstname;  // stores their first name
	string lastname;   // stores their last name
 	int favorite;  // stores the favorite number
        int disliked;  // stores the disliked number
        int birthyear; // stores the year of birth
        string totemtext("gnu"); // stores their totem animal
        int totem;  // stores the char converted from totemtext
	int lucky;     // stores the resultant lucky number

	// ------------- Opening welcome statement --------------
	cout << endl << magical_mist << endl;
	cout << "I am the Fortune Teller. I will tell your fortune." << endl;
	cout << magical_mist << endl;
	cout << endl << "Please ... have a seat." << endl;

	// ------------- Get user input -------------------------
	cout << "First, what is your first name? ";
	cin >> firstname;
	cin.ignore();  // keep the user from messing things up with a bunch of enters
	cout << "And your last name? ";
	cin >> lastname;
	cin.ignore();
	trim(firstname);
	trim(lastname);
	if(firstname == "") { // make sure the name is not blank
		firstname = "Naughty";
	}
	if(lastname == "") { // make sure the name is not blank
		lastname = "Monkey";
	}
	cout << "Very good, " << firstname << ". " << endl;
	cout << "Now, what year were you born? (As in 1999, or 99. Numbers only!) ";
	cin >> birthyear;
	cout << "What is your favorite number today (no decimals)? ";
	cin >> favorite;
	cout << "What is a number you don't like (no decimals)? ";
	cin >> disliked;
	cout << "What is your spirit animal, " << firstname << "? ";
	cin >> totemtext;
	if(totemtext != ""){ // make sure we have some text
		char a = totemtext[0];
		totem = (int)a;
	}else{ // otherwise assign a default
		totem = 1;
	}
	
	cout << endl << magical_mist << endl;
	cout << firstname << "! An image is forming... " << endl;
	cout << magical_mist << endl;

	lucky = (((firstname.size()/lastname.size())*100)+(favorite*disliked)+(birthyear*totem)) % 10;
	cout << endl << "Your lucky number for today is: " << lucky << endl;
	if(lucky < 0){  // conditional, values less than 0
		cout << "Try to be less negative. Things aren't as bad as you think." << endl;
	}
	if(lucky == 0){ // exactly 0
		cout << "Aim for your dreams, " << firstname << "! You can't miss!" << endl;
	}
	if(lucky > 0 && lucky < 3){ // 1 or 2
		cout << "Today is just a regular day. Keep on trucking." << endl;
	}
	if(lucky > 2 && lucky < 5){ // 3 or 4
		cout << "Today is a day like every other. " << endl << "But, tomorrow, make sure to wear clean underwear." << endl;
	}
	if(lucky > 4 && lucky < 7){ // 5 or 6
		cout << "Today is a day for love. " << endl << "You should spend time with the ones you love, " << endl << "or talk to that special someone you've been thinking about." << endl;
	}
	if(lucky == 7){ // exactly 7
		cout << "Today is your lucky day, " << firstname << "! Hit the casinos! Buy a lottery ticket! Ask for a raise!" << endl;
	}
	if(lucky > 7 && lucky < 10){ // 8 or 9
		cout << "Today you should embrace technology. Buy a new laptop or tablet." << endl;
	}
	if(lucky > 9){ // should never happen
		cout << "You're very gifted, " << firstname << " " << lastname << "! You can do things nobody else can do." << endl;
	}

	// ---------- Code to help the program exit "gracefully" -----
	cout << endl << magical_mist << endl;
 	cout << "The spirits have spoken. They will tell me nothing more for now. " << endl;
	cout << magical_mist << endl;
 	cout << endl << "Thank you for coming to see me, " << firstname << "." << endl;
 	cout << "Press enter to exit... " << endl;
	cin.ignore();
	return 0;
}
