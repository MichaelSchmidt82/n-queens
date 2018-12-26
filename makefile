all: main.cpp greedy_local.o genetic.o
	g++ --std=c++11 main.cpp greedy_local.o genetic.o -o n_queens

greedy_local.o: greedy_local.cpp
	g++ --std=c++11 -c greedy_local.cpp -o greedy_local.o

genetic.o: genetic.cpp
		g++ --std=c++11 -c genetic.cpp 


clean:
	rm *.o
	rm n_queens
