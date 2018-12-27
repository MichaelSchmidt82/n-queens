#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H

#include "globals.h"

class Individual {
    public:
        Individual(int n);
        Individual(int n, const Sequence & s);
        Individual(int n, const Individual & mother, const Individual & father);
        ~Individual();

        int operator[] (int i) const;
        bool operator> (const Individual & rhs) const;
        bool operator== (const Individual & rhs) const;

        int queen_pairs() const;
        bool solution() const { return n_pairs == queen_pairs();}
        double fitness () const { return m_Fitness; }
        void print() const;

        double set_fitness (double sum, double start);
        void mutate();

    private:
        mutable int m_NonAttackingPairs;
        mutable double m_Fitness;
        Sequence sequence;

        const int N;
        int n_pairs;
};

struct IndividualPtrCompare {
	bool operator()(const IndividualPtr lhs, const IndividualPtr rhs) const { return *lhs > *rhs; }
};
#endif
