/*
 * Linked List
 * Dependencies: <cstdlib> (NULL), <string>, <sstream>
 * 
 */
#include<cstdlib>
#include<string>
#include<sstream>

#include"node.h"

class linkedlist {
	private:
		node *head;
		int count;
		int DOUBLE_PRECISION;
		
	public:
		linkedlist();

		int getCount();
		void insert(double); // Inserts a new node at the head of the list, to which head will then point
		int remove(double); // Removes the most recent node of the supplied value; Returns number of nodes removed
		double getLast(); // Returns the value of the most recently added node, pointed to by head; if count == 0, returns 0
		std::string getList(); // Accepts a string by reference and appends the value of each node to it, separated by spaces
};