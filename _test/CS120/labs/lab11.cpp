/*
 * Robot World
 *
 * Gabe Gibler
 * CS120-03
 * Lab #11
 * 
 * *) See world.h for changes...
 */

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

#include"robot.h"
#include"world.h"

int main() {

	srand(time(NULL));

	world robot_world;
	
	robot_world.set_up();

	do {
		robot_world.update();
		robot_world.draw();
		cin.ignore();
	} while(1);

	cin.ignore();
	cout << "Press enter to exit..." << endl;
	cin.ignore();
	return 0;
}