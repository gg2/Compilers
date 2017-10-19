#include <iostream>
#include <cstdlib>
#include "fraction.h"

using namespace std;

int menu();
int read_value(string s);

int main()
{
	int choice, num, den;
	fraction one; // sets the default numerator to 0 and denominator to 1
	fraction two(2, 3); // set the numerator to 2 and the denominator to 3
	fraction result;

	do
	{
		choice = menu();

		switch(choice)
		{
			case 1:
				cout << "fraction one is: " << one.getNum() << "/" << one.getDen() << endl;

				num = read_value("numerator");
				one.setNum(num);

				den = read_value("denominator");
				one.setDen(den);
				one.reduce();

				cout << "fraction one is: " << one.getNum() << "/" << one.getDen() << endl;
				break;

			case 2:
				cout << "fraction two is: " << two.getNum() << "/" << two.getDen() << endl;

				num = read_value("numerator");
				two.setNum(num);

				den = read_value("denominator");
				two.setDen(den);
				two.reduce();

				cout << "fraction two is: " << two.getNum() << "/" << two.getDen() << endl;
				break;

			case 3:
				// NOTE the fraction will always be printed in reduced form
				cout << "fraction one is: " << one.getNum() << "/" << one.getDen() << endl;
				cout << "fraction two is: " << two.getNum() << "/" << two.getDen() << endl;
				break;

			case 4:
				if(one.equals(two))
					cout << "fraction one is the same as fraction two" << endl;

				else
					cout << "fraction one is NOT the same as fraction two" << endl;
				break;

			case 5:
				result = one.add(two);
				cout << "The result of " << one.getNum() << "/" << one.getDen() << " + " << two.getNum() << "/";
				cout << two.getDen() << " is " << result.getNum() << "/" << result.getDen() << endl;
				break;

			default:
				cout << "You have chosen to quit" << endl;
				cout << "GOODBYE!" << endl;

		}// end switch


	}while(choice != 6);

	return 0;

}// end main

int menu()
{

	int choice;

	cout << "Please choose from the following" << endl;
	cout << "1) Change the value of fraction one" << endl;
	cout << "2) Change the value of fraction two" << endl;
	cout << "3) Print the values of the fractions" << endl;
	cout << "4) Verify fraction one is equal to fraction two" << endl;
	cout << "5) Add fraction one to fraction two to get a result" << endl;
	cout << "6) Quit" << endl;
	cout << "Choice --> ";
	cin >> choice;

	while(choice < 1 || choice > 6)
	{
		cout << endl << "Invalid choice " << endl << endl;

		cout << "Please choose from the following" << endl;
		cout << "1) Change the value of fraction one" << endl;
		cout << "2) Change the value of fraction two" << endl;
		cout << "3) Print the values of the fractions" << endl;
		cout << "4) Verify fraction one is equal to fraction two" << endl;
		cout << "5) Add fraction one to fraction two to get a result" << endl;
		cout << "6) Quit" << endl;
		cout << "Choice --> ";
		cin >> choice;

	}// end while

	return choice;

}// end menu

int read_value(string s)
{
	int num;

	cout << "Please enter a new value for the " << s << " ";
	cin >> num;

	return num;

}// end read_value