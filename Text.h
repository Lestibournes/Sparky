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

#ifndef Text_h
#define Text_h

#include <vector>
#include <string>

/* These global functions must be called only after curses mode has been initialized. They will clear the screen and display text */
namespace Text {
//	The amount of space to put between chracters:	
	const int space = 2;
	void drawLevel(int level, int width, int height);

	/* This function is the exception to the rule as it does not clear the screen but instead adds text */
	void drawDigit(int digit, int x, int y);
	int getDigitWidth(int digit);
	
	void drawChar(char c, int x, int y);
	int getCharWidth(char c);
	
	void drawString(std::string c, int x, int y);
	int getStringWidth(std::string c);
	
//	Takes a number and returns a vector containing the width of each of its digits in the ascii font:
	std::vector<int> getDigitSizes(int number);
	
//	Takes a number and returns a vector containing its individual digits:
	std::vector<int> getDigits(int number);
	
//	Draw the title splash screen:
	void drawTitle(int width, int height);
	
//	Draw the credit screen:
	void drawCredits(int width, int height);
}

#endif
