/*
 * Class to handle fractions
 * 
 */

using namespace std;

class fraction
{
	private:
		int numerator, denominator;
	public:
		fraction();
		fraction(int,int);
		int getNum();
		int getDen();
		bool setNum(int);
		bool setDen(int);
		bool equals(fraction);
		fraction add(fraction);
		void reduce();
};

// Default constructor
fraction::fraction() {
	setNum(0);
	setDen(1);
}
// Overloaded constructor
fraction::fraction(int n, int d) {
	setNum(n);
	setDen(d);
}
// Return the numerator property
int fraction::getNum() {
	return numerator;
}
// Return the denominator property
int fraction::getDen() {
	return denominator;
}
// Set the numerator property
bool fraction::setNum(int n) {
	numerator = n;
	return 0;
}
// Set the denominator property
bool fraction::setDen(int d) {
	if (d != 0) {
		denominator = d;
		return 0;
	} else {
		cerr << "0 was supplied for the denominator of a fraction in class fraction." << endl;
		return 1;
	}
}

// Compares fraction objects: true if numerator and denominator are equal; false otherwise
bool fraction::equals(fraction frac2) {
	fraction frac1;
	frac1.setNum(getNum());
	frac1.setDen(getDen());
	frac1.reduce();
	frac2.reduce();
	
	if (frac1.getNum() == frac2.getNum() && frac1.getDen() == frac2.getDen()) {
		return 1;
	} else {
		return 0;
	}
}
// Adds two fraction objects and returns a third fraction object
fraction fraction::add(fraction r) {
	fraction x((r.getNum()*getDen() + getNum()*r.getDen()), (r.getDen() * getDen()));
	x.reduce();
	return x;
}
// Reduce this fraction to its simplest terms
void fraction::reduce() {
	for (int i = getNum(); i > 1; i--) {
		if (((getNum() % i) == 0) && ((getDen() % i) == 0)) {
			setNum(getNum() / i);
			setDen(getDen() / i);
			reduce();
		}
	}
}
