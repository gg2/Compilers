#include<iostream>
#include<cstdlib>

int main() {
	char* a;
	
	std::cout << "\n\n";
	std::cout << &a << "\n";
	std::cout << a[0] << a[1] << a[2] << a[3] << "\n";
/*
	a = "a";
	std::cout << a;
	a++;
	a = "b";
	std::cout << a;
	a++;
	a = "c";
	std::cout << a;
	std::cout << "\n a[3] == '\0' ? " << (a[3] == '\0');
*/	
	std::cout << "\n" << std::endl;
	
	return 0;
}