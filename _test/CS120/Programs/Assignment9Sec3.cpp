/*
 * The Game of Life
 *
 * Gabe Gibler
 * CS120-03
 * Assignment #9
 * 
 * 1) Added option to initialize the world from a configuration file.
 * 2) Added an option to read the world size from the configuration file.
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
		char forms[3];
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
	const int iW=98, iH=5, iX=0, iY=0, ulr = iH, ulc = 0, cell_s_max = 3;
	int lrr = 30, lrc = 30, x, y;
	CursWin input(iY,iX,iH,iW);
	CursWin stage;
	string responses = "ny"; 
	string inConfig, inSize, inSizeFile;
	string FileName;
	double t = 1.0, generations = 0.0;
	srand(time(NULL));

	input << cmove << iY << iX << "Beginning the Game of Life..." << cendl;
	// Game options
	// Input a specified initial configuration?
	input << cnl << "Load configuration from file (.txt) (" << responses[1] << "/" << responses[0] << ")? " << cnl;
	input << "(If not, a random initial configuration will be used.) ";
	inConfig = getInput(input,responses);
	// If so, get filename
	if (inConfig[0] == responses[1]) {
		input << cnl << "What is the configuration file's filename (must be .txt)? " >> FileName;
	}
	// Specify the field size? (default is 30x30)
	input << cnl << "Would you like to manually specify the world size (" << responses[1] << "/" << responses[0] << ")? " << cnl;
	input << "(Default is 30 x 30.) ";
	inSize = getInput(input,responses);
	if (inSize[0] == responses[0] && inConfig[0] == responses[1]) {
		input << cnl << "Are the display sizes specified in the configuration file (" << responses[1] << "/" << responses[0] << ")? " << cnl;
		input <<  "(Must be on 1st line: width height) ";
		inSizeFile = getInput(input,responses);
	}
	// Get a manual HxW, if requested
	// Or parse the file for init values HxW, if appropriate
	// Otherwise, the defaults are used
	if (inSize[0] == responses[1]) {
		input << cnl << "Display width: ";
		input >> lrc;
		input << cnl << "Display height: ";
		input >> lrr;
	} else if (inSize[0] == responses[0] && inSizeFile[0] == responses[1]) {
		ifstream infile;
		infile.open(FileName.c_str());
		infile >> lrc >> lrr;		
		infile.close();
	}

	// Variable declarations[2, dimensioning arrays]
	cell cells[lrr][lrc];
	int cellGrowth[lrr][lrc];
	// Initialize cell properties
	// If initial configuration is in a file, get it from the file
	// Otherwise, random configuration
	if (inConfig[0] == responses[1]) {
		string garbage;
		ifstream infile;
		infile.open(FileName.c_str());
		
		if (inSize[0] == responses[0] && inSizeFile[0] == responses[1]) {
			getline(infile, garbage);
		}
		while (!infile.eof()) {
			for (y = 0; y < lrr; y++) {
				for (x = 0; x < lrc; x++) {
					infile >> cellGrowth[y][x];
				}
				getline(infile, garbage);
			}
		}
		infile.close();
	} else {
		for (y = 0; y < lrr; y++) {
			for (x = 0; x < lrc; x++) {
				//cellGrowth[y][x] = 0;
				cellGrowth[y][x] = (rand() % cell_s_max);
			}
		}
	}

	// Get the number of iterations to perform
	input << cnl << "How many generations would you like performed (0 for continuous)? " >> generations;
	
	input << cnl << "Begin..." << cendl;
	stage.PlaceWin(ulr,ulc,lrr+ulr+1,lrc+ulc+1);

	// Primary game iteration
	while(t <= generations || generations == 0) {
		// Draw out or update grid
		for (y = 0; y < lrr; y++) {
			for (x = 0; x < lrc; x++) {
				if (cellGrowth[y][x] > -1) {
					cells[y][x].setState(cellGrowth[y][x]);
					stage << cmove << y << x << cells[y][x].getForm();
				}
			}
		}
		stage << cflush;
		usleep(50000);
		// Process cell states
		for (y = 0; y < lrr; y++) {
			for (x = 0; x < lrc; x++) {
				// Get neighbor count
				int neighbors = 0;
				for (int j = -1; j < 2; j++) {
					int q = ((j + y + lrr) % lrr);
					for (int i = -1; i < 2; i++) {
						int p = ((i + x + lrc) % lrc);
						if (cells[q][p].getState() > 0 && !(i == 0 && j == 0))
							neighbors++;
					}
				}
				// Process cell states
				// 1. A living cell with fewer than two neighbors dies due to loneliness.
				// 2. A living cell with more than three neighbors dies due to overpopulation.
				// 3. A living cell with two or three neighbors lives to the next generation
				// 4. A cell is born if surrounded by exactly three living neighbors.	
				if (cells[y][x].getState() > 0) {
					if (neighbors < 2 || neighbors > 3)
						cellGrowth[y][x] = 0;
					else if (cells[y][x].getState() == 1)
						cellGrowth[y][x] = 2;	
				} else if (cells[y][x].getState() == 0 && neighbors == 3) {
					cellGrowth[y][x] = 1;
				} else {
					cellGrowth[y][x] = -1;
				}
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
	s_max = 3;
	setState(s_min);
	forms[s_min] = ' ';
	forms[s_min+1] = '+';
	forms[s_max-1] = '#';
}
cell::cell(int s) {
	s_min = 0;
	s_max = 3;
	setState(s);
	forms[s_min] = ' ';
	forms[s_min+1] = '+';
	forms[s_max-1] = '#';
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
