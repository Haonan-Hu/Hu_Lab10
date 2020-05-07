lab10: main.o Executive.o Disjoint.o Graph.o
	g++ -g -std=c++11 -Wall main.o Executive.o Graph.o Disjoint.o -o lab10

main.o: main.cpp Executive.h Executive.cpp Graph.h Graph.cpp Disjoint.h Disjoint.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Graph.h Graph.cpp Disjoint.h Disjoint.cpp
	g++ -g -std=c++11 -Wall -c Executive.cpp

Graph.o: Graph.h Graph.cpp Disjoint.h Disjoint.cpp
	g++ -g -std=c++11 -Wall -c Graph.cpp

Disjoint.o: Disjoint.h Disjoint.cpp Node.h
	g++ -g -std=c++11 -Wall -c Disjoint.cpp

clean:
	rm *.o lab10
