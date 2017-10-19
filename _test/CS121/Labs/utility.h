#include<iostream>
#include<limits>
#include<cstdlib>
#include<cstddef>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<cctype>
#include<cmath>
#include<ctime>

enum error {success, fail, range_error, underflow, overflow, fatal, internal_error, not_present, duplicate_error, entry_inserted, entry_found};

int const DOUBLE_PRECISION = 16;

void div(std::string);
bool confirm();
std::string ToString(int);
std::string ToString(double);
std::string ToString(char);
