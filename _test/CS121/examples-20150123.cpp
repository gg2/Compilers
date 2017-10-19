// C/C++

#include<iostream>
#include<cstdlib>

using namespace std;

struct fraction {
	int numer;
	int denom;
};

typedef struct fraction Fraction;

void SetFraction( Fraction &F, int n, int d );
void PrintFraction( Fraction F);

int main() 
{
	Fraction f;
	
	f.numer = 1;
	f.denom = 2;
	cout << "One half: ";
	PrintFraction(f);
	cout << endl;
	
	SetFraction( f, 1, 3);
	cout << "One third: ";
	PrintFraction(f);
	cout << endl;
	
	return 0;
}

/* SetFraction: initializes a fraction */
void SetFraction( Fraction &F, int n, int d ) {
	F.numer = n;
	F.denom = d;
}

/* PrintFraction: outputs a fraction */
void PrintFraction( Fraction F ) {
	cout << F.numer << " / " << F.denom;
}

/* ------------------------------------- */

// Swift
/* 
 * fraction.swift
 * Create fractions using structs in Swift.
 * Bruce Bolden
 * January 22, 2015
 */
 
struct Fraction
{
	var numer : Int = 0
	var denom : Int = 1
	
	func description() -> String {
		return "\(numer) / \(denom)"
	}
}

func printFraction( f : Fraction)
{
	println( "\(f.numer) / \(f.denom)" )
}

var oneHalf = Fraction()

// If func description() present in struct Fraction
println( "oneHalf (initially): " + oneHalf.description() )

oneHalf.numer = 1
oneHalf.denom = 2

printFraction( oneHalf )
// If func description() present in struct Fraction
print( "oneHalf (description): " )
println( oneHalf.description() )

print( "oneHalf (printFraction): " )
printFraction( oneHalf )
