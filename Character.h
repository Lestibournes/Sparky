#ifndef Character_h
#define Character_h

class Simulator;

//Defines a character in the simulation. This is not meant to be instantiated directly but is a base class for specific character types.
class Character {
	protected:
		//The number of steps each character is to take before changing direction:
		static const int MAX_STEPS = 17;
		
		//Steps counter:
		int steps;
		
		//A pointer to the simulation:
		Simulator * sim;
		
		//The dimensions of the bounding box for the character:
		int width;
		int height;
		
		//Current location:
		int location_x;
		int location_y;
		
		//Change in x and change in y in each step. Values can be -1, 0, or 1:
		int direction_x;
		int direction_y;
		
		//Whether the character is a friend or a stranger:
		int team;
		
		//Function for randomly changing the direction of the character:
		void changeDirection();

	public:
		//The constructor takes a pointer to the simulation as well as those of the character's bounding box:
		Character(Simulator * sim, int width, int height);
		
		//Uses ncurses to draw the character in its current location on the screen:
		virtual void draw() = 0;
		
		//Moves the character one step and randomly change direction if needed:
		void advance();
		
		//Changes the direction to the specified direction and then moves the character one step. If the character moved, return 1. If not, return 0:
		int advance(int direction_x, int direction_y);
		
		//Check for collision with an 'other' character:
		int collides(Character * other);
		
		//Change the team:
		void setTeam(int team);
		
		//Get the team:
		int getTeam();
		
		//Compare this team with another team (0 = different, 1 = same):
		int teamEquals(int other);
};

#endif
