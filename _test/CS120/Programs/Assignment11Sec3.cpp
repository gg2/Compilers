/*
 * Robots: Linked Lists
 *
 * Gabe Gibler
 * CS120-03
 * Assignment #11
 *
 * 2a) Modified turnLeft (made it specific to a single node, same as most of the other robot methods).
 *    And correspondingly changed the usage of it below.
 * 2b) Added usages of the other methods added to linkedlist and node.
 * 
 * 4) Oh. I did that for #2, except I made all functions seek specified robots. However, for a method that does still target all robots, see refresh_all().
 * 
 * 5) I verify that get() works by semi-randomly asking for a robot 
 *    (since the new robot's id was not actually assigned sequentially, I can't quite get to it with a truly random request, as is).
 */

#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;

#include"robot.h"
#include"node.h"
#include"linkedlist.h"

string const hr = "* * * * * * * * * *";

void div();

int main() {
	linkedlist ll;
	const int num_robots = 3;
	robot *robot_ptr;
	int x,y;
	robot *instance;

	srand(time(NULL));
	
	div();
	
	for(int i=0; i < num_robots; i++) {
		robot_ptr = new robot(i);
		ll.insert(robot_ptr);
	}
	ll.print();
	cout << "Turn all robots left: " << endl;
	for (int i=0; i < num_robots; i++) {
		ll.turnLeft(i);
	}
	cout << "Now, turn all robots right: " << endl;
	for (int i=0; i < num_robots; i++) {
		ll.turnRight(i);
	}
	cout << "Take a step back: " << endl;
	for (int i=0; i < num_robots; i++) {
		x = y = ll.meter(i);
		ll.reverse(i,x,y);
	}
	cout << "And curtsy: " << endl;
	ll.refresh_all();
	ll.print();
	div();
	
	cout << "Inserting a new robot (and removing an existing one): " << endl;
	robot_ptr = new robot(x);
	ll.insert(robot_ptr);
	ll.remove(2);
	ll.print();
	div();
	
	cout << "Energize the new robot: " << endl;
	// x,y are just being used for fun, to see what's in them after messing around...
	ll.energize(x,y);
	
	cout << endl << "Now, select a random robot and ask it to say \"hi\": " << endl;
	y = rand() % ll.getCount();
	if (y < 2)
		x = y;
	if (ll.getCount() > 0) {
		instance = ll.get(x);
		if (instance != NULL) 
			cout << "\"Hello. I am robot number " << instance -> getID() << ". \nMy serial number is " << instance << ". \nI am pleased to make your acquaintance.\"" << endl;
		else
			cout << "The targeted robot did not exist!" << endl;
	} else {
		cout << "Except, no robots exist in the list!" << endl;
	}
	div();
	
	return 0;
}

// Print a visual divider for textual output
void div() {
	cout << endl << hr << endl;
}
