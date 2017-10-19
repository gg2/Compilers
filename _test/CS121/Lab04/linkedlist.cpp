#include"linkedlist.h"

linkedlist::linkedlist() {
	head = NULL;
	count = 0;
	DOUBLE_PRECISION = 16;
}

int linkedlist::getCount() {
	return count;
}

void linkedlist::insert(double d) {
	node *n = new node();
	n -> data = d;
	n -> next = head;
	head = n;
	count++;
}

int linkedlist::remove(double d) {
	int x = count;
	if (head != NULL) {
		node *curr = head, *prev = head;
		// Walk through nodes until the end or until data matches
		while (curr != NULL && curr -> data != d) {
			prev = curr;
			curr = curr -> next;
		}
		// If data matched...
		if (curr != NULL) {
			// If head points to the same node, must update it.
			if (curr == head) {
				head = curr -> next;
			}
			prev -> next = curr -> next;
			delete curr;
			count--;
		}
	}
	// If any were deleted, there should be a difference between x and count
	return x - count;
}

double linkedlist::getLast() {
	if (count > 0) {
		return head -> data;
	} else {
		return 0;
	}
}

std::string linkedlist::getList() {
	std::string s = "";
	node *n = head;
	while (n != NULL) {
		//s += std::to_string(n -> data) + " ";
		// using ostringstream since to_string doesn't work in g++ on this server
		std::ostringstream ss;
		ss.precision(DOUBLE_PRECISION);
		ss << n -> data << " ";
		s += ss.str();
		n = n -> next;
	}
	return s;
}
