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

#include "Simulator.h"

#include <cstdlib>
#include <iostream> 
#include <curses.h>
#include <chrono>
#include <thread>
#include <algorithm>

#include "Person.h"
#include "Dog.h"
#include "Text.h"

int Simulator::getHeight() {
	return LINES;
}
		
int Simulator::getWidth() {
	return COLS;
}

void Simulator::drawBoard() {
//Clear the screen of all previous scribbles:
clear();

///********** Characters ***************************************/


	//Iterate over all the strangers and draw them:
	for (unsigned int i = 0; i < characters.size(); i++) {
		if (characters[i]->teamEquals(strangers)) {
			//Set the color palette for strangers:
			attron(COLOR_PAIR(1));			
		}
		else if (characters[i]->teamEquals(friends)) {
			//Set the color palette for friends:
			attron(COLOR_PAIR(2));
		}
		
		characters[i]->draw();
	}
	
/********** Player **************************************/
	attron(COLOR_PAIR(3));
	player->draw();
	
	//Actually perform the drawing operation:
	refresh();
}

Simulator::Simulator() {
//	Initialize ncurses:
	initscr();
	start_color();
	noecho();
	cbreak();
//	raw();
	keypad(stdscr, TRUE);
	
//	Hide the cursor:
	curs_set(0);
	
//	Create color schemes in ncurses. 1 is for dogs, 2 for people, and 3 for simulation borders and UI:
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_YELLOW, COLOR_BLACK);
}

void Simulator::init() {
//	Initialize the player:
	player = new Dog(this);
	player->setTeam(players);
	
//	Choose a random number of dogs and people:
	num_dogs++;
	num_persons++;
	
//	Get rid of any previous content of the vectors:
	characters.erase(characters.begin(), characters.end());
	
//	Populate the vectors:
	for (int i = 0; i < num_dogs; i++) {
		Dog * dog = new Dog(this);
		dog->setTeam(strangers);
		characters.push_back(dog);
	}
	
	for (int i = 0; i < num_persons; i++) {
		Person * person = new Person(this);
		person->setTeam(strangers);
		characters.push_back(person);
	}
}

void Simulator::run() {
	int key;
	int next_key;
	
	int x = 0;
	int y = 0;
	
	init();
	
//	Draw the splash screen:
	attron(COLOR_PAIR(4));
	Text::drawTitle(getWidth(), getHeight());
	std::this_thread::sleep_for(std::chrono::milliseconds {pause/1});
	
//	Wait for player input. If the play presses the Esc key, exit:
	getCharBlocking(key);
	
	if (key == 27) {
		endwin();
		return;
	}
	
//	Draw the credit screen:
	attron(COLOR_PAIR(4));
	Text::drawCredits(getWidth(), getHeight());
	std::this_thread::sleep_for(std::chrono::milliseconds {pause/1});
	
//	Wait for player input. If the play presses the Esc key, exit:
	getCharBlocking(key);
	
	if (key == 27) {
		endwin();
		return;
	}
	
	attron(COLOR_PAIR(5));
	Text::drawLevel(num_persons, getWidth(), getHeight());
	std::this_thread::sleep_for(std::chrono::milliseconds {pause/1});
	
//	Wait for player input. If the play presses the Esc key, exit:
	getCharBlocking(key);
	
	if (key == 27) {
		endwin();
		return;
	}
	
//	Set input to not block:
	nodelay(stdscr,TRUE);

	
	//Main execution loop:
	while(1) {
		if (ended()) {
//			Start a new level:
			init();
			
//			Set the input to block:
			timeout(-1);
			
//			Draw the victory message:
			attron(COLOR_PAIR(5));	
			Text::drawLevel(num_persons, getWidth(), getHeight());
			std::this_thread::sleep_for(std::chrono::milliseconds {pause/1});
			
////			Wait for keypress:
//			flushinp();
//			key = getch();
			
			getCharBlocking(key);
			
			if (key == 27) {
				break;
			}
			
//			Set the input to not block:
			timeout(0);
			
//			Stop the player's movement:
			x = 0;
			y = 0;
		}
		
//		std::vector<Character *> changed;
		
//		Check for collisions between the player and the strangers:
		for (unsigned int i = 0; i < characters.size(); i++) {
			if (characters[i]->teamEquals(strangers) && characters[i]->collides(player)) {
//				changed.push_back(characters[i]);
				characters[i]->setTeam(friends);
			}
			else {
				for (unsigned int h = 0; h < characters.size(); h++) {
					if (	/*std::find(changed.begin(), changed.end(), characters[h]) != changed.end() &&*/
							characters[i]->teamEquals(strangers) &&
							characters[h]->collides(characters[i])) {
							
//						changed.push_back(characters[h]);
						characters[h]->setTeam(strangers);
					}
				}
			}
		}
		
//		Advance the characters:
		for (unsigned int i = 0; i < characters.size(); i++) {
			characters[i]->advance();
		}
		
//		Get the keyboard input and carry out the corresponding actions:
//		key = getch();
//		next_key = getch();
//		flushinp();
//		ungetch(next_key);

		getCharNotBlocking(key, next_key);
		
		if (key == 27) {
//			If the play presses the Esc key, exit:
			break;
		}
		else if (key == KEY_DOWN && next_key == KEY_LEFT) {
			x = -1;
			y = 1;
		}
		else if (key == KEY_DOWN && next_key == KEY_RIGHT) {
			x = 1;
			y = 1;
		}
		else if (key == KEY_UP && next_key == KEY_LEFT) {
			x = -1;
			y = -1;
		}
		else if (key == KEY_UP && next_key == KEY_RIGHT) {
			x = 1;
			y = -1;
		}
		else if (next_key == KEY_DOWN && key == KEY_LEFT) {
			x = -1;
			y = 1;
		}
		else if (next_key == KEY_DOWN && key == KEY_RIGHT) {
			x = 1;
			y = 1;
		}
		else if (next_key == KEY_UP && key == KEY_LEFT) {
			x = -1;
			y = -1;
		}
		else if (next_key == KEY_UP && key == KEY_RIGHT) {
			x = 1;
			y = -1;
		}
		else if (key == KEY_DOWN && next_key == ERR) {
			x = 0;
			y = 1;
		}
		else if (key == KEY_UP && next_key == ERR) {
			x = 0;
			y = -1;
		}
		else if (key == KEY_LEFT && next_key == ERR) {
			x = -1;
			y = 0;
		}
		else if (key == KEY_RIGHT && next_key == ERR) {
			x = 1;
			y = 0;
		}

		player->advance(x, y);
		
		//Render the simulation to the screen:
		drawBoard();
		
		std::this_thread::sleep_for(std::chrono::milliseconds {1000/30});
	}
	
//	When the main loop is broken, it's time to gracefully exit the program, and that means switching out of ncurses mode:
	endwin();
}

int Simulator::ended() {
	for (unsigned int i = 0; i < characters.size(); i++) {
		if (characters[i]->teamEquals(strangers)) {
			return 0;
		}
	}
	
	return 1;
}

void Simulator::getCharBlocking(int &c1) {
//	Set the input to block:
	timeout(-1);
	
//	Wait for keypress:
	c1 = getch();
}

void Simulator::getCharNotBlocking(int &c1, int &c2) {
//	Set the input to not block:
	timeout(0);
	
//	Fetch keypress:
	c1 = getch();
	c2 = getch();
}
