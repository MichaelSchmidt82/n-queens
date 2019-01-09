#include "globals.h"
#include "queens_base.h"
#include "greedy_local.h"
#include "depth_first.h"
#include "genetic.h"

#include <chrono>

int main(int argc, char* argv[]) {

	//assert(argc == 3 && "supply SEED and N");
	srand(atoi(argv[1]));

	int N = atoi(argv[2]);

	QueensBase* depth_first = new DepthFirstSearch(N);
	//auto start = std::chrono::high_resolution_clock::now();
	QueensBase* genetic = new GeneticSearch(N);
	QueensBase* greedy = new GreedyLocal(N);

	cout << "Depth First Search:" << endl;
	depth_first->solve();
	depth_first->print();
	cout << endl;

	cout << "Greedy Local Search:" << endl;
	greedy->solve();
	greedy->print();
	cout << endl;

	cout << "Genetic Search:" << endl;
	genetic->solve();
	//auto stop = std::chrono::high_resolution_clock::now();
	//auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
	//cout << "duration:" << duration.count() << endl;
	genetic->print();
	cout << endl;

	return 0;
}
