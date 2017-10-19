class robot {
private:
	int direction;
	int energy;
	int ID;
	int moved;

	void turnLeft();
	void turnRight();
	void forward(int &, int &);

public:
	robot(int);
	void refresh() {moved = 0;}
	void draw();
	void print();
	void move(int &, int &);
};

robot::robot(int id) {
	energy = 50;
	ID = id;
	moved = 0;
	direction = 0;
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
	cout << "R";
}	

void robot::print() {
	cout << "ID: " << ID 
	     << "   Energy = " << energy
	     << "   Direction = " << direction;
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