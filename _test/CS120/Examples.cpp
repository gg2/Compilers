/*
 * Straightening Out Some C++ Issues
 *
 * Gabe Gibler
 * CS120-03
 *
 */

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<time.h>

using namespace std;

string const hr = "* * * * * * * * * *";

void div();

struct collection {
	private:
		int priv1;
		int priv2;
	public:
		collection();
		int pub1;
		int pub2;
};


int main()
{
	srand(time(NULL));

	div();
	cout << "C++ Experiments" << endl;
	div();
	
//	cout << endl << "Integer division (1/2): " << 9/10 << endl;
//	cout << "Processes right to left? or left to right? ";
//	int t = 4.0/2*4;
//	cout << (t<1 ? "RTL" : "LTR") << " " << t << endl;
	
//	collection stuff;
//	cout << stuff.pub1 << " " << stuff.pub2 << endl;
	
	cout << endl << "C-style strings: " << endl;

	char cstr[257] = "";
	char *pstr = cstr;	
	for (int i=0; i<95; i++) {
		cstr[i] = i+33;
	}
	for (int i=0; (pstr[i] != 0); i++) {
		cout << pstr[i];
		cout << " ";
		for (int j=7; j>-1; j--) {
			if (pstr[i] & pow(2,i))
				cout << 1;
			else
				cout << 0;
		}
		cout << " ";
	}
	cout << endl;
	
	// Exit program
	div();
 	cout << "Press enter to exit." << endl;
	cin.ignore();
	return 0;
}

collection::collection() {
	priv1 = 1;
	priv2 = 2;
	pub1 = priv1;
	pub2 = priv2;
}

// Print a visual divider for textual output
void div() {
	cout << endl << hr << endl;
}