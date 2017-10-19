node::node(int i) {
	id = i;
	next = NULL;
	self = NULL;
	prev = NULL;
	
	data = "";
}

int node::get_id() {
	return id;
}


node *node::get_next() {
	return next;
}
void node::set_next(node *a) {
	next = a;
}
node *node::get_self() {
	return self;
}
void node::set_self(node *a) {
	self = a;
}
node *node::get_prev() {
	return prev;
}
void node::set_prev(node *a) {
	prev = a;
}

string node::get_data() {
	return data;
}
int node::set_data(string s) {
	data = s;
	return 0;
}
