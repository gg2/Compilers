/* 
 * A simple calculator program,
 * controlled by a menu and 
 * divided into separate functions
 * 
 * Modified 2014/10/03 by Gabe Gibler
 * CS120-03
 * Assignment #5
 * 
 * 1) Added Subtraction and Multiplication functions and options
 * 2) Added a minimum function and option
 * 3) Added a maximum function and option
 * 4) Added an option for returning a random number between 0 and a desired maximum
 * 5) Added a function for returning the length of a string
 * 6) Modified to display a confirmation of the operation
 * 
 */

#include<iostream>
#include<cstdlib>
#include<time.h>
#include<string>

using namespace std;

//---------- Function Prototypes -----------
void print_menu();
double get_value();
string get_string();
double add(double,double);
double subtract(double,double);
double multiply(double,double);
double divide(double,double);
double minimum(double,double);
double maximum(double,double);
double b_rand(double);
int str_len(string);

//--------------  Main -------------------
int main()
{
	double operand1, operand2, answer;
	string string_input;
	int choice;
	
	cout.precision(16);
	
	do {
		print_menu();
		cin >> choice;
		cout << endl;
		
		switch(choice) {
			case 0:                    // program will exit
				break;
			case 1:                    // addition
				operand1 = get_value();
				operand2 = get_value();
				answer = add(operand1, operand2);
				break;
			case 2:                    // addition
				operand1 = get_value();
				operand2 = get_value();
				answer = subtract(operand1, operand2);
				break;
			case 3:                    // addition
				operand1 = get_value();
				operand2 = get_value();
				answer = multiply(operand1, operand2);
				break;
			case 4:                    // division
				operand1 = get_value();
				operand2 = get_value();
				answer = divide(operand1,operand2);
				break;
			case 5:                    // minimum
				operand1 = get_value();
				operand2 = get_value();
				answer = minimum(operand1,operand2);
				break;
			case 6:                    // minimum
				operand1 = get_value();
				operand2 = get_value();
				answer = maximum(operand1,operand2);
				break;
			case 7:                    // random
				operand1 = get_value();
				answer = b_rand(operand1);
				break;
			case 8:										 // programmer's option
				string_input = get_string();
				cout << "Length of \"" << string_input << "\": " << str_len(string_input);
				choice = -1; // make it skip printing the calculation-oriented output
				break;
			default:
				choice = -1;   // choice is invalid
				cout << "Invalid choice." << endl;
		}
		if(choice > 0) {   // if choice is valid, print the answer
			cout << " = " << answer << endl;
		}
	} while(choice != 0);    // if not 0, loop back to start
	return 0;
}

//--------------  Functions -------------------
double add(double operand1, double operand2) {
	cout << operand1 << " + " << operand2;
	return operand1 + operand2;
}
double subtract(double operand1, double operand2) {
	cout << operand1 << " - " << operand2;
	return operand1 - operand2;
}
double multiply(double operand1, double operand2) {
	cout << operand1 << " * " << operand2;
	return operand1 * operand2;
}
double divide(double dividend, double divisor) {
			cout << dividend << " / " << divisor;
      if(divisor == 0){
            return 0;  // avoids divide by zero errors
      }
      else
            return (dividend/divisor);
}
double minimum(double operand1, double operand2) {
	cout << "Lesser of " << operand1 << " and " << operand2;
	if (operand1 < operand2) {
		return operand1;
	} else {
		return operand2;
	}
}
double maximum(double operand1, double operand2) {
	cout << "Greater of " << operand1 << " and " << operand2;
	if (operand1 > operand2) {
		return operand1;
	} else {
		return operand2;
	}
}
double b_rand(double input) {
	int maximum = (int)input;
	cout << "Random number from 0-" << maximum;
	srand(time(NULL));
	return ((rand() % (maximum + 1)) * 1.0);
}
int str_len(string str) {
	return str.length();
}
//----------------- get_value function ----------------
double get_value() {
	double temp_value;
	cout << "Please enter a value: ";
	cin >> temp_value;
	cin.ignore();
	return temp_value;
}
string get_string() {
	string str;
	cout << "Please enter a value: ";
	cin >> str;
	cin.ignore();
	return str;
}
//-------------------- print_menu function -------------
void print_menu() {
     cout << endl;
     cout << "Add (1)" << endl;
     cout << "Subtract (2)" << endl;
     cout << "Multiply (3)" << endl;
     cout << "Divide (4)" << endl;
     cout << "Minimum (5)" << endl;
     cout << "Maximum (6)" << endl;
     cout << "Random Number (7)" << endl;
     cout << "String Length (8)" << endl;
     cout << "Exit (0)" << endl;
     cout << "Enter your choice: ";
}