/* 
 * stack_interface.h
 *
 * CS 121 Sec 03 - Bolden
 * Gabe Gibler
 * 2015 Apr 2
 * gibl3465@vandals.uidaho.edu
 *
 * Stack interface
 *---------------------------------------------------------------------
 */

#ifndef STACK_H
#define STACK_H

#include<cstdlib>
#include<iostream>

typedef int stack_data;
stack_data DATA_DEFAULT = '\0';

class Stack {
	private:
		struct Node {
			stack_data data;
			Node* next;
		};
		Node* head;
		int count;

	public:
		Stack();
		~Stack();
		
		int size();
		void push(stack_data);
		stack_data pop();
		stack_data top();
		void print();
};

#endif
