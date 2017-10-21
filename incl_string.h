/*
 * include_string.h - Faux system header for <string>.
 *
 * Copyright (C) 2014 Andrew Schwartzmeyer
 *
 * This file released under the AGPLv3 license.
 * Retrieved from GitHub: https://github.com/andschwa/partial-cpp-compiler
 */

#include <string.h>

class string {
public:
	string(char *);
	char *c_str();
private:
	char *data;
};

string::string(char *s)
{
	data = strdup(s);
}

char *string::c_str()
{
	return data;
}