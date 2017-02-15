#include "Text.h"

#include <curses.h>

/* These global functions must be called only after curses mode has been initialized. They will clear the screen and display text */
void Text::drawLevel(int level, int width, int height) {
//	Clear the screen:
	clear();
	
	std::string c = "LEVEL";
	
//	The dimensions of the word (width no longer used):
	int word_height = 16;

//	The value of each digit in the number of the level:
	std::vector<int> digits = getDigits(level);
	
//	The width of each digit in the number of the level:
	std::vector<int> sizes = getDigitSizes(level);
	
//	The total width of the text on the screen:
	int totalWidth = getStringWidth(c);
	
	for (unsigned int i = 0; i < sizes.size(); i++) {
		totalWidth += space + sizes[i];
	}

//	Setting the x, y coordinates so that the word will be printed in the center of the screen:
	int x = width / 2 - (totalWidth / 2);
	int y = height / 2 - (word_height / 2);
	
	drawString(c + std::to_string(level), x, y);
	
//	Setting the x, y coordinates so that the numbers will be printed at the same height as the word immediately after it:
	y = height / 2 - (word_height / 2);
	x += getStringWidth(c) + space;
	
//	Draw the first digit:
//	drawDigit(digits[digits.size() - 1], x, y);
	
//	Iterate over and draw the rest of the digits:
	for (unsigned int i = digits.size(); i > 0; i--) {
		drawDigit(digits[i - 1], x, y);
		x += space + sizes[i - 1];
	}
	
//	Put our scribblings on the display:
	refresh();
}

/* This function is the exception to the rule as it does not clear the screen but instead adds text */
void Text::drawDigit(int digit, int x, int y) {
	if (digit == 1) {
		move(y++, x);
		addstr("  1111111");
		move(y++, x);
		addstr(" 1::::::1");
		move(y++, x);
		addstr("1:::::::1");
		move(y++, x);
		addstr("111:::::1");
		move(y++, x);
		addstr("   1::::1");
		move(y++, x);
		addstr("   1::::1");
		move(y++, x);
		addstr("   1::::1");
		move(y++, x);
		addstr("   1::::l");
		move(y++, x);
		addstr("   1::::l");
		move(y++, x);
		addstr("   1::::l");
		move(y++, x);
		addstr("   1::::l");
		move(y++, x);
		addstr("   1::::l");
		move(y++, x);
		addstr("111::::::111");
		move(y++, x);
		addstr("1::::::::::1");
		move(y++, x);
		addstr("1::::::::::1");
		move(y++, x);
		addstr("111111111111");
	}
	else if (digit == 2) {
		move(y++, x);
		addstr(" 222222222222222");
		move(y++, x);
		addstr("2:::::::::::::::22");
		move(y++, x);
		addstr("2::::::222222:::::2");
		move(y++, x);
		addstr("2222222     2:::::2");
		move(y++, x);
		addstr("            2:::::2");
		move(y++, x);
		addstr("            2:::::2");
		move(y++, x);
		addstr("         2222::::2");
		move(y++, x);
		addstr("    22222::::::22");
		move(y++, x);
		addstr("  22::::::::222");
		move(y++, x);
		addstr(" 2:::::22222");
		move(y++, x);
		addstr("2:::::2");
		move(y++, x);
		addstr("2:::::2");
		move(y++, x);
		addstr("2:::::2       222222");
		move(y++, x);
		addstr("2::::::2222222:::::2");
		move(y++, x);
		addstr("2::::::::::::::::::2");
		move(y++, x);
		addstr("22222222222222222222");
	}
	else if (digit == 3) {
		move(y++, x);
		addstr(" 333333333333333");
		move(y++, x);
		addstr("3:::::::::::::::33");
		move(y++, x);
		addstr("3::::::33333::::::3");
		move(y++, x);
		addstr("3333333     3:::::3");
		move(y++, x);
		addstr("            3:::::3");
		move(y++, x);
		addstr("            3:::::3");
		move(y++, x);
		addstr("    33333333:::::3");
		move(y++, x);
		addstr("    3:::::::::::3");
		move(y++, x);
		addstr("    33333333:::::3");
		move(y++, x);
		addstr("            3:::::3");
		move(y++, x);
		addstr("            3:::::3");
		move(y++, x);
		addstr("            3:::::3");
		move(y++, x);
		addstr("3333333     3:::::3");
		move(y++, x);
		addstr("3::::::33333::::::3");
		move(y++, x);
		addstr("3:::::::::::::::33");
		move(y++, x);
		addstr(" 333333333333333");
	}
	else if (digit == 4) {
		move(y++, x);
		addstr("       444444444");
		move(y++, x);
		addstr("      4::::::::4");
		move(y++, x);
		addstr("     4:::::::::4");
		move(y++, x);
		addstr("    4::::44::::4");
		move(y++, x);
		addstr("   4::::4 4::::4");
		move(y++, x);
		addstr("  4::::4  4::::4");
		move(y++, x);
		addstr(" 4::::4   4::::4");
		move(y++, x);
		addstr("4::::444444::::444");
		move(y++, x);
		addstr("4::::::::::::::::4");
		move(y++, x);
		addstr("4444444444:::::444");
		move(y++, x);
		addstr("          4::::4");
		move(y++, x);
		addstr("          4::::4");
		move(y++, x);
		addstr("          4::::4");
		move(y++, x);
		addstr("        44::::::44");
		move(y++, x);
		addstr("        4::::::::4");
		move(y++, x);
		addstr("        4444444444");
	}
	else if (digit == 5) {
		move(y++, x);
		addstr("555555555555555555");
		move(y++, x);
		addstr("5::::::::::::::::5");
		move(y++, x);
		addstr("5::::::::::::::::5");
		move(y++, x);
		addstr("5:::::555555555555");
		move(y++, x);
		addstr("5:::::5");
		move(y++, x);
		addstr("5:::::5");
		move(y++, x);
		addstr("5:::::5555555555");
		move(y++, x);
		addstr("5:::::::::::::::5");
		move(y++, x);
		addstr("555555555555:::::5");
		move(y++, x);
		addstr("            5:::::5");
		move(y++, x);
		addstr("            5:::::5");
		move(y++, x);
		addstr("5555555     5:::::5");
		move(y++, x);
		addstr("5::::::55555::::::5");
		move(y++, x);
		addstr(" 55:::::::::::::55");
   		move(y++, x);
		addstr("   55:::::::::55");
		move(y++, x);
		addstr("     555555555");
	}
	else if (digit == 6) {
		move(y++, x);
		addstr("        66666666");
		move(y++, x);
		addstr("       6::::::6");
		move(y++, x);
		addstr("      6::::::6");
		move(y++, x);
		addstr("     6::::::6");
		move(y++, x);
		addstr("    6::::::6");
		move(y++, x);
		addstr("   6::::::6");
		move(y++, x);
		addstr("  6::::::6");
		move(y++, x);
		addstr(" 6::::::::66666");
		move(y++, x);
		addstr("6::::::::::::::66");
		move(y++, x);
		addstr("6::::::66666:::::6");
		move(y++, x);
		addstr("6:::::6     6:::::6");
		move(y++, x);
		addstr("6:::::6     6:::::6");
		move(y++, x);
		addstr("6::::::66666::::::6");
		move(y++, x);
		addstr(" 66:::::::::::::66");
		move(y++, x);
		addstr("   66:::::::::66");
		move(y++, x);
		addstr("     666666666");
	}
	else if (digit == 7) {
		move(y++, x);
		addstr("77777777777777777777");
		move(y++, x);
		addstr("7::::::::::::::::::7");
		move(y++, x);
		addstr("7::::::::::::::::::7");
		move(y++, x);
		addstr("777777777777:::::::7");
		move(y++, x);
		addstr("           7::::::7");
		move(y++, x);
		addstr("          7::::::7");
		move(y++, x);
		addstr("         7::::::7");
		move(y++, x);
		addstr("        7::::::7");
		move(y++, x);
		addstr("       7::::::7");
		move(y++, x);
		addstr("      7::::::7");
		move(y++, x);
		addstr("     7::::::7");
		move(y++, x);
		addstr("    7::::::7");
		move(y++, x);
		addstr("   7::::::7");
		move(y++, x);
		addstr("  7::::::7");
 		move(y++, x);
		addstr("7::::::7");
		move(y++, x);
		addstr("77777777");
	}
	else if (digit == 8) {
		move(y++, x);
		addstr("     888888888");
		move(y++, x);
		addstr("   88:::::::::88");
		move(y++, x);
		addstr(" 88:::::::::::::88");
		move(y++, x);
		addstr("8::::::88888::::::8");
		move(y++, x);
		addstr("8:::::8     8:::::8");
		move(y++, x);
		addstr("8:::::8     8:::::8");
		move(y++, x);
		addstr(" 8:::::88888:::::8");
		move(y++, x);
		addstr("  8:::::::::::::8");
		move(y++, x);
		addstr(" 8:::::88888:::::8");
		move(y++, x);
		addstr("8:::::8     8:::::8");
		move(y++, x);
		addstr("8:::::8     8:::::8");
		move(y++, x);
		addstr("8:::::8     8:::::8");
		move(y++, x);
		addstr("8::::::88888::::::8");
		move(y++, x);
		addstr(" 88:::::::::::::88");
		move(y++, x);
		addstr("   88:::::::::88");
		move(y++, x);
		addstr("     888888888");
	}
	else if (digit == 9) {
		move(y++, x);
		addstr("     999999999");
		move(y++, x);
		addstr("   99:::::::::99");
		move(y++, x);
		addstr(" 99:::::::::::::99");
		move(y++, x);
		addstr("9::::::99999::::::9");
		move(y++, x);
		addstr("9:::::9     9:::::9");
		move(y++, x);
		addstr("9:::::9     9:::::9");
		move(y++, x);
		addstr(" 9:::::99999::::::9");
		move(y++, x);
		addstr("  99::::::::::::::9");
		move(y++, x);
		addstr("    99999::::::::9");
		move(y++, x);
		addstr("         9::::::9");
		move(y++, x);
		addstr("        9::::::9");
		move(y++, x);
		addstr("       9::::::9");
		move(y++, x);
		addstr("      9::::::9");
		move(y++, x);
		addstr("     9::::::9");
		move(y++, x);
		addstr("    9::::::9");
		move(y++, x);
		addstr("   99999999");
	}
	else if (digit == 0) {
		move(y++, x);
		addstr("     000000000");
		move(y++, x);
		addstr("   00:::::::::00");
		move(y++, x);
		addstr(" 00:::::::::::::00");
		move(y++, x);
		addstr("0:::::::000:::::::0");
		move(y++, x);
		addstr("0::::::0   0::::::0");
		move(y++, x);
		addstr("0:::::0     0:::::0");
		move(y++, x);
		addstr("0:::::0     0:::::0");
		move(y++, x);
		addstr("0:::::0 000 0:::::0");
		move(y++, x);
		addstr("0:::::0 000 0:::::0");
		move(y++, x);
		addstr("0:::::0     0:::::0");
		move(y++, x);
		addstr("0:::::0     0:::::0");
		move(y++, x);
		addstr("0::::::0   0::::::0");
		move(y++, x);
		addstr("0:::::::000:::::::0");
		move(y++, x);
		addstr(" 00:::::::::::::00");
		move(y++, x);
		addstr("   00:::::::::00");
		move(y++, x);
		addstr("     000000000");
	 }
}

/* This function is the exception to the rule as it does not clear the screen but instead adds text */
void Text::drawChar(char c, int x, int y) {
	if (c == 'L') {
		move(y++, x);
		addstr("LLLLLLLLLLL");
		move(y++, x);
		addstr("L:::::::::L");
		move(y++, x);
		addstr("L:::::::::L");
		move(y++, x);
		addstr("LL:::::::LL");
		move(y++, x);
		addstr("  L:::::L");
		move(y++, x);
		addstr("  L:::::L");
		move(y++, x);
		addstr("  L:::::L");
		move(y++, x);
		addstr("  L:::::L");
		move(y++, x);
		addstr("  L:::::L");
		move(y++, x);
		addstr("  L:::::L");
		move(y++, x);
		addstr("  L:::::L");
		move(y++, x);
		addstr("  L:::::L         LLLLLL");
		move(y++, x);
		addstr("LL:::::::LLLLLLLLL:::::L");
		move(y++, x);
		addstr("L::::::::::::::::::::::L");
		move(y++, x);
		addstr("L::::::::::::::::::::::L");
		move(y++, x);
		addstr("LLLLLLLLLLLLLLLLLLLLLLLL");
	}
	else if (c == 'E') {
		move(y++, x);
		addstr("EEEEEEEEEEEEEEEEEEEEEE");
		move(y++, x);
		addstr("E::::::::::::::::::::E");
		move(y++, x);
		addstr("E::::::::::::::::::::E");
		move(y++, x);
		addstr("EE::::::EEEEEEEEE::::E");
		move(y++, x);
		addstr("  E:::::E       EEEEEE");
		move(y++, x);
		addstr("  E:::::E");
		move(y++, x);
		addstr("  E::::::EEEEEEEEEE");
		move(y++, x);
		addstr("  E:::::::::::::::E");
		move(y++, x);
		addstr("  E:::::::::::::::E");
		move(y++, x);
		addstr("  E::::::EEEEEEEEEE");
		move(y++, x);
		addstr("  E:::::E");
		move(y++, x);
		addstr("  E:::::E       EEEEEE");
		move(y++, x);
		addstr("EE::::::EEEEEEEE:::::E");
		move(y++, x);
		addstr("E::::::::::::::::::::E");
		move(y++, x);
		addstr("E::::::::::::::::::::E");
		move(y++, x);
		addstr("EEEEEEEEEEEEEEEEEEEEEE");
	}
	else if (c == 'V') {
		move(y++, x);
		addstr("VVVVVVVV           VVVVVVVV");
		move(y++, x);
		addstr("V::::::V           V::::::V");
		move(y++, x);
		addstr("V::::::V           V::::::V");
		move(y++, x);
		addstr("V::::::V           V::::::V");
		move(y++, x);
		addstr(" V:::::V           V:::::V");
		move(y++, x);
		addstr("  V:::::V         V:::::V");
		move(y++, x);
		addstr("   V:::::V       V:::::V");
		move(y++, x);
		addstr("    V:::::V     V:::::V");
		move(y++, x);
		addstr("     V:::::V   V:::::V");
		move(y++, x);
		addstr("      V:::::V V:::::V");
		move(y++, x);
		addstr("       V:::::V:::::V");
		move(y++, x);
		addstr("        V:::::::::V");
		move(y++, x);
		addstr("         V:::::::V");
		move(y++, x);
		addstr("          V:::::V");
		move(y++, x);
		addstr("           V:::V");
		move(y++, x);
		addstr("            VVV");
	}
}

int Text::getDigitWidth(int digit) {
	if (digit == 1) {
		return 12;
	}
	else if (digit == 2) {
		return 20;
	}
	else if (digit == 3) {
		return 19;
	}
	else if (digit == 4) {
		return 18;
	}
	else if (digit == 5) {
		return 19;
	}
	else if (digit == 6) {
		return 20;
	}
	else if (digit == 7) {
		return 20;
	}
	else if (digit == 8) {
		return 19;
	}
	else if (digit == 9) {
		return 19;
	}
	else if (digit == 0) {
		return 19;
	}
	
	return 0;
}

int Text::getCharWidth(char c) {
	if (c == 'L') {
		return 24;
	}
	else if (c == 'E') {
		return 22;
	}
	else if (c == 'V') {
		return 27;
	}
	
	return 0;
}

void Text::drawString(std::string c, int x, int y) {
	for (int i = 0; c[i]; i++) {
		drawChar(c[i], x, y);
		
		if (c[i + 1]) {
			x += getCharWidth(c[i]) + space;
		}
		else {
			x += getCharWidth(c[i]);
		}
	}
}

int Text::getStringWidth(std::string c) {
	int width = 0;
	
	for (int i = 0; c[i]; i++) {
		if (c[i + 1]) {
			width += getCharWidth(c[i]) + space;
		}
		else {
			width += getCharWidth(c[i]);
		}
	}
	
	return width;
}

std::vector<int> Text::getDigitSizes(int number) {
//	The width of each digit in the number of the level:
	std::vector<int> sizes;
	
//	Temporarily stores the digit while we get the individual digits out of the number of the level:
	int digit;
	
//	Keep looping until there are no digits left to extract:
	do {
//		Using modulus to get individual digits:
		digit = number % 10;
		
//		Storing the digit's width:
		sizes.push_back(getDigitWidth(digit));
		
//		Preparing temp for the next iteration:
		number = number / 10;
	} while (number != 0);
	
	return sizes;
}

std::vector<int> Text::getDigits(int number) {
//	The value of each digit in the number of the level:
	std::vector<int> digits;
	
//	Temporarily stores the digit while we get the individual digits out of the number of the level:
	int digit;
	
//	Keep looping until there are no digits left to extract:
	do {
//		Using modulus to get individual digits:
		digit = number % 10;
		
//		Storing the digit:
		digits.push_back(digit);
		
//		Preparing temp for the next iteration:
		number = number / 10;
	} while (number != 0);
	
	return digits;
}

void Text::drawTitle(int width, int height) {
	clear();
	int x = width / 2 - (96 / 2);
	int y = height / 2 - (10 / 2);
	
	//96 wide, 10 high
	//Broadway fornt on patorjk.com
	move(y++, x);
	addstr("   d888888o.   8 888888888o      .8.          8 888888888o.   8 8888     ,88' `8.`8888.      ,8'");
	move(y++, x);
	addstr(" .`8888:' `88. 8 8888    `88.   .888.         8 8888    `88.  8 8888    ,88'   `8.`8888.    ,8' ");
	move(y++, x);
	addstr(" 8.`8888.   Y8 8 8888     `88  :88888.        8 8888     `88  8 8888   ,88'     `8.`8888.  ,8'  ");
	move(y++, x);
	addstr(" `8.`8888.     8 8888     ,88 . `88888.       8 8888     ,88  8 8888  ,88'       `8.`8888.,8'   ");
	move(y++, x);
	addstr("  `8.`8888.    8 8888.   ,88'.8. `88888.      8 8888.   ,88'  8 8888 ,88'         `8.`88888'    ");
	move(y++, x);
	addstr("   `8.`8888.   8 888888888P'.8`8. `88888.     8 888888888P'   8 8888 88'           `8. 8888     ");
	move(y++, x);
	addstr("    `8.`8888.  8 8888      .8' `8. `88888.    8 8888`8b       8 888888<             `8 8888     ");
	move(y++, x);
	addstr("8b   `8.`8888. 8 8888     .8'   `8. `88888.   8 8888 `8b.     8 8888 `Y8.            8 8888     ");
	move(y++, x);
	addstr("`8b.  ;8.`8888 8 8888    .888888888. `88888.  8 8888   `8b.   8 8888   `Y8.          8 8888     ");
	move(y, x);
	addstr(" `Y8888P ,88P' 8 8888   .8'       `8. `88888. 8 8888     `88. 8 8888     `Y8.        8 8888     ");
	
	refresh();
}

void Text::drawCredits(int width, int height) {
	clear();
	int x = width / 2 - (73 / 2);
	int y = 2;
	
	move(y++, x);
	addstr(" .d8888b.  8888888b.  8888888888 8888888b. 8888888 88888888888 .d8888b.  ");
	move(y++, x);
	addstr("d88P  Y88b 888   Y88b 888        888  \"Y88b  888       888    d88P  Y88b ");
	move(y++, x);
	addstr("888    888 888    888 888        888    888  888       888    Y88b.      ");
	move(y++, x);
	addstr("888        888   d88P 8888888    888    888  888       888     \"Y888b.   ");
	move(y++, x);
	addstr("888        8888888P\"  888        888    888  888       888        \"Y88b. ");
	move(y++, x);
	addstr("888    888 888 T88b   888        888    888  888       888          \"888 ");
	move(y++, x);
	addstr("Y88b  d88P 888  T88b  888        888  .d88P  888       888    Y88b  d88P ");
	move(y++, x);
	addstr(" \"Y8888P\"  888   T88b 8888888888 8888888P\" 8888888     888     \"Y8888P\"  ");
	
	move(y++, x);
	move(y++, x);
	
	x = width / 2 - (7 / 2);
	
	move(y++, x + 1);
	addstr("/^^^\\");
	move(y++, x);
	addstr("/ . . \\");
	move(y++, x);
	addstr("V\\ Y /V");
	move(y++, x + 1);
	addstr("/ - \\");
	move(y++, x + 1);
	addstr("|    \\");
	move(y++, x + 1);
	addstr("||(__V");
	
	x = width / 2 - (25 / 2);
	
	move(y++, x);
	move(y++, x);
	addstr("http://www.asciiworld.com");
	
	move(y++, x);
	move(y++, x);
	
	x = width / 2 - (12 / 2);
	
	move(y++, x + 4);
	addstr("/:\"\"|");
	move(y++, x + 3);
	addstr("|:`66|_");
	move(y++, x + 3);
	addstr("C`    _)");
	move(y++, x + 4);
	addstr("\\ ._|");
	move(y++, x + 5);
	addstr(") /");
	move(y++, x + 4);
	addstr("/`\\\\");
	move(y++, x + 3);
	addstr("|| |Y|");
	move(y++, x + 3);
	addstr("|| |#|");
	move(y++, x + 3);
	addstr("|| |#|");
	move(y++, x + 3);
	addstr("|| |#|");
	move(y++, x + 3);
	addstr(":| |=:");
	move(y++, x + 3);
	addstr("||_|,|");
	move(y++, x + 3);
	addstr("\\)))||");
	move(y++, x);
	addstr("|~~~`-`~~~|");
	move(y++, x);
	addstr("|         |");
	move(y++, x);
	addstr("|_________|");
	move(y++, x);
	addstr("|_________|");
	move(y++, x + 4);
	addstr("| ||");
	move(y++, x + 4);
	addstr("|_||__");
	move(y++, x - 1);
	addstr("jgs  (____))");
	
	x = width / 2 - (25 / 2);
	
	move(y++, x);
	move(y++, x);
	addstr("http://www.asciiworld.com");
	
	x = width / 2 - (46 / 2);
	
	move(y++, x);
	move(y++, x);
	move(y++, x);
	move(y++, x);
	addstr("ASCII Fonts: http://patorjk.com/software/taag/");
	
	x = width / 2 - (41 / 2);
	
	move(y++, x);
	move(y++, x);
	move(y++, x);
	move(y++, x);
	addstr("This game was created by Yitzchak Schwarz");
	
	refresh();
}
