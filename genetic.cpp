#include "globals.h"
#include "genetic.h"

Genetic::~Genetic() {
    for (IndividualPtr i : control)
        delete i;

    for (IndividualPtr i : experimental)
        delete i;
}

void Genetic::solve() {
    std::sort(control.begin(), control.end(), IndividualPtrCompare());
    while (!control[0]->solution()) {
        /* Examine and calculate fitness of current generation */
        fitness(control);

        /* Create & Calculate the fitness of the next generation */
        next_population();
        fitness(experimental);
        inbreed_check();
    }
}

void Genetic::print() const {
    control[0]->print();
}

void Genetic::init_population () {
    for (int i = 0; i < pop_size; i++)
        control.push_back(new Individual(N));
}

void Genetic::next_population () {
    /* Over reproduce */
    for (int i = pop_size * 2; i >= 0; i--)
        experimental.push_back(reproduce());

    /* Survival of the fittest */
    std::sort(experimental.begin(), experimental.end(), IndividualPtrCompare());
    for (int i = (pop_size * 2); i > pop_size -1 ; i--) {
        delete experimental[i];
        experimental.pop_back();
    }
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

    bool inbreed = *control[0] == *control[pop_size - 1];

    if (inbreed) {
        for (IndividualPtr i : control)
            delete i;
        control.clear();
        init_population();
    }
    else
        control = experimental;
    experimental.clear();
}

IndividualPtr Genetic::reproduce () {
    IndividualPtr mother = control[0];
    IndividualPtr father = control[0];
    IndividualPtr child = nullptr;

    // is this correct? reproduce only on highest fitness ??

    double threshold = fRand();
    for (IndividualPtr i : control)
        if ( i->fitness() > threshold) {
            mother = i;
            break;
        }

    threshold = fRand();
    for (IndividualPtr i : control)
        if ( i->fitness() > threshold) {
            father = i;
            break;
        }


    child = new Individual(N, *mother, *father);

    if (fRand() < 0.03)
        child->mutate();

    return child;
}

double Genetic::fRand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
