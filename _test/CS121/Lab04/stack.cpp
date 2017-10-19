#include"stack.h"

Stack::Stack() {
	// Nothing to prepare.
}

void Stack::push(double d) {
	List.insert(d);
}

double Stack::pop() {
	// Check against count() before calling.
	double x = 0.0;
	if (List.getCount() > 0) {
		x = List.getLast();
		List.remove(x);
	}
	return x;
}

double Stack::top() {
	// Watch out for the 0 that may mean the list was empty. 
	// Check against count() before calling.
	return List.getLast(); 
}

std::string Stack::print() {
	return List.getList();
}

int Stack::count() {
	return List.getCount();
}
