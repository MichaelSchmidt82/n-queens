#ifndef GENETIC_H
#define GENETIC_H

#include "globals.h"
#include "queens_base.h"
#include "individual.h"

class Genetic : public QueensBase {

public:
    Genetic(int _n) : N(_n) {
        pairs = N * (N - 1) / 2;
        pop_size = 500;

        init_population();
    }
    ~Genetic();

    void print() const;
    void solve();

private:
    const int N;
    int pairs;
    int pop_size;
    Population curr_gen;
    Population next_gen;

    /* Prototypes */
    void init_population();
    void next_population();
    void fitness(Population &);
    void inbreed_check ();
    double fRand (double fMin = 0.0, double fMax = 1.0);
    IndividualPtr reproduce(const Population &);
};
#endif
