/*
 * BaseToInt
 *
 * Gabe Gibler
 * CS120-03
 * Lab #9
 *
 */

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>

using namespace std;

int basetoint(string,int);
int chartoint(char,int);

string const hr = "* * * * * * * * * *";

void div();

int main()
{
	int base, result, response;
	string str;

	div();
	cout << "BaseToInt Converter" << endl;
	div();
	
	do {
		cout << "Enter the numerical representation you wish to convert (no spaces): ";
		cin >> str;
		cin.ignore();
		cout << "Enter the base of this number (2-16): ";
		cin >> base;
		cin.ignore();
		result = basetoint(str, base);
		if (result > -1)
			cout << endl << "The base(10) integer value of your base(" << base << ") number: " << result << endl << endl;
		else
			cout << endl << "There was an error converting the number." << endl << endl;
		
		cout << "Repeat (0 / 1)? ";
		cin >> response;
		cin.ignore();
		cout << endl;
	} while(response > 0);
	
	// Exit program
	div();
 	cout << "Press enter to exit." << endl;
	cin.ignore();
	return 0;
}

int basetoint(string str, int base) {
/*
The function returns the int value represented by the string. Upon error, return -1.
Handle bases 2 to 16.
Check for two kinds of errors:
• given base values are in the specified range [2-16].
• input characters are legal for the specified base
*/
	int digit, exp, result;
	int base_min = 2, base_max = 16;
	
	if (base < base_min || base > base_max) {
		return -1;
	} else {		
		result = 0;

		for (exp = 0; exp < str.length(); exp++)
		{
			// cout << digits[exp];
			digit = chartoint(str[exp], base);
			if (digit < 0)
				return -1;
			else
				result += digit * pow(base,str.length()-1-exp);
		}

		return result;
	}
}

int chartoint(char A, int base) {
	char values[22] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F', 'a', 'b', 'c', 'd', 'e', 'f'};
	int result = -1;

	// 48-57 "0-9"; 65-70 "A-F"; 97-102 "a-f";
	// int m = A-'a'+10;
	// int result = A - values[i] + i;
	
	for (int i=0; i < base && result < 0; i++) {
		if (A == values[i])
			result = i;
	}
	if (result < 0 && base > 10)
	{
		for (int j=16; j < 22 && result < 0; j++) {
			if (A == values[j])
				result = j-6;
		}
	}
	return result;
}

// Print a visual divider for textual output
void div() {
	cout << endl << hr << endl;
}