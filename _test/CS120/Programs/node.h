class node {
	private:
		node *next;
		robot *data;
	public:
		node();
		void set_next(node *n) {next = n;}
		void set_data(robot *d) {data = d;}
		node *get_next() {return next;}
		robot *get_data() {return data;}
		int remove(int);
		void remove_data() {delete data;}

		void print();
		int meter(int);
		void energize(int, int);
		void refresh(int);
		void refresh_all();
		void move(int, int &, int &);
		void forward(int, int &, int &);
		void reverse(int, int &, int &);
		void turnLeft(int);
		void turnRight(int);
};

node::node() {
	next = NULL;
	data = NULL;
}
int node::remove(int n) {
	if (next != NULL) {
		if ((next -> data) -> getID() == n) {
			node *temp;
			temp = next;
			next = next -> next;
			temp -> remove_data();
			delete temp;
			return(1);
		} else {
			return(next -> remove(n)); // try the next node
		}
	}
	return 0; // given robot was never found
}

void node::print() {
	if (next != NULL)
		next -> print();
	data -> print();
	cout << endl;
}
int node::meter(int ID) {
	if (data -> getID() == ID)
		return data -> meter();
	else if (next != NULL)
		return next -> meter(ID);
}
void node::energize(int ID, int e) {
	if (data -> getID() == ID) {
		data -> energize(e);
		data -> print();
		cout << endl;
	} else if (next != NULL)
		next -> energize(ID, e);
}
void node::refresh(int ID)  {
	if (data -> getID() == ID)
		data -> refresh();
	else if (next != NULL)
		next -> refresh(ID);
}
void node::refresh_all() {
	data -> refresh();
	if (next != NULL)
		next -> refresh_all();
}
void node::move(int ID, int &x, int &y) {
	if (data -> getID() == ID) {
		data -> move(x,y);
		data -> print();
		cout << endl;
	} else if (next != NULL)
		next -> move(ID, x, y);
}
void node::forward(int ID, int &x, int &y) {
	if (data -> getID() == ID) {
		data -> forward(x,y);
		data -> print();
		cout << endl;
	} else if (next != NULL)
		next -> forward(ID, x, y);
}
void node::reverse(int ID, int &x, int &y) {
	if (data -> getID() == ID) {
		data -> reverse(x,y);
		data -> print();
		cout << endl;
	} else if (next != NULL)
		next -> reverse(ID, x, y);
}
void node::turnLeft(int ID) {
	if (data -> getID() == ID) {
		data -> turnLeft();
		data -> print();
		cout << endl;
	} else if (next != NULL)
		next -> turnLeft(ID);
}
void node::turnRight(int ID) {
	if (data -> getID() == ID) {
		data -> turnRight();
		data -> print();
		cout << endl;
	} else if(next != NULL)
		next -> turnRight(ID);
}
