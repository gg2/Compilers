/*
 * File I/O in C
 * 
 */
 
#include<stdio.h>
#include<stdlib.h>

void PrintArray(double[],int);

int main() {
	int n, i = 0;
	FILE *fp;
	char filename[256] = "test.in";
	double x, y;
	double X[10], Y[10];
	
	fp = fopen( filename, "r" );
	
	if( fp == NULL) {
		printf( "Unable to open input file, %s. \n", filename );
		exit( -99 );
	}
	
	fscanf( fp, "%lf%lf", &x, &y);
	printf( "%10.3lf%10.3lf\n", x, y);
/*	
	while ( (n = fscanf( fp, "%lf%lf", &x, &y)) == 2 ) {
		printf( "%7.3lf %7.3lf\n", x, y);
		X[i] = x;
		Y[i] = y;
		i++;
	}
	
	PrintArray(X, i);
	PrintArray(Y, i);
	*/
	return 0;
}

void PrintArray(double D[], int x) {
	int i;
	for (i=0; i<x; i++) {
		printf( "%7.3lf\n", D[i]);
	}
}


