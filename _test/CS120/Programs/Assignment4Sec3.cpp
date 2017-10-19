/*
 * The game of NIM —
 * a simple program introducing some 
 * fundamental programming concepts.
 * 
 * Modified 2014/09/24 by Gabe Gibler
 * CS120-03
 * Assignment #4
 * 
 * 1) Added commentary.
 * 2) Added the "graphical" output of playing pieces.
 * 3) Added a replay option, and scorekeeping
 * 
 */

#include<iostream>
#include<cstdlib>
#include<time.h>
#include<boost/algorithm/string.hpp>

using namespace std;
using namespace boost::algorithm;

int switch_player(int);

int main()
{
	// Variable initializations
	string divider = "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-";
	string confirm = "0";
	string player_names[2] = {"The Computer", "Player 1"};
	int score[2] = {0,0};
	string pp_type = "chit";
	string pp_symbol = "O";
	double pp_ct_orig = 23.0;
	double pp_percent_rem = 0.0;
	int pp_ct_rem = (int)pp_ct_orig;
	int current_player = 1;
	int move;
	srand(time(NULL));
	
	string instructions = "The game starts with a certain, limited number of " + pp_type + "s. \nPlayers take turns removing their choice of 1, 2, or 3 " + pp_type + "s. \nThe player forced to remove the last " + pp_type + " loses. \nThe player who loses the game gets to play first in the next game.";
	
	// Game intro
	cout << endl << divider << endl;
	cout << endl << "The Game of Nim" << endl;
	cout << endl << divider << endl;
	// Displays the instructions (or not) per user's response
	cout << endl << "Would you like to see the instructions? (y/n) ";
	cin >> confirm;
	trim(confirm);
	to_lower(confirm);
	cin.ignore();
	
	if (confirm != "0" && confirm != "n" && confirm != "no") 
	{
		cout << endl << instructions << endl;
		
		cout << endl << "When you're finished, press enter." << endl;
		cin.ignore();
	}
	
	// Game setup
	cout << endl << divider << endl;
	cout << endl << "Well, let's set up the game... " << endl;
	// Get user's name, and returns the computer's alias (which is fixed for now)
	cout << endl << "Player " << current_player << ", what is your name? ";
	cin >> player_names[current_player];
	trim(player_names[current_player]);
	cout << endl << "Player 2 is " << player_names[switch_player(current_player)] << "." << endl;
	cout << endl;
	cin.ignore();
	
	// Begin loop allowing for repeated game play
	do {

		// Allow for selection of the number of playing pieces
		cout << endl << "Select the number of " << pp_type << "s you'd like to play with, " << player_names[1] << endl << "(11 or more; 23 or more is ideal): ";
		cin >> pp_ct_rem;
		if (pp_ct_rem < 11) {
			pp_ct_rem = 23;
		}
		pp_ct_orig = (double)pp_ct_rem;
		// Confirms number of pieces
		cout << endl << "There will be " << pp_ct_rem << " " << pp_type << (pp_ct_rem != 1 ? "s" : "") << " to remove. Let's begin! " << endl;
		cout << endl << divider << endl << endl;
		cin.ignore();
		
		// And begin!
		// Main game loop
		do {
			if (current_player == 1) {
				cout << player_names[current_player] << ", enter your move (1-3): ";
				cin >> move;
				while (move < 1 || move > 3 || move > pp_ct_rem) {
					cout << endl << "That's not allowed, " << player_names[current_player] << ". \nPlease enter a valid move: ";
					cin >> move;
				}
				// Displays player's choice to confirm
				cout << "Very good. " << move << " " << pp_type << (move != 1 ? "s" : "") << ", " << player_names[current_player] << "." << endl;
				cin.ignore();
			} else {
				do {
					int mod_amt = 3;
					if (pp_ct_rem < 3) {
						mod_amt = pp_ct_rem;
					}
					move = 1 + rand() % mod_amt; // random selection for computer's move
					
				} while (move < 1 || move > 3 || move > pp_ct_rem);
				// Displays computer's choice
				cout << player_names[current_player] << " removed " << move << " " << pp_type << (move != 1 ? "s" : "") << "." << endl;
			}
			// Implement the move
			pp_ct_rem = pp_ct_rem - move;
			pp_percent_rem = pp_ct_rem/pp_ct_orig;
			if (pp_percent_rem > .54) {
					cout << pp_ct_rem << " " << pp_type << "s left. " << player_names[switch_player(current_player)] << "'s turn." << endl; 
			} else if (pp_percent_rem > .46) {
					cout << "We're moving along to the last half of the game." << endl; 
			} else if (pp_percent_rem >= .3) {
					cout << "Interesting move. " << pp_ct_rem << " " << pp_type << "s left. Let's see how " << player_names[switch_player(current_player)] << " responds." << endl; 
			} else if (pp_percent_rem >= .2) {
					cout << "It's down to the wire. " << player_names[switch_player(current_player)] << " needs to choose carefully. " << pp_ct_rem << " " << pp_type << "s to remove." << endl; 
			} else if (pp_percent_rem > 0) {
				if (pp_ct_rem > 1) {
					cout << pp_ct_rem << " " << pp_type << "s to go now! These next few moves will decide the game, folks." << endl;
				} else {
					cout << pp_ct_rem << " " << pp_type << "! It's all over for " << player_names[switch_player(current_player)] << "." << endl;
				}
			} else if (pp_ct_rem == 0) {
				cout << "Game over!" << endl;
			} else {
					cout << "Did you see that? What was that, folks? I need to watch the replay." << endl; 
			}
			// cout << "Number of " << pp_type << "s left: " << pp_ct_rem << endl;
			// Print out a graphical representation of the number of remaining playing pieces
			cout << "[ ";
			for (int i=pp_ct_rem; i > 0; i--) {
				cout << pp_symbol;
			}
			cout << " ]" << endl;
			// Switch players
			current_player = switch_player(current_player);
		} while (pp_ct_rem > 0);
	
		// End of game
		cout << endl << divider << endl << endl;
		cout << player_names[current_player] << " wins!" << endl << endl;
		
		// Increment and display the running score
		score[current_player]++;
		cout << "-.-. Score .-.-" << endl;
		cout << player_names[current_player] << ": " << score[current_player] << endl;
		cout << player_names[switch_player(current_player)] << ": " << score[switch_player(current_player)] << endl;
		cout << divider << endl << endl;
		
		cout << "Play another game? (y/n) ";
		cin >> confirm;
		trim(confirm);
		to_lower(confirm);
		cin.ignore();
		current_player = switch_player(current_player);
	} while(confirm == "1" || confirm == "y" || confirm == "yes");
	
	cout << endl << divider << endl << endl;
	cout << "Thanks for playing!" << endl;
	cout << "Press enter to quit." << endl;
	cin.ignore();
	return 0;
}

int switch_player(int c) {
	return (c + 1) % 2;
};
