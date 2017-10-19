class node {
	private:
		node *next;
		node *self;
		node *prev;
		int id;
		string data;
		
	public:
		node(int);
		int get_id();
		
		node *get_next();
		void set_next(node*);
		node *get_self();
		void set_self(node*);
		node *get_prev();
		void set_prev(node*);
		
		string get_data();
		int set_data(string);
};
