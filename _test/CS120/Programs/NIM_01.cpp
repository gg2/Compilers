/*
 * The game of NIM —
 * a simple program introducing some 
 * fundamental programming concepts.
 * 
 * Modified 2014/09/19 by Gabe Gibler
 * CS120-03
 * Assignment #3
 *
 * 1) Modified to accept a user name and utilize that throughout the game; along with some other personalization touches.
 * 2) Asks to display the rules, and does so if desired.
 * 3) Prints the number of objects removed by each player.
 * 4) Implemented srand() to seed random selection of computer's move.
 * 5) Allowed specification of # of chits.
 * 6) Instituted the possibility of naming the playing pieces (something other than chits).
 * 7) Set player names to an array (switching array per current_player).
 * 
 */

#include<iostream>
#include<cstdlib>
#include<time.h>
#include<boost/algorithm/string.hpp>

using namespace std;
using namespace boost::algorithm;

int main()
{
	// Variable initializations
	string divider = "-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-";
	string confirm = "0";
	string player_names[2] = {"The Computer", "Player 1"};
	string obj_type = "chit";
	int num_objects = 23;
	int current_player = 1;
	int move;
	srand(time(NULL));
	
	string instructions = "The game starts with a certain, limited number of " + obj_type + "s. \nPlayers take turns removing 1, 2, or 3 of the " + obj_type + "s \n(their choice each turn). The player forced to remove \nthe last " + obj_type + " loses. ";
	
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
	cout << endl << "Player 2 is " << player_names[(current_player + 1) % 2] << "." << endl;
	cout << endl;
	cin.ignore();
	// Allow for selection of the number of playing pieces
	cout << endl << "Select the number of " << obj_type << "s you'd like to play with, " << player_names[1] << endl << "(11 or more; 23 or more is ideal): ";
	cin >> num_objects;
	if (num_objects < 11) {
		num_objects = 23;
	}
	// Confirms number of pieces
	cout << endl << "There will be " << num_objects << " " << obj_type << (num_objects != 1 ? "s" : "") << " to remove. Let's begin! " << endl;
	cout << endl << divider << endl << endl;
	cin.ignore();
	
	// And begin!
	// Main game loop
	do {
		if (current_player == 1) {
			cout << player_names[current_player] << ", enter your move (1-3): ";
			cin >> move;
			while (move < 1 || move > 3 || move > num_objects) {
				cout << endl << "That's not allowed, " << player_names[current_player] << ". \nPlease enter a valid move: ";
				cin >> move;
			}
			// Displays player's choice to confirm
			cout << "Very good. " << move << " " << obj_type << (move != 1 ? "s" : "") << ", " << player_names[current_player] << "." << endl;
			cin.ignore();
		} else {
			do {
				int mod_amt = 3;
				if (num_objects < 3) {
					mod_amt = num_objects;
				}
				move = 1 + rand() % mod_amt; // random selection for computer's move
				
			} while (move < 1 || move > 3 || move > num_objects);
			// Displays computer's choice
			cout << player_names[current_player] << " removed " << move << " " << obj_type << (move != 1 ? "s" : "") << "." << endl;
		}
		// Implement the move
		num_objects = num_objects - move;
		cout << "Number of " << obj_type << "s left: " << num_objects << endl << ". . ." << endl;
		// Switch players
		current_player = (current_player + 1) % 2;
	} while (num_objects > 0);

	// End of game
	cout << endl << divider << endl << endl;
	cout << player_names[current_player] << " wins!" << endl;
	cout << endl << divider << endl;
	cout << endl << "Press enter to quit." << endl;
	cin.ignore();
	return 0;
}
