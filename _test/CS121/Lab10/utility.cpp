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
