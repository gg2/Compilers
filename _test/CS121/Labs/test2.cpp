 
#include"utility.h"
std::string hr = "* * * * * * * * * *";

int main()
{
	div(hr);
	std::cout << "Testing String Comparison" << std::endl;
	div(hr);

	std::string a = "bravo";
	std::string b = "alpha";
	
	std::cout << a << " < " << b << " == " << (a < b) << "\n" << std::endl;
	
	// Exit program
	div(hr);
	return 0;
}
