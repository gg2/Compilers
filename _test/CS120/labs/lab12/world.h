/*
 * 
 * 1) var "terrain" --> var "map" + biomes array for holding terrain types
 * 2) Added discoverability to terrain
 * 3) Rearranged order of operations w/i update method considerably.
 * 4) 
 * 
 */

const int HEIGHT = 15;
const int WIDTH = 15;
const int TERRAIN_TYPES = 5; // # of desired types + 1 for the Undiscovered

class world {
private:
	terrain map[WIDTH][HEIGHT];
	robot *bots[WIDTH][HEIGHT];
	char biomes[TERRAIN_TYPES];
	
public:
	void set_up();
	void draw();
	void update();
};

void world::set_up() {
	biomes[0] = '^';
	biomes[1] = '_';
	biomes[2] = '#';
	biomes[3] = 'M';
	biomes[4] = ' '; // Undiscovered
	
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			bots[x][y] = NULL;
			map[x][y] = terrain(biomes[TERRAIN_TYPES-1],TERRAIN_TYPES-1);
		}
	}
	bots[2][2] = new robot(1);
	bots[7][7] = new robot(2);
	bots[13][13] = new robot(3);
}

void world::draw() {
	for (int y = 0; y < HEIGHT; y++) {
		for (int x = 0; x < WIDTH; x++) {
			if (bots[x][y] == NULL) {
				cout << map[x][y].image;
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
				if (bots[x][y] -> meter() > 0) {
					if (map[x][y].image == biomes[TERRAIN_TYPES-1]) {
						int t = rand() % (TERRAIN_TYPES-1);
						map[x][y].image = biomes[t];
						map[x][y].cost = -t;
						if (t == 0)
							map[x][y].cost = 13;
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
						bots[tempx][tempy] -> energize(map[tempx][tempy].cost);
					}
				}
			}
		}
	}
}