main: main.cc Simulator.o Text.o Dog.o Person.o Character.o
	g++ -Wall main.cc Simulator.o Text.o Dog.o Person.o Character.o -l ncurses -o Sparky

main.o: main.cc
	g++ -c -Wall main.cc -o main.o

Simulator.o: Simulator.cc Simulator.h Text.o Dog.o Person.o
	g++ -c -Wall Simulator.cc -std=c++11 -o Simulator.o

Text.o: Text.cc Text.h
	g++ -c -Wall Text.cc -std=c++11 -o Text.o

Dog.o: Dog.cc Dog.h Character.o
	g++ -c -Wall Dog.cc -o Dog.o

Person.o: Person.cc Person.h Character.o
	g++ -c -Wall Person.cc -o Person.o

Character.o: Character.cc Character.h
	g++ -c -Wall Character.cc -o Character.o

link: main.o Simulator.o Dog.o Person.o Character.o
	ld main.o Simulator.o Dog.o Person.o Character.o -l ncurses -o link

clean:
	rm *.o
