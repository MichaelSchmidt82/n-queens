all: main.cpp greedy_local.o genetic.o individual.o recursive.o
	g++ --std=c++11 main.cpp greedy_local.o genetic.o individual.o recursive.o -o n_queens

recursive.o: recursive.cpp
	g++ --std=c++11 -c recursive.cpp -o recursive.o

greedy_local.o: greedy_local.cpp
	g++ --std=c++11 -c greedy_local.cpp -o greedy_local.o

genetic.o, individual.o: genetic.cpp individual.cpp
	g++ --std=c++11 -c genetic.cpp individual.cpp

clean:
	rm *.o
	rm n_queens
