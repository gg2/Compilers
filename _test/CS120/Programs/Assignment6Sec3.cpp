/*
 * declaration of the pet class
 *
 * Gabe Gibler
 * CS120-03
 * Assignment #6
 *
 * 1) Incorporates modifications from lab6
 * 2) Added obedience and train() as associated member and method
 * 3) Added a loss scenario for 0 obedience
 * 4) Made obedience interact with other actions
 * 5) Added a happenstance function that is called randomly from check_health();
 * 
 */

#include<iostream>
#include<string>
#include<cstdlib>
#include<time.h>

using namespace std;

string const hr = "* * * * * * * * * *";

void div();

class pet {
   private:          // private data members
      string type;
      string voice;
      string name;
      int hunger;
      int happiness;
      int obedience;
   public:          // public member functions
      pet();                // constructor
      void print();
      int check_health();
      void train();
      void play();
      void feed();
      void happenstance();
};

int main() {
	pet pet1;
	int choice;
	int health_check;
	srand(time(NULL));
	do {
	 pet1.print();
	 cout << "What would you like to do with your pet?\n";
	 cout << " Train (1) \n Play (2) \n Feed (3) \n Exit (0) \n";
	 cin >> choice;
	 switch(choice) {
	 	case 0:
	 		cout << "Goodbye!" << endl;
	 		break;
		case 1:
			pet1.train();
			break;
		case 2:
			pet1.play();
			break;
		case 3:
			pet1.feed();
			break;
		default:
			cout << "Your pet can't do that. Try something else." << endl;
	}
	health_check = pet1.check_health();
	} while(choice != 0 && health_check != 1);
	
	div();
	cout << "Press enter to exit." << endl;
	cin.ignore();
	return 0;
}

/* Constructor, creates a new pet with starting values. */
pet::pet(){
	hunger = 50;
	happiness = 50;
	obedience = 20;
	div();
	cout << "What kind of pet is this (one word)? ";
	cin >> type;
	cin.ignore();
	cout << "What do " << type << "s say (one word)? ";
	cin >> voice;
	cin.ignore();
	cout << "Please name your " << type << " (one word): ";
	cin >> name;
	div();
}

/* Member function print(), prints information about a pet. */
void pet::print(){
	div();
	cout << "~ Your " << type << ", " << name << " ~" << endl;
	cout << " Obedience: " << obedience << endl;
	cout << " Happiness: " << happiness << endl;
	cout << " Hunger: " << hunger;
	div();
}
/* Member function check_health(), checks the health of a pet. */
int pet::check_health(){
	if (hunger >= 100) {
		div();
		cout << name << " has starved. You should not be a pet owner." << endl;
		return 1;
	}
	if (hunger < 0) {
		div();
		cout << "Alas, " << name << " passed away in the night from a mysterious disease." << endl;
		return 1;
	}
	if (happiness <= 0) {
		div();
		cout << voice << "! " << name << " died of a broken heart." << endl;
		return 1;
	}
	if (obedience <= 0) {
		div();
		cout << "Your " << type << ", " << name << ", has run away after biting the neighbor lady's ankles." << endl;
		return 1;
	}
	// obedience and automatically degrade, and must be kept after despite all other choices
	obedience -= 5;
	hunger += 5;
	// check for 
	if ((rand() % 8) == 0) {
		happenstance();
	}
	return 0;
}
/* Member function train(), allows teaching a pet to be obedient. */
void pet::train() {
	cout << "Sit, " << name << ". Stay. Good " << type << ". " << endl << "Down. Down! Be good." << endl;
	cout << voice << endl;
	obedience += 50;
	if (obedience > 100) {
		obedience = 100;
	}
}
/* Member function play(), allows playing with a pet. */
void pet::play(){
	int choice = 0;
	cout << "What should we play?" << endl;
	cout << " Pet your pet (1) \n Fetch (2) \n Roll over (3)" << endl;
	cin >> choice;
	cin.ignore();
	cout << endl;
	switch(choice) {
		case 1:
			cout << "\"Good " << type << ", " << name << ".\"" << endl;
			if (obedience < 10) {
				cout << "Grrrr..." << endl;
			} else {
				cout << voice << endl;
				happiness += 5;
				obedience += 2;
			}
			hunger += 0;
			break; 
		case 2:
			cout << voice << "! *tromp,tromp,tromp* ... *tromp,tromp,tromp* *pant* *pant*" << endl;
			happiness += 10;
			hunger += 12;
			break;
		case 3:
			cout << "\"Roll over, " << name << "!\"" << endl;
			if (obedience < 20) {
				cout << voice << "!" << endl;
			} else {
				cout << "*roll*" << endl;
				happiness += 2;
				obedience += 5;
			}
			hunger += 5;
			break;
		default:
			cout << "Your " << type << " can't do that. Try something else." << endl;
	}
}
/* Member function feed(), allows the user to feed a pet. */
void pet::feed(){
    cout << "*munch* *munch* mmmm." << endl;
    hunger -= 25;
    if (hunger < 0) {
    	hunger = 0;
    }
}
/* Member function happenstance(), for occurrence of random events */
void pet::happenstance() {
	div();
	switch(rand() % 6) {
		case 0:
		// positive hunger
			cout << name << " found something very dead and stinky yet tasty to eat. \nWhatever it was, it was thoroughly enjoyed. ";
			hunger -= 25;
			obedience -= 5;
			happiness += 5;
			break;
		case 1:
		// negative hunger
			cout << name << " just spent 20 minutes in a manic frenzy chasing dust bunnies, ghosts, and itself around the house. ";
			hunger += 25;
			happiness += 10;
			break;
		case 2:
		// positive happiness
			cout << name << " just ralphed and ate up every bit of the end result. ";
			happiness +=10;
			obedience -=5;
			break;
		case 3:
		// negative happiness
			cout << name << " wasn't very excited about being left behind for your extended weekend getaway. \nWhen you returned home, " << name << " was moping pitifully in the corner";
			happiness -= 50;
			break;
		case 4:
		// positive obedience
			cout << name << " just burnt its tongue on the freshly baked lasagna you told it to stay away from. ";
			obedience += 10;
			happiness -= 10;
			break;
		case 5:
		// negative obedience
			cout << "You need to improve your training methods, because " << name << " is apparently not responding very well to them. ";
			obedience -= 15;
			break;
		default:
			break; // do nothing
	}
	div();
}

void div() {
	cout << endl << hr << endl;
}