#ifndef RECURSIVE_H
#define RECURSIVE_H

#include "globals.h"

class Recursive {

public:
    Recursive(int _n) : n(_n), board(nullptr) {
        initialize();
        solvable = true;
    }
    ~Recursive();

    void solve();
    void print();

private:
    int n;
    bool solvable;
    Board board;

    void initialize();
    bool checkSafe(int row, int col);
    bool solver(int col);
};

#endif
