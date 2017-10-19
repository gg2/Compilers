/*
 *
 * Gabe Gibler
 * CS120-03
 * Lab #5
 *
 * Calculation of 3D Shapes, Take 2
 *
 */

#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;

void calculateIt(double, double, string);

int main() {
	
	// Variable declarations
	string const divider = "**********";
	double r = 0;
	double h = 0;
	
	// Intro
	cout << endl << "3D Solids Calculations (Lab #2)" << endl;
	cout << endl;
	
	/*
	 * Calculate volume, surface area, ratio for a right circular cylinder
	 */
	cout << endl << divider << endl;
	cout << "Calculations for a right circular cylinder..." << endl;
	// Request radius, height
	cout << "Please provide the radius: ";
	cin >> r;
	cout << "Please provide the height: ";
	cin >> h;
	cin.ignore();
	
	calculateIt(r, h, "cylinder");
	
	/*
	 * Calculate volume, surface area, ratio for a right circular cone
	 */
	cout << endl << divider << endl;
	cout << "Calculations for a right circular cone..." << endl;
	// Request radius, height
	cout << "Please provide the radius: ";
	cin >> r;
	cout << "Please provide the height: ";
	cin >> h;
	cin.ignore();
	
	calculateIt(r, h, "cone");
	
	/*
	 * Calculate volume, surface area, ratio for a sphere
	 */
	cout << endl << divider << endl;
	cout << "Calculations for a sphere..." << endl;
	// Request radius
	cout << "Please provide the radius: ";
	cin >> r;
	cin.ignore();
	
	calculateIt(r, h, "sphere");
	
	// Prepare to exit the program
	cout << endl << divider << endl;
	cout << "Press enter to exit." << endl;
	cin.ignore();
	return 0;
}

void calculateIt(double& r, double& h, string shape) 
{
	double const PI = 3.14159;
	double V;
	double SA;
	double R;

	// Begin output of the results
	cout << endl << "Results for a ";

	// Perform the calculations
	if (shape == "cylinder") {
		/*
		V = πr^2h
		S = 2πr(r + h)
		*/
		V = (PI*pow(r, 2.0)*h);
		SA = (2.0*PI*r*(r + h));

		cout << "cylinder";

	} else if (shape == "cone") {
		/*
		V = 1/3πr2h
		S = πr(r + sqrt(r^2 + h^2))
		*/
		V = ((1.0/3.0)*PI*pow(r, 2.0)*h);
		SA = (PI*r*(r + sqrt(pow(r, 2.0) + pow(h, 2.0))));

		cout << "cone";
		
	} else if (shape == "sphere") {
		/*
		V = 4/3πr3
		S = 4πr^2
		*/
		V = ((4.0/3.0)*PI*pow(r, 3.0));
		SA = (4.0*PI*pow(r, 2.0));

		cout << "sphere";

	} else {
		V = 0;
		SA = 0;

		cout << "sphincter-says-what!?";

	}
	
	if (SA != 0) {
		R = V/SA;
	} else {
		R = 0;
	}
	
	// Finish output of the results
	cout << "..." << endl;
	
	cout << "Volume: " << V << endl;
	cout << "Surface Area: " << SA << endl;
	cout << "Ratio: " << R << endl;
}