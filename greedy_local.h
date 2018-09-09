#ifndef GREEDY_LOCAL_H
#define GREEDY_LOCAL_H

#include "globals.h"

class GreedyLocal {

public:
    GreedyLocal(int _n, int seed) : n(_n), board(nullptr) {
        initialize();
        srand(seed);
    };
    ~GreedyLocal();

    void solve();
    void print();


private:
    /* variables */
    int n;
    Board board;
    Locations queens;
    Locations minimums;

    void initialize();
    void update();

    int findLowest();
    void placeLowest();

    int heuristicFunction(pair<int, int>);
    bool is_solution();
};
#endif
