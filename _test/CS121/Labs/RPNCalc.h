/*
 * Reverse Polish Notation (RPN) Calculator Class
 * Utilizes a stack to perform mathematical calculations
 * Dependencies: <iostream>, <cstdlib>, <string>, <cmath>
 * 
 */
#include<iostream>
#include<cstdlib>
#include<string>
#include<sstream>
#include<cmath>

#include"stack.h"

class RPNCalc {
	private:
		Stack stack;
		int DOUBLE_PRECISION;
		std::string ERR_INSUFFICIENT;
		std::string MSG_EMPTY;
	
	public:
		RPNCalc();
		
		void store(double);
		
		void add();
		void subtract();
		void multiply();
		void divide();
		void sq();
		void sqrt();
		
		void dup();
		void swap();
		
		std::string ps(); // "Print Stack"
		std::string result(); // Print top item of stack
};