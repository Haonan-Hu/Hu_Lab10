lab10A: main.o Executive.o Disjoint.o
	g++ -g -std=c++11 -Wall main.o Executive.o Disjoint.o -o lab10A

main.o: main.cpp Executive.h Executive.cpp Disjoint.h Disjoint.cpp
	g++ -g -std=c++11 -Wall -c main.cpp

Executive.o: Executive.h Executive.cpp Disjoint.h Disjoint.cpp
	g++ -g -std=c++11 -Wall -c Executive.cpp

Disjoint.o: Disjoint.h Disjoint.cpp Node.h
	g++ -g -std=c++11 -Wall -c Disjoint.cpp

clean:
	rm *.o lab10A
