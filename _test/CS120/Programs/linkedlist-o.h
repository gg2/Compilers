/*
 * 
 * 2) Modified turnLeft (made it specific to a single node, same as most of the other robot methods).
 * 
 * 4) Already made most of the new methods robot specific #2; instead, I made a version of refresh that targets all robots in the list.
 *
*/

class linkedlist {
	private:
		int count;
		node *head;
	public:
		linkedlist();
		int getCount();
		void insert(robot*);
		void remove(int);
		
		robot *get(int);
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

linkedlist::linkedlist() {
	head = NULL;
	count = 0;
}
int linkedlist::getCount() {
	return count;
}

void linkedlist::insert(robot *rp) {
	node *n;
	n = new node;
	n -> set_data(rp);
	n -> set_next(head);
	head = n;
	count++;
}
void linkedlist::remove(int n) {
	if (head == NULL)
		return;
	if ((head -> get_data()) -> getID() == n) {
		node *temp;
		temp = head;
		head = head -> get_next();
		temp -> remove_data();
		delete temp;
		count--;
	} else {
		if (head -> remove(n) == 1)
			count--;
	}
}

robot *linkedlist::get(int ID) {
	robot *r = NULL;
	node *n = head; // <-- dereference or not!?
	while (n != NULL)
	{
		r = n -> get_data();
		if (r -> getID() == ID) {
			n = NULL;
			return r;
		} else {
			r = NULL;
			n = n -> get_next();
		}
	}
	return r;
}
void linkedlist::print() {
	cout << "There are " << count << " robots in the list: \n";
	if (head != NULL)
		head -> print();
}

int linkedlist::meter(int ID) {
	if (head != NULL)
		return head -> meter(ID);
}
void linkedlist::energize(int ID, int e) {
	if (head != NULL)
		head -> energize(ID, e);
}
void linkedlist::refresh(int ID)  {
	if (head != NULL)
		head -> refresh(ID);
}
void linkedlist::refresh_all() {
	if (head != NULL)
		head -> refresh_all();
}
void linkedlist::move(int ID, int &x, int &y) {
	if (head != NULL)
		head -> move(ID, x, y);
}
void linkedlist::forward(int ID, int &x, int &y) {
	if (head != NULL)
		head -> forward(ID, x, y);
}
void linkedlist::reverse(int ID, int &x, int &y) {
	if (head != NULL)
		head -> reverse(ID, x, y);
}
void linkedlist::turnLeft(int ID) {
	if (head != NULL)
		head -> turnLeft(ID);
}
void linkedlist::turnRight(int ID) {
	if (head != NULL)
		head -> turnRight(ID);
}
