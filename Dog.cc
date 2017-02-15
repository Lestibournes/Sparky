#include "Dog.h"

#include <iostream>
#include <curses.h>

//The dog's constructer calls the base class constructor and provides it with the bounding box dimensions:
Dog::Dog(Simulator * sim) : Character(sim, 7, 6) {}

void Dog::draw() {
//	I'm drawing ascii art, so for each line I need to set the height of the line and the starting point on that line:
	
	move(location_y, location_x + 1);
	addstr("/^^^\\");
	move(location_y + 1, location_x);
	addstr("/ . . \\");
	move(location_y + 2, location_x);
	addstr("V\\ Y /V");
	move(location_y + 3, location_x + 1);
	addstr("/ - \\");
	move(location_y + 4, location_x + 1);
	addstr("|    \\");
	move(location_y + 5, location_x + 1);
	addstr("||(__V");
}
