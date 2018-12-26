#include "globals.h"
#include "greedy_local.h"
#include "recursive.h"
#include "genetic.h"

int main() {

    Recursive* rec = new Recursive(18);
    Genetic* gen = new Genetic(18);

    rec->solve();
    rec->print();

    gen->solve();
    gen->print();



    return 0;
}
