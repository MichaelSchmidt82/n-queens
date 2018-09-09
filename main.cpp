#include "globals.h"
#include "greedy_local.h"
#include "recursive.h"

int main() {

    Recursive* rec = new Recursive(18);

    rec->solve();
    rec->print();

    return 0;
}
