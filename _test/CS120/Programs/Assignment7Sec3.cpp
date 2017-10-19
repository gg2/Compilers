/*
 * Playing Cards
 *
 * Gabe Gibler
 * CS120-03
 * Assignment #7
 *
 * 1) Created a card_deck class for creating a deck of cards and handling its capabilities, rather than creating a disconnected loop to create a deck.
 * 2) Made the arrays for hand1 and hand2, and make them draw from the deck
 * 
 */

#include<iostream>
#include<cstdlib>
#include<time.h>
#include"playing_card.h"
#include"card_deck.h"

using namespace std;

string const hr = "* * * * * * * * * *";

void div();

int main() {
	int i, hand_num_cards = 5;
	srand(time(NULL));
	
	div();
	cout << "Deck of Cards";
	div();
	
	card_deck deck1;
	playing_card hand1[hand_num_cards], hand2[hand_num_cards];
	
	// Print a listing of a deck of cards
	cout << "The deck contains: " << endl;
	deck1.list();
	cout << "[shuffle...]" << endl;
	deck1.shuffle();
	cout << "After shuffling: " << endl;
	deck1.list();
	cout << endl;

	cout << "Player 1 and Player 2 each draw their hands now." << endl;
	cout << "After drawing: " << endl;
	cout << "Hand1 contains: " << endl;
	for (i=0; i < hand_num_cards; i++) {
		hand1[i] = deck1.draw();
		hand1[i].flip();
		hand1[i].look();
	}
	cout << "Hand2 contains: " << endl;
	for (i=0; i < hand_num_cards; i++) {
		hand2[i] = deck1.draw();
		hand2[i].flip();
		hand2[i].look();
	}
	cout << endl << "And the deck contains: " << endl;
	deck1.list();
	
	// Exit program
	div();
 	cout << "Press enter to exit." << endl;
	cin.ignore();
	return 0;
}

// Print a visual divider for textual output
void div() {
	cout << endl << hr << endl;
}