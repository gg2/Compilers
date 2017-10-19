/* 
 * Gabe Gibler
 * CS121 Sec 03
 * Lab #6
 * Statistics 
 * 2015/02/26
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void ShowHeader(FILE*);
void GetFilenames(int, char**, char*, char*);
double StatsMin(double*,int);
double StatsMax(double*,int);
double StatsMean(double*,int);
double StatsStdDeviation(double*,int);

int main(int argc, char** argv)
{
	const int MAX_FILENAME = 128;
	char inputfilename[MAX_FILENAME];
	char outputfilename[MAX_FILENAME];
	FILE* inputfile;
	FILE* outputfile;
	const int MAX_INPUT = 100;
	double input[MAX_INPUT];
	double in;
	int inputcount = 0;
	int i = 0;
	
	// Get filenames
	GetFilenames(argc, argv, inputfilename, outputfilename);
	// Confirm filenames
	if (!inputfilename)
		printf("! Input filename is not readable.\n");
	else
		printf("Input filename: %s\n", inputfilename);
	if (!outputfilename)
		printf("! Output filename is not readable.\n");
	else
		printf("Output filename: %s\n", outputfilename);
	printf("\n");
	
	outputfile = fopen(outputfilename, "w");
	if (outputfile == 0) {
		printf("Could not open output file.\n");
	} else {
		ShowHeader(outputfile);

		inputfile = fopen(inputfilename, "r");
		if (inputfile == 0) {
			printf("Could not open input file.\n");
		} else {
			// Get values in input file and assign to array
			while( fscanf(inputfile, "%lf", &in) != EOF ) { // reading from file
				printf("%d: %lf\n", inputcount, in);
				input[inputcount] = in;
				printf("%d: %lf\n", inputcount, input[inputcount]);
				inputcount++;
			}

			// Minimum
			fprintf(outputfile, "Minimum: %lf\n", StatsMin( input, inputcount ) );
			// Maximum
			fprintf(outputfile, "Maximum: %lf\n", StatsMax( input, inputcount ) );
			// Average (mean)
			fprintf(outputfile, "Average (mean): %lf\n", StatsMean( input, inputcount ) );
			// Standard deviation
			fprintf(outputfile, "Standard deviation): %lf\n", StatsStdDeviation( input, inputcount ) );
			
			// Write input data to file for verification purposes
			fprintf(outputfile, "Input data:\n- - - - - - -\n");
			for (i = 0; i < inputcount; i++) {
				fprintf(outputfile, "%lf\n", input[i]);
			}
			fprintf(outputfile, "\n\n");
			
			fclose(inputfile);
		}
		
		fclose(outputfile);
	}
	
	printf("\nResults printed to file, %s\n- - - - - - - -\n", outputfilename);
	return 0;
}

// Get filenames
// ! Assuming properly formatted input for each supplied parameter !
// Check command line arguments for filenames;
// If more than program name supplied, 2nd is input file
// Accepts: argc and argv supplied to main, 
//          references for storing input and output filenames
// Result: input and output filenames should be filled,
//         or reasons for errors written to screen
void GetFilenames(int c, char** args, char* in, char* out) {
	if (c > 1) {
		strcpy( in, args[1] );
	} else {
		printf("Please provide the name of the input file: ");
		scanf("%127s", in);
	}
	// If exactly 3 arguments provided, 3rd is output file
	if (c == 3) {
		strcpy( out, args[2] );
	} else {
		printf("Please provide the name of the output file: ");
		scanf("%127s", out);
	}
}

// For writing the standard header to the output file
// Accepts: output file to write to
// Result: writes header to parameter
void ShowHeader(FILE* outputfile) {
	const char* header = "Lab06-Header.txt";

	FILE* headerfile = fopen(header, "r");
	if (headerfile == 0) {
		printf("Header not found.\n\n");
	} else {
		int c;
		while ( (c = fgetc(headerfile)) != EOF ) {
			fprintf(outputfile, "%c", c);
		}
		fclose(headerfile);
	}
}

// Find the minimum
double StatsMin(double *d, int c) {
	double least = d[0];
	int i = 1;
	while (i<c) {
		if (d[i] < least)
			least = d[i];
		i++;
	}
	return least;
}

// Find the maximum
double StatsMax(double *d, int c) {
	double most = d[0];
	int i = 1;
	while (i<c) {
		if (d[i] > most)
			most = d[i];
		i++;
	}
	return most;
}

// Calculate the mean
double StatsMean(double *d, int c) {
	double avg = 0;
	int i = 0;
	while (i<c) {
		avg += d[i];
		i++;
	}
	// Ensure no div/0
	if (c > 0)
		avg = avg / c;
	else
		avg = 0;
	
	return avg;
}

// Calculate the standard deviation
// (1/n * (sum(x[i]^2, i=1; i<=n))) - (1/n^2 * (sum(x[i], i=1; i<=n)^2))
double StatsStdDeviation(double *d, int c) {
	double avg = StatsMean(d, c);
	
	double sum1 = 0;
	int i = 0;
	while (i<c) {
		sum1 += (d[i]-avg) * (d[i]-avg);
		i++;
	}

	return sqrt(sum1/(i-1));
}

