/*
 * 
 * 1) Added energize and meter methods to handle energy consumption
 * 2) Added a reverse function to handle cases of blocked movement
 * 3) Increased robot's initial energy, and randomized initial direction
 * 
 */

class robot {
	private:
		int ID;
		int energy;
		int direction;
		int moved;
	
	public:
		robot(int);
		int getID();
		void draw();
		void print();
		void energize(int);
		int meter();
		void refresh() {moved = 0;}
		void move(int &, int &);
		void forward(int &, int &);
		void reverse(int &, int &);
		void turnLeft();
		void turnRight();
};

robot::robot(int id) {
	ID = id;
	energy = 255;
	direction = rand() % 4;
	moved = 0;
}

int robot::getID() {
	return ID;
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

void robot::reverse(int &x, int &y) {
	if (moved == 1) return;

	turnLeft();
	turnLeft();
	forward(x,y);

	moved = 1;
}

void robot::turnLeft() {
	energy--;
	direction = (direction+3) % 4;
}

void robot::turnRight() {
	energy--;
	direction = (direction+1) % 4;
}

void robot::forward(int &x, int &y) {
	if (moved == 1) return;
	energy -= 2;
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

	moved = 1;
}

void robot::energize(int e) {
	energy += e;
	if (energy < 0)
		energy = 0;
}
int robot::meter() {
	return energy;
}

void robot::draw() {
	cout << "@";
}	

void robot::print() {
	cout << "ID: " << ID 
	     << "   Energy = " << energy
	     << "   Direction = " << direction;
}
