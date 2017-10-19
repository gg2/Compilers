#include<iostream>

using namespace std;

void Swap(int*,int*);

int main() {
	
	int x=5, y=2;
	
	cout << endl << "&x == " << &x << "; &y == " << &y << "; " << endl;
	cout << endl << "x == " << x << "; y == " << y << "; " << endl;
	Swap(&x,&y);
	cout << endl << "x == " << x << "; y == " << y << "; " << endl;
	
	return 0;
}

void Swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}