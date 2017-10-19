#include<iostream>
#include<limits>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cstddef>
#include<fstream>
#include<cctype>
#include<ctime>

enum error {success, fail, range_error, underflow, overflow, fatal, internal_error, not_present, duplicate_error, entry_inserted, entry_found};

void div(std::string);
bool confirm();
