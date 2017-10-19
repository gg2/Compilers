/*
 * Test File
 */

#include <iostream>


int move_numbers( int&, int[50] );


void expirate();


int main( int argc, char **argv )
{
	int A = 100;
	int W[50];
	int Z;
	
	Z = move_numbers( A, W );
	
	std::cout << A << " / " << Z << std::endl;
	
	expirate();
	
	return 0;
}


int move_numbers( int &alpha, int omega[50] )
{
	int i = 0;
	
	for ( i=0; i < alpha; ++i )
	{
		omega[i] = (alpha - i);
		alpha--;
	}
	
	return i;
}


void expirate()
{
	
}
