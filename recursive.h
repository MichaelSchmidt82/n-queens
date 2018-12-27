#ifndef RECURSIVE_H
#define RECURSIVE_H

#include "globals.h"
#include "queens_base.h"

class Recursive : public QueensBase {

public:
    Recursive(int _n) : n(_n), board(nullptr) {
        initialize();
        solvable = true;
    }
    ~Recursive();

    void solve();
    void print() const;

private:
    int n;
    bool solvable;
    Board board;

    void initialize();
    bool checkSafe(int row, int col);
    bool solver(int col);
};

#endif
