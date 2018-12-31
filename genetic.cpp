#include "globals.h"
#include "genetic.h"

Genetic::~Genetic() {
    for (IndividualPtr i : curr_gen)
        delete i;

    for (IndividualPtr i : next_gen)
        delete i;
}

void Genetic::solve() {
    std::sort(curr_gen.begin(), curr_gen.end(), IndividualPtrCompare());
    while (!curr_gen[0]->solution()) {
        /* Examine and calculate fitness of current generation */
        fitness(curr_gen);

        /* Create & Calculate the fitness of the next generation */
        next_population();
        fitness(next_gen);
        inbreed_check();
    }
}

void Genetic::print() const {
    curr_gen[0]->print();
}

void Genetic::init_population () {
    curr_gen.reserve(pop_size);
    for (int i = 0; i < pop_size; i++) {
        curr_gen.push_back(new Individual(N));
    }
}

void Genetic::next_population () {
    /* Over reproduce */
    next_gen.reserve(N * 2);
    for (int i = pop_size * 2; i >= 0; i--)
        next_gen.push_back(reproduce(curr_gen));

    /* Survival of the fittest */
    std::sort(next_gen.begin(), next_gen.end(), IndividualPtrCompare());
    for (int i = (pop_size * 2); i > pop_size - 1 ; i--) {
        delete next_gen[i];
    }

    next_gen.resize(N);
}

void Genetic::fitness(Population & population) {
    double start = 1.0;
    int sum = 0;

    for (IndividualPtr i : population)
        sum += i->non_attacking();

    for (IndividualPtr i : population)
        start = i->set_fitness(sum, start);
}

void Genetic::inbreed_check () {

    bool inbreed = *curr_gen[0] == *curr_gen[pop_size - 1];

    for (IndividualPtr i : curr_gen)
        delete i;

    curr_gen.clear();

    if (inbreed)
        init_population();
    else
        curr_gen = next_gen;
    next_gen.clear();
}

IndividualPtr Genetic::reproduce (const Population & population) {
    IndividualPtr mother = population[0];
    IndividualPtr father = population[0];
    IndividualPtr child = nullptr;

    double threshold = fRand();
    for (IndividualPtr i : population)
        if (i->fitness() > threshold) {
            mother = i;
            break;
        }

    threshold = fRand();
    for (IndividualPtr i : population)
        if (i->fitness() > threshold) {
            father = i;
            break;
        }

    child = new Individual(N, *mother, *father);

    if (fRand() < 0.025)
        child->mutate();

    return child;
}

double Genetic::fRand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
