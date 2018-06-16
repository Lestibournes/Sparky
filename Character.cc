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

#include "Character.h"

#include <cstdlib>

#include "Simulator.h"

using namespace std;

Character::Character(Simulator * sim, int width, int height) {
//	Save the dimensions of the simulation area:
	this->sim = sim;
	
//	Save the dimentions of this character's bounding box:
	this->width = width;
	this->height = height;
	
//	Set a random starting point:
	location_x = rand() % (sim->getWidth() - width);
	location_y = rand() % (sim->getHeight() - height);

//	Initialize current number of steps to 0:
	steps = 0;
	
//	Set a random initial direction:
	changeDirection();
}

void Character::changeDirection() {
//	TODO this function can theoretically choose a new direction that is identical to the old direction.

//	Choose a new direction, but make sure that the new direction isn't to stay in place:
	do {
		direction_x = rand() % 3 - 1;
		direction_y = rand() % 3 - 1;
	} while (direction_x == 0 && direction_y == 0);
}

void Character::advance() {
	if (advance(direction_x, direction_y)) {
		steps++;
		
		//If 17 or more steps have already been performed, change the direction and reset the steps counter:
		if (steps > MAX_STEPS) {
			changeDirection();
			steps = 0;
		}
	}
	
	else {
		//If it's not in bounds, choose a new direction:
		changeDirection();
	}
}

int Character::advance(int direction_x, int direction_y) {
	this->direction_x = direction_x;
	this->direction_y = direction_y;
	
	//Check where the character's next step will take it:
	int next_x = location_x + direction_x;
	int next_y = location_y + direction_y;
	
	//Check that the next step is in bounds, while taking the character's size as well as location into account:
	if (next_x >= 0 && (next_x + width) <= sim->getWidth() && next_y >= 0 && (next_y + height) <= sim->getHeight()) {
		//If it's in bounds, perform the step:
		location_x = next_x;
		location_y = next_y;
		
		return 1;
	}
	else {
		return 0;
	}	
}

int Character::collides(Character * other) {
	if (	location_x < other->location_x + other->width &&
			location_x + width > other->location_x &&
			location_y < other->location_y + other->height &&
			location_y + height > other->location_y) {
		return 1;
	}
	else {
		return 0;
	}
}

//Change the team:
void Character::setTeam(int team) {
	this->team = team;
}

//Get the team:
int Character::getTeam() {
	return team;
}

//Compare this team with another team (0 = different, 1 = same):
int Character::teamEquals(int other) {
	if (team == other) {
		return 1;
	}
	else {
		return 0;
	}
}
