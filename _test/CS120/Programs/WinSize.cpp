/*
 * Program Template
 *
 * Gabe Gibler
 * CS120-03
 * Assignment #XX
 * Lab #XX
 *
 */

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<time.h>
#include"CursWin.h"

using namespace std;

string const hr = "* * * * * * * * * *";

string getInput(char[],int)

int main()
{
	int iW=98, iH=7, iX=0, iY=0;
	int dW = 30, dH = 30, oX = 0, oY = iH;
	CursWin wInput(iY,iX,iH,iW);
	CursWin wDisp;
	string inConfig, inSize, inSizeFile, filename;
	int numResponses = 2;
	char responses[numResponses] = {'n','y'}; 
	srand(time(NULL));

	wInput << "Windows on Unix" << cendl;
	
	// Input a specified initial configuration?
	wInput << "Load configuration from file (.txt) (" << responses[1] << "/" << responses[0] << ")?" << cendl;
	inConfig = getInput(responses,numResponses);
	// Specify the field size (default is 30x30)?
	wInput << "Would you like to manually specify the window size (" << responses[1] << "/" << responses[0] << ")? ";
	inSize = getInput(responses,numResponses);
	if ((inSize == responses[0] && inConfig == responses[1]) {
		wInput << "Are the display sizes specified in the configuration file (" << responses[1] << "/" << responses[0] << ")? " << cendl <<  "(Must be on 1st line - width height)";
		inSizeFile = getInput(responses,numResponses);
	}
	// get a manual HxW if requested
	// if not, the defaults are used
	if (inSize == responses[1]) {
		wInput << "Display width: " >> dW;
		wInput << "Display height: " >> dH;
	}
	// if initial configuration is in a file, get filename
	// parse it for init values HxW, if appropriate
	if (inConfig == responses[1]) {
		ifstream infile;
		wInput << "What is the configuration file's filename (must be .txt)? " >> filename;
		infile.open(filename);
		
		infile >> dW >> dH;
		ignore(infile, '\n');
		while (!infile.eof()) {
			for (int i=0; i < dH; i++) {
				for (int j=0; j < dW; j++) {
						infile >> [i][j];
				}
				ignore(infile, '\n');
			}
			if([] < dW)
				
			if([] < dH)
				
		}
	}
	// if no, random configuration HxW
	else {
		
	}
	
	wDisp.PlaceWin(oY,oX,dH,dW);
	
	// Exit program
 	wInput << "Press enter to exit." << cendl;
	cin.ignore();
	return 0;
}

string getInput(char c[], int len) {
	string a;
	bool valid = 0;
	while (!valid) {
		wInput >> a;
		for (int i=0; i < len; i++) {
			if (a.length() == 1 && a[0] == c[i])
				valid = 1;
		}
		if (!valid)
			wInput << "Your response was not understood." << cendl;
	}
	return a;
}