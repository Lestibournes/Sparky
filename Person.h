#ifndef Person_h
#define Person_h

#include "Character.h"

//Defines a character of type person:
class Person : public Character {
	public:
//		The constructor takes a pointer to the simulation area:
		Person(Simulator * sim);
		
//		Uses ncurses to draw the character in its current location on the screen:
		void draw();
};

#endif
