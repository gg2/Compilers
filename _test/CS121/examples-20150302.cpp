// Handle up to base 16; lookup table beyond base 10
void PrintBinary( int n, int base ) {
	if ( n < base ) {
		if ( n < 10 )
			cout << n;
		else
			cout << lookup[n - base];
	} else {
		PrintBinary( n/base );
		if ( (n % base) < 10 )
			cout << n % base;
		else
			cout << 
	}
}