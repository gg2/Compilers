/*
 * Deck of Cards class
 * 
 */

//#include<iostream>
//#include<cstdlib>
//#include"playing_card.h"

using namespace std;

class card_deck
{
	private:
		int num_cards;
		playing_card deck[312];
		int current_i;
		void create();
	public:
		card_deck();
		card_deck(int);
		void list();
		void shuffle();
		void sort();
		playing_card draw();
};

// Card deck constructor
card_deck::card_deck() {
	num_cards = 52;
	current_i = 0;
	create();
}
// Card deck constructor; accepts an integer to define the number of cards in the deck; 
// Initializes as an empty set
card_deck::card_deck(int s) {
	if (s > 312) {
		s = 312;
	}
	if (s < 1) {
		s = 1;
	}
	num_cards = s;
	current_i = 0;
	//create();
}
// Construct the deck
void card_deck::create() {
	for (int i=0; i < num_cards; i++) {
		deck[i].choose(((i % 13)+1),((i/13)+1));
	}
}
// Print out a listing of all the cards in the deck, in order
void card_deck::list() {
	for (int i=current_i; i < num_cards; i++) {
		deck[i].flip();
		deck[i].look();
		deck[i].flip();
	}
}
// Randomize the deck order; shuffles only the range of cards currently "in" the deck
void card_deck::shuffle() {
	int x;
	int y;
  playing_card temp;	
  
	for (int i=0; i < (num_cards * 7); i++) {
		// Sort the cards currently in the deck (exclude those already drawn) 
		x = ((rand() % (num_cards - current_i)) + current_i);
		y = ((rand() % (num_cards - current_i)) + current_i);
		temp = deck[x];
		deck[x] = deck[y];
		deck[y] = temp;
	}
}
// Organize the deck; resets it entirely at the same time
void card_deck::sort() {
	current_i = 0;
	create();
}
// Draw a card from the top
playing_card card_deck::draw() {
	if (current_i >= num_cards) {
		current_i = 0;
		shuffle();
	}
	return deck[current_i++];
}
