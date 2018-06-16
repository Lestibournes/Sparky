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

#ifndef Simulator_h
#define Simulator_h

#include <vector>

class Character;
class Dog;
class Person;

//Creates and runs the simulation
class Simulator {
	private:
//		Number of characters:
		int num_dogs;
		int num_persons;
	
//		Draws the board:
		void drawBoard();

//		Draws the splash screen:
		void drawSplash();
		
//		The queue of characters:
		std::vector<Character *> characters;
		
//		The player character:
		Dog * player;
		
		void getCharBlocking(int &c1);
		void getCharNotBlocking(int &c1, int &c2);
		
//		How long to pause after showing a splash screen before accepting player input:
		static const int pause = 1000;
		
//		The number values for the teams:
		static const int players = 0;
		static const int strangers = 1;
		static const int friends = 2;
		
	public:
//		The hight of the simulation area:
		int getHeight();
		
//		The width of the simulation area:
		int getWidth();
		
//		Constructor. What else is there to say?
		Simulator();
		
//		Set up a new game:
		void init();
		
//		Runs the simulation:
		void run();
		
		//Check if the game reached its end:
		int ended();
};

#endif
