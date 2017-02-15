#include <iostream>
#include <cstdlib>

#include "Simulator.h"

using namespace std;

int main(int argc, char ** argv) {
//	Seed the random number generator with the current time:
	srand(time(NULL));
	
//	Create and start the simulation:
	Simulator * sim = new Simulator();
	sim->run();
}
