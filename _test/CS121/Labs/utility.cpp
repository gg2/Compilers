#include"utility.h"

// Print a visual divider for textual output
void div(std::string hr) {
	std::cout << std::endl << hr << std::endl;
}

// Get textual confirmation from user
// Returns true if yes, false if no
bool confirm() {
	int c;
	bool initial = true;
	do {
		if (initial) {
			std::cout << " (y/n)?" << std::flush;
		} else {
			std::cout << "Please enter y or n to respond: " << std::flush;
		}
		do {
			c = std::cin.get();
		} while(c == '\n' || c == ' ' || c == '\t');
	} while(c != 'y' && c != 'Y' && c != 'n' && c != 'N');
	return (c == 'y' || c == 'Y');
}

std::string ToString(int i) {
	// using ostringstream since to_string doesn't work in g++ on this server
	std::ostringstream ss;
	ss << i;
	return ss.str();
}
std::string ToString(double d) {
	// using ostringstream since to_string doesn't work in g++ on this server
	std::ostringstream ss;
	ss.precision(DOUBLE_PRECISION);
	ss << d;
	return ss.str();
}
std::string ToString(char c) {
	// using ostringstream since to_string doesn't work in g++ on this server
	std::ostringstream ss;
	ss << c;
	return ss.str();
}
