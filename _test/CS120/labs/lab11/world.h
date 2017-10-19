/*
 * 1) Added terrain types as an array, populated in set_up()
 * 2) Added discoverability to terrain
 * 
 */

const int HEIGHT = 15;
const int WIDTH = 15;
const int TERRAIN_TYPES = 5; // # of desired types + 1 for the Undiscovered

class world {
private:
	int terrain[WIDTH][HEIGHT];
	robot *bots[WIDTH][HEIGHT];
	char biomes[TERRAIN_TYPES];
	
public:
	void set_up();
	void draw();
	void update();
};

void world::set_up() {
	biomes[0] = '_';
	biomes[1] = '^';
	biomes[2] = '#';
	biomes[3] = 'M';
	biomes[4] = ' '; // Undiscovered
	
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			bots[x][y] = NULL;
			terrain[x][y] = TERRAIN_TYPES-1;
		}
	}
	bots[2][2] = new robot(1);
	bots[4][7] = new robot(2);
	bots[11][8] = new robot(3);
	bots[13][13] = new robot(4);
}

void world::draw() {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (bots[x][y] == NULL) {
				cout << biomes[terrain[x][y]];
			}
			else {
				bots[x][y]->draw();
			}
		}
		cout << endl;
	}
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (bots[x][y] != NULL) {
				bots[x][y]->print();
				bots[x][y]->refresh();
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
			if (bots[x][y] != NULL) {
				if (terrain[x][y] == TERRAIN_TYPES-1) {
					terrain[x][y] = (rand() % (TERRAIN_TYPES-1));
				}
				tempx = x;
				tempy = y;
				bots[x][y] -> move(tempx,tempy);
				if (tempx < 0 || tempx >= WIDTH) {
					tempx = x;
				}
				if (tempy < 0 || tempy >= HEIGHT) {
					tempy = y;
				}
				if (bots[tempx][tempy] == NULL) {
					temp = bots[x][y];
					bots[x][y] = NULL;
					bots[tempx][tempy] = temp;
				}
			}
		}
	}
}