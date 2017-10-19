#include<iostream>

using namespace std;

void int_in(int&);
void swap(int&,int&);

int main() {
	int x = 1;
	int y = 2;
	
	int_in(x);
	int_in(y);
	cout << "x == " << x << "; y == " << y << endl;
	cout << "addr(x) == " << &x << "; addr(y) == " << &y << endl;
	
	cout << "Now switch them." << endl;	
	swap(x,y);

	cout << "x == " << x << "; y == " << y << endl;
	return 0;
}

void int_in(int &x) {
	cout << "Please enter a number (int): ";
	cin >> x;
	cin.ignore();
	cout << endl;
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}