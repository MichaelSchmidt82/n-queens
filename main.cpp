#include "globals.h"
#include "queens_base.h"
#include "greedy_local.h"
#include "recursive.h"
#include "genetic.h"

int main(int argc, char* argv[]) {

    assert(argc == 3 && "supply SEED and N");
    srand(atoi(argv[1]));

    int N = atoi(argv[2]);

    QueensBase* recursive = new Recursive(N);
    QueensBase* genetic = new Genetic(N);
    QueensBase* greedy = new GreedyLocal(N);

    cout << "Recursive:" << endl;
    recursive->solve();
    recursive->print();
    cout << endl;

    cout << "Greedy Local:" << endl;
    greedy->solve();
    greedy->print();
    cout << endl;

    cout << "Genetic:" << endl;
    genetic->solve();
    genetic->print();
    cout << endl;

    return 0;
}
