#include "globals.h"
#include "greedy_local.h"

int main() {

    GreedyLocal* greedy_local =  new GreedyLocal(8, 8);

    greedy_local->solve();
    greedy_local->print();

    return 0;
}
