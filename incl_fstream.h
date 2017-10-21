/*
 * include_fstream.h - Faux system header for <fstream>.
 *
 * Copyright (C) 2014 Andrew Schwartzmeyer
 *
 * This file released under the AGPLv3 license.
 * Retrieved from GitHub: https://github.com/andschwa/partial-cpp-compiler
 */

class ifstream {
public:
	bool is_open();
	void open(char *);
	void close();
	void ignore();
	bool eof();
};

class ofstream {
public:
	bool is_open();
	void open(char *);
	void close();
	bool eof();
};