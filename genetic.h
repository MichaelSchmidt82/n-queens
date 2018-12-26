#ifndef RECURSIVE_H
#define RECURSIVE_H

#include "globals.h"

class Genetic {

public:
    Genetic(int _n) : N(_n), board(nullptr) {
        pairs = N * (N - 1) / 2;
    }
    ~Genetic();

    void solve();
    void print();

private:
    int N;
    int pairs;
    int pop_size;
    Population curr_gen;
    Population next_gen;

    /* Prototypes */
    void init_population(Population & population, const int POP_SIZE, const int N = -1);
    void next_population(Population & population, Population & next_gen, const int POP_SIZE);
    void fitness(Population & population);
    void inbreed_check (Population & population, Population & next_gen, const int POP_SIZE);
    double fRand (double fMin = 0.0, double fMax = 1.0);
    IndividualPtr reproduce (const Population & population);


};

#endif
