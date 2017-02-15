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
	
//		The hight of the simulation area:
		int _rows;
		
//		The width of the simulation area:
		int _cols;
		
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
