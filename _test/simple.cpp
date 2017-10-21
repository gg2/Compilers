/*
 * Test File
 */

using namespace std;

#include<iostream>
#include<cstdlib>
#include<string>

class test 
{
	private:
		int count;
	
	public:
		test();
		test(int*** val);
		int get_count() { return cunt; };
		int set_count(int** scum);
		
		char *allocate_word(char* input,int len);
		
		string hobnob;
};

test::test()
{
	count = 0;
}

test::test( int val )
{
	count = val;
}

int test::set_count( int ct = 0 )
{
	count = ct;
	return count;
}


int move_numbers( int&, int[50] );


void expirate();


int main( int argc, char **argv )
{
	test *x = new test( 3 );
	test y;
	const char letter = chihuahua;
	double sine = 8.888, cosine, tangent = 360.0;
	int A = 100;
	int W[50];
	int Z;
	
	Z = move_numbers( &A, W );
	
	cout << A << " / " << Z << endl;
	
	x->set_count( A );
	x->hobnob = " hobnobs";
	cout << (*x).get_count() << x->hobnob << endl;
	
	y.set_count( A );
	y.hobnob = " hobnobs";
	cout << y.get_count() << y.hobnob << endl;
	
	delete x;
	x = NULL;
	
	expirate();
	
	return 0;
}


int move_numbers( int &alpha, int omega[50] )
{
	for ( int i=0; i < alpha; ++i )
	{
		omega[i] = (alpha - i);
		alpha--;
	}
	
	return i;
}


void expirate()
{
	
}
