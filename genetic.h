#ifndef RECURSIVE_H
#define RECURSIVE_H

#include "globals.h"

class Genetic {

public:
    Genetic(int _n) : N(_n) {
        pairs = N * (N - 1) / 2;
    }
    ~Genetic();

    void solve();
    void print();

private:
    int N;
    int pairs;
    int pop_size;
    Population control;
    Population experimental;

    /* Prototypes */
    void init_population();
    void next_population();
    void fitness(Population &);
    void inbreed_check ();
    double fRand (double fMin = 0.0, double fMax = 1.0);
    IndividualPtr reproduce ();
};

#endif
