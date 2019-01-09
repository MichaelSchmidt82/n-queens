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

	int non_attacking() const;
	bool solution() const { return goal == non_attacking(); }
	double fitness() const { return m_fitness; }
	void print() const;

	double set_fitness(double sum, double start);
	void mutate();

private:
	mutable int m_non_attacking;
	mutable double m_fitness;
	Sequence sequence;

	const int N;
	int goal;
};

struct IndividualPtrCompare {
	bool operator()(const IndividualPtr lhs, const IndividualPtr rhs) const { return *lhs > *rhs; }
};
#endif
