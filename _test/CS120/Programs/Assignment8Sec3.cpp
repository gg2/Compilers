/*
 * Board Game
 *
 * Gabe Gibler
 * CS120-03
 * Assignment #8
 *
 * 1) Program fetches a game title, instructions, the "goal" name, and the victory statement from the game info text.
 * 2) Created a player class, for handling each player's data.
 * 3) Made the game utilize the player class, including shortening the main while game loop as it iterates using only the current player's info.
 * 4) Game accepts a variable number of players.
 * 5) Squares can move players a random number of spaces, if their movement modifier is set >= board_length. 
 *    There is also a modifier set in the game info text that determines the portion of board_length that a random move can be.
 * 6) Added "resolve" as an attribute for each player. If resolve == 0, player will go home and move no more. (3 strikes and you're out, effectively.)
 * 
 */

#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include<ctime>
#include<cstdlib>

using namespace std;

// Declaration of square class
class square {
	private:
		int move;
		int effect;
		char symbol;
		string message;
	public:
		square();
		void print();
		int action(int,int,int&);
		void set(int,int,char,string);
};
// Declaration of player class
class player {
	private:

	public:
		player();
		string name;
		char symbol;
		int position;
		int resolve;
};

// Function prototypes
void read_game(string[],square[]);
void create_player(player[],int);
void print_board(square[],player,string);
void check_position(player);
// Global variables
// Title [line 1], Instructions [line 2], Goal Name [line 3], Victory Text [line 4], Random Move Modifier [line 5]
const int meta_ct = 5;
const int board_length = 20;
int num_players = 2;

int main() {
	int current_player = 1, roll, rand_mod = 2;
	square the_board[board_length];
	string game_info[meta_ct];
	srand(time(NULL));
	
	// Fetch game data
	read_game(game_info, the_board);
	cout << endl;
	for (int i=0; i < meta_ct-3; i++) {
		cout << game_info[i] << endl << endl;
	}
	istringstream strconverter(game_info[4]);
	strconverter >> rand_mod;
	if (rand_mod < 1)
		rand_mod = 2;
	// Number of players and player setup
	do {
		if (num_players < 2 || num_players > 12)
			cout << "Please choose a number of players from 2 to 12. ";
		else
			cout << "How many players? (2-12) ";
		cin >> num_players;
	} while (num_players < 2 || num_players > 12);
	player players[num_players];
	for (int i=0; i < num_players; i++) {
		create_player(players, i);
	}
	cout << endl;
	// Initial display of the board
	for (int i=0; i < num_players; i++) {
		print_board(the_board, players[i], game_info[2]);
	}
	
	do {
		cout << "\n\n\n" << players[current_player-1].name << ", type enter to roll." << endl;
		cin.ignore();
		roll = 1 + (rand() % 5);
		cout << players[current_player-1].name << " rolled " << roll << "." << endl;
		players[current_player-1].position += roll;
		check_position(players[current_player-1]);
		players[current_player-1].position += the_board[players[current_player-1].position].action(board_length-1, rand_mod, players[current_player-1].resolve);
		check_position(players[current_player-1]);
		for (int i=0; i < num_players; i++) {
			print_board(the_board, players[i], game_info[2]);
		}
		current_player = (current_player % num_players) + 1;
	} while(players[((current_player-1 + num_players-1) % num_players)].position < board_length - 1);
	// Resetting to previous player
	current_player = ((current_player-1 + num_players-1) % num_players) + 1;
	cout << endl << players[current_player-1].name << game_info[3] << endl;
	cin.ignore();
	return 0;
}

void read_game(string g[], square b[]) {
	ifstream infile;
	infile.open("game.txt");
	string game_meta;
	int square_number, square_move, square_effect;
	char square_symbol;
	string square_message;
	
	// Fetch the game metadata
	for (int m = 0; m < meta_ct; m++) {
		getline(infile, game_meta);
		g[m] = game_meta;
	}
	while (!infile.eof()) {
		infile >> square_number >> square_move >> square_effect >> square_symbol;
		getline(infile, square_message);
		if(square_number < board_length)
			b[square_number].set(square_move, square_effect, square_symbol, square_message);
	}
}
void print_board(square b[], player p, string goal_name) {
	for(int i=0; i < board_length; i++) {
		if(i != p.position)
			b[i].print();
		else
			cout << p.symbol;
	}
	cout << goal_name << endl;
	for(int i=0; i < board_length; i++) {
		cout << "-";
	}
	cout << endl;
}
void create_player(player p[], int n) {
	cout << "Player " << n+1 << ", what is your name (one word only)? ";
	cin >> p[n].name;
	cout << "What symbol would you like to use for your player, " << p[n].name << " (a single letter, number or symbol)? "; 
	cin >> p[n].symbol;
	p[n].position = 0;
	cout << "That's it. You're all set up, " << p[n].name << "." << endl;
	cin.ignore();
}
void check_position(player p) {
	if(p.position < 0 || p.resolve < 1)
		p.position = 0;
	if(p.position >= board_length)
		p.position = board_length - 1;
}

// Functions of the class square
square::square() {
	move = 0;
	effect = 0;
	symbol = ' ';
	message = "";
}
int square::action(int max, int rand_mod, int &resolve) {
	cout << message << endl;
	resolve += effect;
	// Set a movement modifier greater than the length of the board to indicate a randomized move
	// The game info text should contain a number to indicate the amount to modify the random move.
	if (move > max) {
		return ((rand() % (max/rand_mod)) - (max/rand_mod/2));
	} else {
		return move;
	}
}
void square::print() {
	cout << symbol;
}
void square::set(int m, int e, char s, string msg) {
	move = m;
	effect = e;
	symbol = s;
	message = msg;
}

// Functions of the class player
player::player() {
	name = "X";
	symbol = 'X';
	position = 0;
	resolve = 3;
}
