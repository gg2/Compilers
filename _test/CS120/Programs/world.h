/*
 * 
 * 1) var "terrain" --> var "map" -- array for holding terrain types
 * 2) Added discoverability to terrain
 * 3) Rearranged order of operations w/i update method considerably.
 * 4) Enabled wrap-around for robot's movement (made world spherical)
 * 5) Robots explore an area first, before that area has its effect
 * 6) Robot collisions cause moving robot to pass along portion of their energy to the other robot
 * 
 */

const int HEIGHT = 15;
const int WIDTH = 15;
const int TERRAIN_TYPES = 10; // # of desired types + 1 for the Undiscovered
const int EXPLORATION_COST = -2; // Energy cost for exploring each area
const char UNEXPLORED_TERRAIN = ' ';

class world {
private:
	terrain map[WIDTH][HEIGHT];
	robot *bots[WIDTH][HEIGHT];
	
public:
	void set_up();
	void draw();
	void update();
};

void world::set_up() {
	// Cycle through grid and initialize bots array and create terrain
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			bots[x][y] = NULL;
			int t = rand() % (TERRAIN_TYPES);
			switch (t) {
				case 0:
				case 1:
					map[x][y] = terrain('^',13);
					break;
				case 2:
				case 3:
				case 4:
					map[x][y] = terrain('_',0);
					break;
				case 5:
					map[x][y] = terrain('#',-3,2);
					break;
				case 6:
					map[x][y] = terrain('T',-2);
					break;
				case 7:
					map[x][y] = terrain('T',-2,2);
					break;
				case 8:
					map[x][y] = terrain('M',-3,3);
					break;
				case 9:
					map[x][y] = terrain('o',-1,1);
					break;
				default:
					map[x][y] = terrain(' ',-4);
			}
		}
	}
	// Select coordinates for initial robot descents...
	bots[2][2] = new robot(1);
	bots[7][7] = new robot(2);
	bots[13][13] = new robot(3);
}

void world::draw() {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (bots[x][y] == NULL) {
				if (map[x][y].explored)
					cout << map[x][y].image;
				else
					cout << UNEXPLORED_TERRAIN;
			}
			else {
				bots[x][y] -> draw();
			}
		}
		cout << endl;
	}
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (bots[x][y] != NULL) {
				bots[x][y] -> print();
				bots[x][y] -> refresh();
				cout << endl;
			}
		}
	}
}

void world::update() {
	int tempx,tempy;
	robot *temp;
	
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (bots[x][y] != NULL && bots[x][y] -> meter() > 0) {
				if (map[x][y].explored == 0) {
					// Explore the location
					map[x][y].explored = 1;
					// Exploration cost
					bots[x][y] -> energize(EXPLORATION_COST);
				} else {
					// Continue along, and determine terrain effects
					switch (map[x][y].effect) {
						case 1:
							// Robot destroyed
							bots[x][y] = NULL;
							break;
						case 2:
							// Robot loses bearings (enters vortex)
							switch (rand() % 3) {
								case 0:
									bots[x][y] -> turnLeft();
									bots[x][y] -> turnLeft();
									break;
								case 1:
									bots[x][y] -> turnLeft();
									break;
								case 2:
									bots[x][y] -> turnRight();
									break;
							}
							break;
					}
					if (bots[x][y] != NULL && bots[x][y] -> meter() > 0) {
						tempx = x;
						tempy = y;
						if (map[x][y].effect == 3)
							// Robot cannot cross area and must turn back
							bots[x][y] -> reverse(tempx,tempy);
						else
							bots[x][y] -> move(tempx,tempy);
						// Allow wrap-around -- spherical world
						tempx = (tempx + WIDTH) % WIDTH;
						tempy = (tempy + HEIGHT) % HEIGHT;
						if (bots[tempx][tempy] == NULL) {
							temp = bots[x][y];
							bots[x][y] = NULL;
							bots[tempx][tempy] = temp;
							bots[tempx][tempy] -> energize(map[tempx][tempy].cost);
						} else if (bots[tempx][tempy] -> getID() != bots[x][y] -> getID()) {
							// Robot interactions
							bots[tempx][tempy] -> energize(bots[x][y] -> meter() / 2);
							bots[x][y] -> energize(bots[x][y] -> meter() / -2);
						}
					}
				}
			}
		}
	}
}