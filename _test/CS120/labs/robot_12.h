/*
 * 
 * 1) Added energize and meter methods to handle energy consumption
 * 
 */

class robot {
private:
	int ID;
	int energy;
	int direction;
	int moved;

	void turnLeft();
	void turnRight();
	void forward(int &, int &);

public:
	robot(int);
	void refresh() {moved = 0;}
	void draw();
	void print();
	void energize(int);
	int meter();
	void move(int &, int &);
};

robot::robot(int id) {
	ID = id;
	energy = 99;
	direction = 0;
	moved = 0;
}


void robot::turnLeft() {
	energy--;
	direction = (direction+3)%4;
}

void robot::turnRight() {
	energy--;
	direction = (direction+1)%4;
}

void robot::forward(int &x, int &y) {
	energy-=2;
	switch(direction) {
	case 0:
		y--;
		break;
	case 1:
		x++;
		break;
	case 2:
		y++;
		break;
	case 3:
		x--;
		break;

	}
}

void robot::draw() {
	cout << "@";
}	

void robot::print() {
	cout << "ID: " << ID 
	     << "   Energy = " << energy
	     << "   Direction = " << direction;
}

void robot::energize(int e) {
	energy += e;
}
int robot::meter() {
	return energy;
}

void robot::move(int &x, int &y) {
	if (moved == 1) return;
	switch(rand() % 4) {
	case 0:
		turnLeft();
		break;
	case 1:
		turnRight();
		break;
	case 2:
	case 3:
		forward(x,y);
		break;
	default:
		cout << "Error in robot move." << endl;
	}
	moved = 1;
}