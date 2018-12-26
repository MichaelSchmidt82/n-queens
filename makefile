all: main.cpp greedy_local.o
	g++ --std=c++11 main.cpp greedy_local.o -o greedy_local

greedy_local.o: greedy_local.cpp
	g++ --std=c++11 -c greedy_local.cpp -o greedy_local.o

genetic.o: n_queens_genetic.cpp individual.cpp
		g++ --std=c++11 -c n_queens_genetic.cpp individual.cpp -o n_queens_genetic.o


clean:
	rm *.o
	rm greedy_local
