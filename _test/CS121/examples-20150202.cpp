struct circle {
	double radius;
};
typedef struct circle Circle;

struct square {
	
};
typedef struct square Square;

struct rectangle {
	
};
typedef struct rectangle Rectangle;

// Methods to utilize struct, outside of struct
void SetRadius( Circle &c, double r);
void ShowRadius( Circle c );

void SetRadius( Circle &c, double r ) {
	if (r >= 0)
		c.radius = r;
	else
		c.radius = r;
}
void ShowRadius( Circle c ) {
	cout << c.radius << endl;
}

/* As a class */
#include<iostream>

using namespace std;

class Circle {
	public: 
		// constructors
		Circle();
		Circle(double r);
		
		void SetRadius( double r);
		double GetRadius();
		void ShowRadius();

	private:
		
};

/* 
	Circle Class Implementation, circle.cpp
	
	Bruce M. Bolden; May 4, 1998
 */

#include "circle.h"

Circle::Circle() {
	radius = 1.0;
}

Circle::Circle( double r ) {
	radius = r;
}

void Circle::SetRadius( double r ) {
	radius = r;
}

double Circle::GetRadius() {
	return radius;
}

void Circle::ShowRadius() {
	cout << radius << endl;
}

/* 
	TestCircle.cpp
	
	Bruce M. Bolden; May 4, 1998
 */

#include<iostream>

using namespace std;

#include "circle.h"

int main() {
	Circle c1;
	Circle c2(3.0);

	cout << "The radius of c1 is: " << c1.ShowRadius();
	cout << "The radius of c1 is: " << c2.ShowRadius();
	
	c1.SetRadius( 2.1 );
	cout << "The radius of c1 is: " << c1.ShowRadius();
	
	return EXIT_SUCCESS; // EXIT_SUCCESS == 0 / EXIT_FAILURE == 1
}