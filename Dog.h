#ifndef Dog_h
#define Dog_h

#include "Character.h"

//Defines a character of type dog:
class Dog : public Character {
	public:
//		The constructor takes the width and height of the simulation area:
		Dog(Simulator * sim);
		
//		Uses ncurses to draw the character in its current location on the screen:
		void draw();
};

#endif
