/*
 *
 * Gabe Gibler
 * CS121-03
 * One-dimensional Cellular Automata
 * 02/04/2015
 * 
 * 
 */

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>

using namespace std;

string const hr = "* * * * * * * * * *";

string getInput(string);

// Class to handle cell properties 
class cell {
	private:
		int s_min;
		int s_max;
		int state;
		char forms[2];
	public:
		cell();
		cell(int);
		int getState();
		int setState(int);
		char getForm();
		void setForms(char[]);
};

int main()
{
	// Variable declarations[1]
	const int col_ct_max = 128, cell_s_max = 2;
	int col_ct = col_ct_max, col_i;
	string responses = "ny"; 
	string inConfig, inSize, inSizeFile;
	string FileName;
	double t = 1.0, generations = 0.0;
	srand(time(NULL));

	cout << "\nOne-dimensional Cellular Automata...\n" << endl;
	// Game options
	// Input a specified initial configuration?
	cout << "Load configuration from file (.txt) (" << responses[1] << "/" << responses[0] << ")? \n";
	cout << "(If not, a random initial configuration will be used.) ";
	inConfig = getInput(responses);
	// If so, get filename
	if (inConfig[0] == responses[1]) {
		cout << "\nWhat is the configuration file's filename (must be .txt)? ";
		cin >> FileName;
		cout << "\nFilename provided: " << FileName << "\n" << endl;
	}
	// Specify the number of cells? (default is 1x128)
	cout << "\nWould you like to manually specify the number of cells (" << responses[1] << "/" << responses[0] << ")? \n";
	cout << "(Default is 128.) ";
	inSize = getInput(responses);
	if (inSize[0] == responses[0] && inConfig[0] == responses[1]) {
		cout << "\nIs the number of cells specified in the configuration file (" << responses[1] << "/" << responses[0] << ")? \n";
		cout << "(Must be on 1st line; integer, max: 128) ";
		inSizeFile = getInput(responses);
	}
	// Get number of cells manually, if requested...
	if (inSize[0] == responses[1]) {
		cout << "\nNumber of cells: ";
		cin >> col_ct;
	}
	// Or parse the file for width, if appropriate...
	else if (inSize[0] == responses[0] && inSizeFile[0] == responses[1]) {
		string tmp;
		ifstream infile;
		infile.open(FileName.c_str());
		getline(infile,tmp);
		col_ct = atoi(tmp.c_str());
		infile.close();
	}
	// Otherwise, the default is used

	// Quick check on the specified dimension
	if (col_ct > col_ct_max)
		col_ct = col_ct_max;
	if (col_ct < 1)
		col_ct = 1;
	cout << "Number of cells == " << col_ct << endl;

	// Array declarations for cellular automata: display and update states
	cell cells[col_ct];
	int cellGrowth[col_ct];
	// Initialize cell properties
	// If initial configuration is in a file, get it from the file...
	if (inConfig[0] == responses[1]) {
		string tmp, a;
		ifstream infile;
		infile.open(FileName.c_str());
		// If width was specified in file, skip and discard it
		if (inSize[0] == responses[0] && inSizeFile[0] == responses[1]) {
			getline(infile, tmp);
		}
		getline(infile, tmp);
		for (col_i = 0; col_i < col_ct; col_i++) {
			a = tmp[col_i];
			cellGrowth[col_i] = atoi(a.c_str());
		}
		infile.close();
	}
	// Otherwise, random configuration
	else {
		for (col_i = 0; col_i < col_ct; col_i++) {
			cellGrowth[col_i] = (rand() % cell_s_max);
		}
	}

	// Get the number of iterations to perform
	cout << "\nHow many generations would you like performed (0 for continuous)? ";
	cin >> generations;
	cin.ignore();
	
	cout << "\nBegin...\n" << hr << "\n\n" << endl;

	// Primary program loop
	while(t <= generations || generations == 0) {
		// Draw out or update grid
		for (col_i = 0; col_i < col_ct; col_i++) {
			if (cellGrowth[col_i] > -1) { // Only update if there is a change
				cells[col_i].setState(cellGrowth[col_i]);
			}
			cout << cells[col_i].getForm();
		}
/*
		cout << "\n";
		for (int j=0; j<col_ct; j++) { // DELETE ME
			cout << (j+1)%10;
		}
*/
		cout << "\n" << endl;
		// Process cell states
		// 1. A living cell dies
		// 2. A dead cell comes to life if and only if its left side touches a live cell.
		// 3. A dead cell comes to life if and only if its right side touches a live cell.
		for (col_i = 0; col_i < col_ct; col_i++) {
			// If already dead, mark unchanged.
			if (cellGrowth[col_i] == 0)
				cellGrowth[col_i] = -1;
			// If alive, kill it.
			if (cellGrowth[col_i] == 1)
				cellGrowth[col_i] = 0;
			// Get neighbor count; skip cell for whom neighbors are being assessed
			int neighbors = 0;
			for (int i = -1; i < 2; i=i+2) {
				int c = ((i + col_i + col_ct) % col_ct);
				if (cells[c].getState() > 0)
					neighbors++;
			}
			if (neighbors == 2) {
				cellGrowth[col_i] = 1;
			}
		}
		t = t + 1.0;
	}
	
	// Exit program
	cout << "Press enter to quit..." << endl;
	cin.ignore();
	
	return 0;
}

// cell class definitions
// Unfortunately, s_min and s_max can only easily be set in the constructors, and not in the class declaration
// So, the size of forms[] must likewise be managed manually in the declaration
cell::cell() {
	s_min = 0;
	s_max = 2;
	setState(s_min);
	forms[s_min] = ' ';
	forms[s_max-1] = '+';
}
cell::cell(int s) {
	s_min = 0;
	s_max = 2;
	setState(s);
	forms[s_min] = ' ';
	forms[s_max-1] = '+';
}
// Get and set cell status
int cell::getState() {
	return state;
}
int cell::setState(int s) {
	if (s >= s_min && s < s_max) {
		state = s;
	} else {
		cerr << "Invalid value for state property using method setState in class 'cell'. Attempt to set state == " << s << endl;
	}
	return state;
}
// Get and set char representing cell status
char cell::getForm() {
	return forms[state];
}
void cell::setForms(char newForms[]) {
	for (int i=s_min; i < s_max; i++) {
		forms[i] = newForms[i];
	}
}

string getInput(string c) {
	string a;
	bool valid = 0;
	while (!valid) {
		cin >> a;
		if (a.length() == 1) {
			for (int i=0; i < c.length(); i++) {
				if (a[0] == c[i])
					valid = 1;
			}
		}
		if (!valid)
			cout << "Your response was not understood. ";
	}
	cin.ignore();
	return a;
}
