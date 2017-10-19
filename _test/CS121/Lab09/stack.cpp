/* 
 * stack_interface.cpp
 *
 * CS 121 Sec 03 - Bolden
 * Gabe Gibler
 * 2015 Apr 2
 * gibl3465@vandals.uidaho.edu
 *
 * Stack interface
 *---------------------------------------------------------------------
 */
 
#include"stack.h"
 
Stack::Stack() {
	head = NULL;
	count = 0;
}
Stack::~Stack() {
	Node* n = head;
	
	while (n != NULL) {
		head = n->next;
		n->next = NULL;
		delete n;
		n = head;
	}
}

int Stack::size() {
	return count;
}

void Stack::push(stack_data d) {
	Node* n = new Node;
	n->data = d;
	if (head == NULL) {
		n->next = NULL;
	} else {
		n->next = head;
	}
	head = n;
	count++;
}

stack_data Stack::pop() {
	stack_data d = DATA_DEFAULT;
	
	if (head != NULL) {
		Node* n = head;
		head = n->next;
		d = n->data;
		n->next = NULL;
		delete n;
		count--;
	}
	return d;
}

stack_data Stack::top() {
	stack_data d = DATA_DEFAULT;
	
	if (head != NULL) {
		d = head->data;
	}
	return d;
}

void Stack::print() {
	if (head == NULL) {
		std::cout << "The stack is empty.";
	} else {
		Node* n = head;
		
		while (n != NULL) {
			std::cout << n->data << " ";
			n = n->next;
		}
	}
}
