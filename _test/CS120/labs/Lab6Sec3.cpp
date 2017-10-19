/*
 * declaration of the pet class
 *
 * Gabe Gibler
 * CS120-03
 * Lab #6
 *
 * 1) Added default cases to main() and pet::play() switches to handle invalid choices
 * 2) Added feedback to the existing options in pet::play()
 * 3) Added an additional option to pet::play()
 * 4) Added "type" and "voice" members to pet, and an initialization for them in the constructor
 * 
 */

#include<iostream>
#include<string>

using namespace std;

string const hr = "* * * * * * * * * *";

class pet {
   private:          // private data members
      string type;
      string voice;
      string name;
      int hunger;
      int happiness;
   public:          // public member functions
      pet();                // constructor
      void play();
      void feed();
      void print();
      int check_health();
};

int main() {
   pet pet1;
   int choice;
   int health_check;
   do {
		 pet1.print();
		 cout << "What would you like to do with your pet?\n";
		 cout << " Play (1) \n Feed (2) \n Exit (0) \n";
		 cin >> choice;
		 switch(choice) {
		 	case 0:
		 		cout << "Goodbye!" << endl;
		 		break;
			case 1:
				pet1.play();
				break;
			case 2:
				pet1.feed();
				break;
			default:
				cout << "Your pet can't do that. Try something else." << endl;
		}
		health_check = pet1.check_health();
   } while(choice != 0 && health_check != 1);

   cout << endl << hr << endl << "Press enter to exit." << endl;
   cin.ignore();
   return 0;
}

/* Constructor, creates a new pet with starting values. */
pet::pet(){
     hunger = 50;
     happiness = 50;
     cout << hr << endl;
     cout << "What kind of pet is this (one word)? ";
     cin >> type;
     cin.ignore();
     cout << endl;
     cout << "What does a " << type << " say (one word)? ";
     cin >> voice;
     cout << "Please name your " << type << " (one word): ";
     cin >> name;
     cout << endl;
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
				cout << "\"Good " << type << ", " << name << ".\" " << voice << endl;
				happiness += 2;
				hunger += 0;
				break; 
			case 2:
				cout << voice << "! *tromp,tromp,tromp* ... *tromp,tromp,tromp* *pant* *pant*" << endl;
				happiness += 10;
				hunger += 12;
				break;
			case 3:
				cout << "\"Roll over, " << name << "!\" *roll*" << endl;
				happiness += 5;
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

/* Member function print(), prints information about a pet. */
void pet::print(){
    cout << endl << "~ Your " << type << ", " << name << " ~" << endl;
    cout << " Happiness: " << happiness << endl;
    cout << " Hunger: " << hunger << endl << hr << endl;
}

/* Member function check_health(), checks the health of a pet. */
int pet::check_health(){
	if(hunger >= 100){
		cout << voice << "!" << name << " has starved." << endl;
		return 1;
	}
	if(happiness <= 0){
		cout << name << " has died of a broken heart." << endl;
		return 1;
	}
	return 0;
}