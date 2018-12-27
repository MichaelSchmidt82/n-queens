#include "globals.h"
#include "queens_base.h"
#include "greedy_local.h"
#include "recursive.h"
#include "genetic.h"

int main() {

    QueensBase* recursive = new Recursive(8);
    QueensBase* genetic = new Genetic(8);
    QueensBase* greedy = new GreedyLocal(8);

    cout << "Recursive:" << endl;
    recursive->solve();
    recursive->print();

    cout << "Genetic:" << endl;
    genetic->solve();
    genetic->print();

    cout << "Greedy Local:" << endl;
    greedy->solve();
    greedy->print();





    return 0;
}
