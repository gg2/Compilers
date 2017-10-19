/*
 * Robot World
 *
 * Gabe Gibler
 * CS120-03
 * Assignment #10
 * 
 * 
 * 
 */

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

#include"robot.h"
#include"terrain.h"
#include"world.h"

int main() {

	srand(time(NULL));

	world robot_world;
	
	robot_world.set_up();

	do {
		robot_world.draw();
		robot_world.update();
		cin.ignore();
	} while(1);

	cin.ignore();
	cout << "Press enter to exit..." << endl;
	cin.ignore();
	return 0;
}