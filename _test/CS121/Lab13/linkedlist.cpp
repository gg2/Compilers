#include"linkedlist.h"

linkedlist::linkedlist() {
	head = NULL;
	count = 0;
}

int linkedlist::size() {
	return count;
}

void linkedlist::add(link_data d) {
	Node *n = new Node();
	n->data = d;
	if (head == NULL) {
		n->next = NULL;
	} else {
		n->next = head;
	}
	head = n;
	count++;
}

int linkedlist::remove(link_data d) {
	int x = count;
	if (head != NULL) {
		Node *curr = head, *prev = head;
		// Walk through nodes until the end or until data matches
		while (curr != NULL && curr->data != d) {
			prev = curr;
			curr = curr->next;
		}
		// If data matched...
		if (curr != NULL) {
			// If head points to the same node, must update it.
			if (curr == head) {
				head = curr->next;
			}
			prev->next = curr->next;
			delete curr;
			count--;
		}
	}
	// If any were deleted, there should be a difference between x and count
	return x - count;
}

link_data linkedlist::last() {
	if (count > 0) {
		return head->data;
	} else {
		return 0;
	}
}

std::string linkedlist::print() {
	std::string s = "";
	Node* n = head;
	while (n != NULL) {
		// using ostringstream since to_string doesn't work in g++ on this server
		std::ostringstream ss;
		ss << n->data << " ";
		s += ss.str();
		n = n->next;
	}
	return s;
}
