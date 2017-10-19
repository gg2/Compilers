class terrain {
	private:
		
	public:
		terrain();
		terrain(char,int);
		char image;
		int cost;
};

terrain::terrain() {
	image = ' ';
	cost = 3;
}

terrain::terrain(char i, int c) {
	image = i;
	cost = c;
}