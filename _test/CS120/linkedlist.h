class linkedlist {
	private:
		node *head;
		int count;

		node *find_node(int);
		
	public:
		linkedlist();
		int get_count();
		
		void insert(int,string);
		void remove(int);
		
		
		string get_data(int);
		void set_data(int,string);
};