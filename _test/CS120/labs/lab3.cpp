/*
 *
 * Gabe Gibler
 * CS120-03
 * Lab #3
 *
 */

#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

int main()
{
	string const hr = "* * * * * * * * * *";
	int n = 1;
	string leading_statement = "Question #";
	
	cout << endl << hr << endl;
	cout << "Boolean Outcomes" << endl;
	cout << endl << hr << endl;

 	cout << leading_statement << n << ": ";
 	cout << ((7 < 8) ? "TRUE" : "FALSE");
 	cout << endl << "7 < 8" << endl << endl;
 	n++;
	
 	cout << leading_statement << n << ": ";
 	cout << ((10 > 10) ? "TRUE" : "FALSE");
 	cout << endl << "10 > 10" << endl << endl;
 	n++;
	
 	cout << leading_statement << n << ": ";
 	cout << (((7 < 10) || (7 > 10)) ? "TRUE" : "FALSE");
 	cout << endl << "(7 < 10) || (7 > 10)" << endl << endl;
 	n++;
	
 	cout << leading_statement << n << ": ";
 	cout << (((7 < 10) && (7 > 10)) ? "TRUE" : "FALSE");
 	cout << endl << "(7 < 10) && (7 > 10)" << endl << endl;
 	n++;
	
 	cout << leading_statement << n << ": ";
 	cout << ((-5 >= 5) ? "TRUE" : "FALSE");
 	cout << endl << "-5 >= 5" << endl << endl;
 	n++;
	
 	cout << leading_statement << n << ": ";
 	cout << (((7 > 10) || (-5 == 5)) ? "TRUE" : "FALSE");
 	cout << endl << "(7 > 10) || (-5 == 5)" << endl << endl;
 	n++;
	
 	cout << leading_statement << n << ": ";
 	cout << ((!(6 == 7)) ? "TRUE" : "FALSE");
 	cout << endl << "!(6 == 7)" << endl << endl;
 	n++;
	
 	cout << leading_statement << n << ": ";
 	cout << (((10 != 11) && (7 > 8)) ? "TRUE" : "FALSE");
 	cout << endl << "(10 != 11) && (7 > 8)" << endl << endl;
 	n++;
	
 	cout << leading_statement << n << ": ";
 	cout << (((7 == 6) || (7 == 7) || (7 == 8)) ? "TRUE" : "FALSE");
 	cout << endl << "(7 == 6) || (7 == 7) || (7 == 8)" << endl << endl;
 	n++;
	
 	cout << leading_statement << n << ": ";
 	cout << ((6 < (8 && 9)) ? "TRUE" : "FALSE");
 	cout << endl << "(6 < (8 && 9))" << endl << endl;
 	n++;
	
 	cout << leading_statement << n << ": ";
 	cout << ((1 == (6 < 8)) ? "TRUE" : "FALSE");
 	cout << endl << "(1 == (6 < 8))" << endl << endl;
 	n++;
	
 	cout << leading_statement << n << ": ";
 	cout << ((0 == (0 || 1)) ? "TRUE" : "FALSE");
 	cout << endl << "(0 == (0 || 1))" << endl << endl;
 	n++;
	
 	cout << leading_statement << n << ": ";
 	cout << ((6 < (5 + 2)) ? "TRUE" : "FALSE");
 	cout << endl << "6 < (5 + 2)" << endl << endl;
 	n++;
	
 	cout << leading_statement << n << ": ";
 	cout << ((6 + (5 == 5)) ? "TRUE" : "FALSE");
 	cout << endl << "6 + (5 == 5)" << endl << endl;
 	n++;
	
 	cout << leading_statement << n << ": ";
 	cout << (((6 < 7) + (7 >= 5)) ? "TRUE" : "FALSE");
 	cout << endl << "(6 < 7) + (7 >= 5)" << endl << endl;
 	n++;
	
	// Exit program
	cout << endl << hr << endl;
 	cout << "Press enter to exit." << endl;
	cin.ignore();
	return 0;
}