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

#include "Person.h"

#include <iostream>
#include <curses.h>

//The person's constructer calls the base class constructor and provides it with the bounding box dimensions:
Person::Person(Simulator * sim) : Character(sim, 11, 20) {}

void Person::draw() {
//	I'm drawing ascii art, so for each line I need to set the height of the line and the starting point on that line:
	move(location_y, location_x + 4);
	addstr("/:\"\"|");
	move(location_y + 1, location_x + 3);
	addstr("|:`66|_");
	move(location_y + 2, location_x + 3);
	addstr("C`    _)");
	move(location_y + 3, location_x + 4);
	addstr("\\ ._|");
	move(location_y + 4, location_x + 5);
	addstr(") /");
	move(location_y + 5, location_x + 4);
	addstr("/`\\\\");
	move(location_y + 6, location_x + 3);
	addstr("|| |Y|");
	move(location_y + 7, location_x + 3);
	addstr("|| |#|");
	move(location_y + 8, location_x + 3);
	addstr("|| |#|");
	move(location_y + 9, location_x + 3);
	addstr("|| |#|");
	move(location_y + 10, location_x + 3);
	addstr(":| |=:");
	move(location_y + 11, location_x + 3);
	addstr("||_|,|");
	move(location_y + 12, location_x + 3);
	addstr("\\)))||");
	move(location_y + 13, location_x);
	addstr("|~~~`-`~~~|");
	move(location_y + 14, location_x);
	addstr("|         |");
	move(location_y + 15, location_x);
	addstr("|_________|");
	move(location_y + 16, location_x);
	addstr("|_________|");
	move(location_y + 17, location_x + 4);
	addstr("| ||");
	move(location_y + 18, location_x + 4);
	addstr("|_||__");
	move(location_y + 19, location_x + 4);
	addstr("(____))");
}
