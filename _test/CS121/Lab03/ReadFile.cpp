#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>

using namespace std;

int main() {
	std::string Filename;
	std::string tmp, a;
	int i=0, col_i, col_ct = 128;
	int cellGrowth[col_ct];
	
	cout << "\nFile Input\n" << endl;
	
	cout << "What is the filename? ";
	cin >> Filename;
	
	cout << "\nFile name provided: " << Filename << endl;
	
		ifstream infile;
		infile.open(Filename.c_str());
		getline(infile,tmp);
		i++;
		cout << "\nRead " << i << ": " << tmp << endl;
		cout << "tmp.size == " << tmp.size() << endl;
		for (col_i = 0; col_i < col_ct; col_i++) {
			a = tmp[col_i];
			cout << "a.c_str(): " << a.c_str() << ";   ";
			cellGrowth[col_i] = atoi(a.c_str());
			cout << col_i << ": " << cellGrowth[col_i] << "\n";
		}
		cout << "col_i: " << col_i << endl;
		infile.close();
		
		cout << flush;

	cout << "Press enter to quit..." << endl;
	cin.ignore();
	return 0;
}