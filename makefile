all: main.cpp greedy_local.o genetic.o individual.o depth_first.o
	g++ --std=c++11 main.cpp greedy_local.o genetic.o individual.o depth_first.o -o n_queens

depth_first.o: depth_first.cpp
	g++ --std=c++11 -c depth_first.cpp -o depth_first.o

greedy_local.o: greedy_local.cpp
	g++ --std=c++11 -c greedy_local.cpp -o greedy_local.o

genetic.o, individual.o: genetic.cpp individual.cpp
	g++ --std=c++11 -c genetic.cpp individual.cpp

clean:
	rm *.o
	rm n_queens
