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
#include"CursWin.h"
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>

using namespace std;

string const hr = "* * * * * * * * * *";

string getInput(CursWin,string);

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
	const int iW=128, iH=5, iX=0, iY=0, ulr = iH, ulc = 0, cell_s_max = 2;
	int lrr = 1, lrc = 128, x, y=0;
	CursWin input(iY,iX,iH,iW);
	CursWin stage;
	string responses = "ny"; 
	string inConfig, inSize, inSizeFile;
	string FileName;
	double t = 1.0, generations = 0.0;
	srand(time(NULL));

	input << cmove << iY << iX << "One-dimensional Cellular Automata..." << cendl;
	// Game options
	// Input a specified initial configuration?
	input << cnl << "Load configuration from file (.txt) (" << responses[1] << "/" << responses[0] << ")? " << cnl;
	input << "(If not, a random initial configuration will be used.) ";
	inConfig = getInput(input,responses);
	// If so, get filename
	if (inConfig[0] == responses[1]) {
		input << cnl << "What is the configuration file's filename (must be .txt)? " >> FileName;
	}
	// Specify the number of cells? (default is 1x128)
	input << cnl << "Would you like to manually specify the number of cells (" << responses[1] << "/" << responses[0] << ")? " << cnl;
	input << "(Default is 128.) ";
	inSize = getInput(input,responses);
	if (inSize[0] == responses[0] && inConfig[0] == responses[1]) {
		input << cnl << "Is the number of cells specified in the configuration file (" << responses[1] << "/" << responses[0] << ")? " << cnl;
		input <<  "(Must be on 1st line, integer, max: 128) ";
		inSizeFile = getInput(input,responses);
	}
	// Get number of cells manually, if requested...
	if (inSize[0] == responses[1]) {
		input << cnl << "Number of cells: ";
		input >> lrc;
	}
	// Or parse the file for width, if appropriate...
	else if (inSize[0] == responses[0] && inSizeFile[0] == responses[1]) {
		ifstream infile;
		infile.open(FileName.c_str());
		infile >> lrc;		
		infile.close();
	}
	// Otherwise, the default is used

	// Array declarations for cellular automata: display and update states
	cell cells[lrc];
	int cellGrowth[lrc];
	// Initialize cell properties
	// If initial configuration is in a file, get it from the file...
	if (inConfig[0] == responses[1]) {
		string garbage;
		ifstream infile;
		infile.open(FileName.c_str());
		
		// If width was specified in file, skip and discard it
		if (inSize[0] == responses[0] && inSizeFile[0] == responses[1]) {
			getline(infile, garbage);
		}
		while (!infile.eof()) {
			for (x = 0; x < lrc; x++) {
				infile >> cellGrowth[x];
			}
			getline(infile, garbage);
		}
		infile.close();
	}
	// Otherwise, random configuration
	else {
		for (x = 0; x < lrc; x++) {
			cellGrowth[x] = (rand() % cell_s_max);
		}
	}

	// Get the number of iterations to perform
	input << cnl << "How many generations would you like performed (0 for continuous)? " >> generations;
	
	input << cnl << "Begin..." << cendl;
	stage.PlaceWin(ulr,ulc,lrr+ulr+1,lrc+ulc+1);

	// Primary program loop
	while(t <= generations || generations == 0) {
		// Draw out or update grid
		for (x = 0; x < lrc; x++) {
			cells[x].setState(cellGrowth[x]);
			stage << cmove << y << x << cells[x].getForm();
		}
		stage << cflush;
		usleep(50000);
		// Process cell states
		// 1. A living cell dies
		// 2. A dead cell comes to life if and only if its left side touches a live cell.
		// 3. A dead cell comes to life if and only if its right side touches a live cell.
		for (x = 0; x < lrc; x++) {
			cellGrowth[x] = 0;
			// Get neighbor count; skip cell for whom neighbors are being assessed
			int neighbors = 0;
			for (int i = -1; i < 2; i+2) {
				int c = ((i + x + lrc) % lrc);
				if (cells[c].getState() > 0)
					neighbors++;
			}
			if (neighbors == 2) {
				cellGrowth[x] = 1;
			}
		}
		t = t + 1.0;
	}
	
	// Exit program
	input >> generations;
	input.ClearWin();
	stage.ClearWin();
	return 0;
}

// cell class definitions
// Unfortunately, s_min and s_max can only easily be set in the constructors, and not in the class declaration
// So, the size of forms[] must likewise be managed manually in the declaration
cell::cell() {
	s_min = 0;
	s_max = 1;
	setState(s_min);
	forms[s_min] = ' ';
	forms[s_max] = '+';
}
cell::cell(int s) {
	s_min = 0;
	s_max = 1;
	setState(s);
	forms[s_min] = ' ';
	forms[s_max] = '+';
}
// Get and set cell status
int cell::getState() {
	return state;
}
int cell::setState(int s) {
	if (s >= s_min && s < s_max) {
		state = s;
	} else {
		//cerr << "Invalid value for state property using method setState in class 'cell'. Attempt to set state == " << s << endl;
		state = -1;
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

string getInput(CursWin window, string c) {
	string a;
	bool valid = 0;
	while (!valid) {
		window >> a;
		if (a.length() == 1) {
			for (int i=0; i < c.length(); i++) {
				if (a[0] == c[i])
					valid = 1;
			}
		}
		if (!valid)
			window << "Your response was not understood. ";
	}
	return a;
}
