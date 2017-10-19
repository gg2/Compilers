// C/C++

#include<iostream>
#include<cstdlib>

using namespace std;

struct Node {
	int info;
	struct Node* next;
};
void PrintList();
int ListLength();

typedef struct Node* NodePtr;
NodePtr head = NULL;

int main() 
{
	return 0;
}

void PrintList() {
	NodePtr p = head;
	
	while (p != NULL) {
		cout << p->info << endl;
		p = p->next;
	}
}

int ListLength() {
	int n = 0;
	NodePtr p = head;
	
	while( p != NULL ) {
		n++;
		p = p->next;
	}
	
	return n;
}

// Insert at the front
void AddToFront( int x ) {
	// Allocate
	NodePtr n = new Node;
	
	// Initialize
	n->info = x;
	n->next = NULL;
	
	// Insert
	if( head == NULL) {
		head = n;
	} else {
		n->next = head;
		head = n;
	}
}
// Insert at the end
void AddToEnd( int x ) {
	// Allocate
	NodePtr n = new Node;
	
	// Initialize
	n->info = x;
	n-> next = NULL;
	
	// Insert
	if( head == NULL ) {
		head = n;
	} else {
		NodePtr p = head;
		while ( p->next != NULL ) {
			p = p->next;
		}
			
			p->next = n;
	}
}

// Delete from the front
void RemoveFromFront() {
	NodePtr p = head;
	
	if ( p == NULL ) {
		// do nothing;
	} else {
		head = p->next;
		
		p->next = NULL;
		delete p;
	}
}

// Delete from the end
void RemoveFromEnd() {
	if ( head != NULL ) {
		NodePtr curr = head;
		NodePtr prev = head;
		
		while ( curr->next != NULL) {
			prev = curr;
			curr = curr->next;
		}
		
		if ( prev == NULL )
			head = NULL;
		else
			prev->next = NULL;
		
		delete curr;
	}
}

