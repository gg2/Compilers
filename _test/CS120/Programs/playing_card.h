/*
 * Playing Card class
 * 
 */

//#include<iostream>
//#include<cstdlib>
#include<string>
#include<sstream>

using namespace std;

class playing_card
{
	private:
		int rank;
		int suit;
		string Rank;
		string Suit;
		bool visibility;
		bool set(int,int);
		void random();	// Requires seeding rand initially in the calling program
	public:
		playing_card();
		playing_card(int,int);
		void choose(int,int);
		int get_rank();
		int get_suit();
		void look();
		void peek();
		void flip();
};

// Constructor; creates a default, random card
playing_card::playing_card() {
	random();
}
// Constructor that accepts rank and suit to create a card
playing_card::playing_card(int r, int s) {
	set(r, s);
}
// Sets the rank and suit of the card
bool playing_card::set(int r, int s) {
	// Start the card face down
	visibility = 0;
	
	// Ace == 1, 2-10, Jack == 11, Queen == 12, King == 13
	rank = 0;
	if (r > 0 && r < 14) {
		rank = r;
	}
	switch (rank) {
		case 1:
			Rank = "Ace";
			break;
		case 11:
			Rank = "Jack";
			break;
		case 12:
			Rank = "Queen";
			break;
		case 13:
			Rank = "King";
			break;
		default:
			ostringstream strconverter;
			strconverter << rank;
			Rank = strconverter.str();
	} 
	// Spades == 1, Hearts == 2, Diamonds == 3, Clubs == 4
	suit = 0;
	if (s > 0 && s < 5) {
		suit = s;
	}
	switch (suit) {
		case 1:
			Suit = "Spades";
			break;
		case 2:
			Suit = "Hearts";
			break;
		case 3:
			Suit = "Diamonds";
			break;
		case 4:
			Suit = "Clubs";
			break;
		default:
			Suit = "Unset";
	}
	 
	return (rank * suit);
}
// Set the card to a random rank and suit
void playing_card::random() {
	set(((rand() % 13) + 1),((rand() % 4) + 1));
}
// Allows the card to be specified or changed after creation
void playing_card::choose(int r, int s) {
	set(r, s);
}
// Returns the card's numeric rank value
int playing_card::get_rank() {
	return rank;
}
// Returns the card's numeric suit value
int playing_card::get_suit() {
	return suit;
}
// View the state of the card -- print its properties dependent on visibility
void playing_card::look() {
	if (visibility) {
		cout << Rank << " of " << Suit;
	} else {
		cout << "[ face down ]";
	}
	cout << endl;
}
// Peek at the card -- print its properties for a user to see, but do not change its visibility
void playing_card::peek() {
	cout << "<<" << Rank << " of " << Suit << ">>" << endl;
}
// Turn the card over
void playing_card::flip() {
	visibility = !visibility;
}