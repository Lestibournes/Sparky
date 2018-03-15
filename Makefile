sparky: main.cc Simulator.o Text.o Dog.o Person.o Character.o
	$(CXX) -Wall main.cc Simulator.o Text.o Dog.o Person.o Character.o -l ncurses -o $@

main.o: main.cc
	$(CXX) -c -Wall main.cc -o $@

Simulator.o: Simulator.cc Simulator.h Text.o Dog.o Person.o
	$(CXX) -c -Wall Simulator.cc -std=c++11 -o $@

Text.o: Text.cc Text.h
	$(CXX) -c -Wall Text.cc -std=c++11 -o $@

Dog.o: Dog.cc Dog.h Character.o
	$(CXX) -c -Wall Dog.cc -o $@

Person.o: Person.cc Person.h Character.o
	$(CXX) -c -Wall Person.cc -o $@

Character.o: Character.cc Character.h
	$(CXX) -c -Wall Character.cc -o $@

clean:
	rm -f sparky *.o

install:
	mv sparky ../install/sparky
