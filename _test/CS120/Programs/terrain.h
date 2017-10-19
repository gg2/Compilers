class terrain {
	private:
		
	public:
		terrain();
		terrain(char,int);
		terrain(char,int,int);
		char image;
		int cost;
		int effect;
		bool explored;
};

terrain::terrain() {
	image = ' ';
	cost = 3;
	effect = 0;
	explored = 0;
}

terrain::terrain(char i, int c) {
	image = i;
	cost = c;
	effect = 0;
	explored = 0;
}

terrain::terrain(char i, int c, int e) {
	image = i;
	cost = c;
	effect = e;
	explored = 0;
}