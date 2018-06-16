/**

    Sparky - A little game about a dog that is trying to make friends
    Copyright (C) 2017  Gerald Isaac Schwarz

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License version 2.0 only,
    as published by the Free Software Foundation.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

**/

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
