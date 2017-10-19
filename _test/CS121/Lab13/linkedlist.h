/*
 * Linked List
 * Dependencies: <cstdlib> (NULL), <string>, <sstream>
 * 
 */

#ifndef LIST_H
#define LIST_H

#include<cstdlib>
#include<string>
#include<sstream>

typedef int link_data;

class linkedlist {
	private:
		struct Node {
			link_data data;
			Node* next;
		};
		Node* head;
		int count;
		
	public:
		linkedlist();

		int size();
		void add(link_data); // Inserts a new node at the head of the list, to which head will then point
		int remove(link_data); // Removes the most recent node of the supplied value; Returns number of nodes removed
		link_data last(); // Returns the value of the most recently added node, pointed to by head; if count == 0, returns 0
		std::string print(); // Returns a string containing the value of each node, separated by spaces
};

#endif