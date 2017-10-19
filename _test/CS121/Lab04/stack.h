/*
 * Stack data type
 * Utilizes a Linked List to store and access data
 * Dependencies: <string>
 * 
 */
#include<string>

#include"linkedlist.h"

class Stack {
	private:
		linkedlist List;
	
	public:
		Stack();
		
		void push(double); // add an item to the stack
		// Check list count before calling pop().
		double pop(); // retrieve and delete top item from the stack
		// Watch out for the 0 that may mean the list was empty. 
		// Check list count before calling top().
		double top(); // return value of last item added to stack; will return 0 if stack is empty
		std::string print(); // return listing of values of each item in stack
		int count(); // return number of items in stack
};