linkedlist::linkedlist() {
	count = 0;
	node *h(count-1);
	h -> set_self(h);
	h -> set_next(NULL);
	h -> set_prev(NULL);
	head = h;
}
int linkedlist::get_count() {
	return count;
}

void linkedlist::insert(int id, string s) {
	node *n;
	n = new node(id);
	n -> set_self(n);
	n -> set_data(s);
	n -> set_next(NULL);
	n -> set_prev(head);
	head = n;
	count++;
}
node *linkedlist::find_node(int id) {
	node *n = NULL;
	bool f = 0;
	do {
		
	} while (f == 0);
	return n;
}
void linkedlist::remove(int id) {
	if (head != NULL) {
		
	} else {
		return;
	}
}

string linkedlist::get_data(int id) {
	return find_node(id) -> get_data();
}
void linkedlist::set_data(int id, string s) {
	find_node(id) -> set_data(s);
}