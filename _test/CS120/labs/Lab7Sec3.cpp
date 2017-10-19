/*
 * Playing Card class
 *
 * Gabe Gibler
 * CS120-03
 * Lab #7
 *
 * Main prints a listing of a deck of cards (no jokers; where are the jokers?!) and
 * prints out a set of cards (size of hand based on input)
 * 1) playing_card contains an additional visibility property, to store whether the card is face up or face down
 * 2) Added look(), peek(), and flip() methods; 
 * 	look() looks at the card, as it is in relation to the user considering visibility;
 * 	peek() looks at the face side of the card, regardless of visibility;
 * 	flip() works with visibility;
 * 3) In this rendition, the default constructor, cheat() work per the assignment's instructions. 
 * 	print() works differently and returns a report on the card's properties, since look() and peek() already do what the instructions intended print() to do
 */

#include<iostream>
#include<cstdlib>
#include<string>
#include<sstream>
#include<time.h>

using namespace std;

string const hr = "* * * * * * * * * *";

void div();

class playing_card
{
	private:
		int rank;
		int suit;
		string Rank;
		string Suit;
		bool visibility;
		bool set(int,int);
	public:
		playing_card();
		playing_card(int,int);
		void random();	// Requires seeding rand initially in the calling program
		void cheat();
		void print();
		void look();
		void peek();
		void flip();
};

int main() {
	int i,r,s;
	int hand_size = 1;
	srand(time(NULL));
	
	div();
	cout << "Deck of Cards";
	div();
	
	// Print a listing of a deck of cards
	cout << "The deck contains: " << endl;
	for (s=1; s<5; s++) {
		for (r=2; r<15; r++) {
			if (r==14) {
				r=1;
			}
			playing_card card(r,s);
			card.flip();
			card.look();
			if (r==1) {
				r=14;
			}
		}
		cout << "* * *" << endl;
	}
	cout << endl << "But what about the Jokers ... ?" << endl << endl;
	
	// Generate a hand of cards
	cout << "How many cards in your hand? (int) ";
	cin >> hand_size;
	cout << endl;

	playing_card hand[hand_size];
	
	cout << "Your hand contains: " << endl;
	for (i=0; i < hand_size; i++) {
		hand[i].random();
		hand[i].flip();
		hand[i].look();
	}
	
	// Exit program
	div();
 	cout << "Press enter to exit." << endl;
	cin.ignore();
	return 0;
}
// Constructor; creates a default, invalid card
playing_card::playing_card() {
	set(-1,-1);
}
// Constructor that accepts rank and suit to create a valid card
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
	// Clubs == 1, Diamonds == 2, Hearts == 3, Spades == 4
	suit = 0;
	if (s > 0 && s < 5) {
		suit = s;
	}
	switch (suit) {
		case 1:
			Suit = "Clubs";
			break;
		case 2:
			Suit = "Diamonds";
			break;
		case 3:
			Suit = "Hearts";
			break;
		case 4:
			Suit = "Spades";
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
// Set the card to the Ace of Spades
void playing_card::cheat() {
	set(1,4);
}
// Prints the card's properties
void playing_card::print() {
	cout << "Rank == " << Rank << " (" << rank << ")" << endl;
	cout << "Suit == " << Suit << " (" << suit << ")" << endl;
	cout << "Face " << (visibility ? "up" : "down") << endl;
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
// Print a visual divider for textual output
void div() {
	cout << endl << hr << endl;
}