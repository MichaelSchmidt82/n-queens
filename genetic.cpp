#include "globals.h"
#include "genetic.hs"
#include "individual.h"
#include "set_once.h"


/* int main */
int Genetic::sovle(int argc, char * argv[]) {

    /* init */
    assert(argc == 4 && "Insufficient arguments provided: POPULATION_SIZE, SEED, and N needed.");
    srand(atoi(argv[2]));

    /* Constants */
    const int POP_SIZE = atoi(argv[1]);             // Population size
    const int N = atoi(argv[3]);                    // Board size

    int pairs = (N * (N - 1)) / 2;
    Population curr_gen;
    Population next_gen;


    // Total non-paired combonations possible.
    cout << "Target: " << setw(8) << pairs << endl;

    init_population(curr_gen, POP_SIZE, N);
    std::sort(curr_gen.begin(), curr_gen.end(), IndividualPtrCompare());

    while (!curr_gen[0]->solution()) {
        /* Examine and calculate fitness of current generation */
        fitness(curr_gen);

        /* Create & Calculate the fitness of the next generation */
        next_population(curr_gen, next_gen, POP_SIZE);
        fitness(next_gen);
        inbreed_check(curr_gen, next_gen, POP_SIZE);
    }
    cout << '\r' << endl << endl;
    cout << "Solution found:" << endl;

    curr_gen[0]->printer();
    return 0;
}

void Genetic::init_population (Population & population, const int POP_SIZE, const int N) {
    int stop = POP_SIZE - 1;
    IndividualPtr individual;

    individual = (N == -1) ? new Individual() : new Individual(N);
    do {
        population.push_back(individual);
        individual = new Individual(); //BUG! memory leak possible (make into simple for loop)
    } while (population.size() < stop);
    population.push_back(individual);
}

void Genetic::next_population (Population & population, Population & next_gen, const int POP_SIZE) {
    /* Over reproduce */
    for (int i = POP_SIZE * 2; i >= 0; i--)
        next_gen.push_back(reproduce(population));

    /* Survival of the fittest */
    std::sort(next_gen.begin(), next_gen.end(), IndividualPtrCompare());
    for (int i = (POP_SIZE * 2); i > POP_SIZE -1 ; i--) {
        delete next_gen[i];
        next_gen.pop_back();
    }
}

void Genetic::fitness(Population & population) {
    double start = 1.0;
    int sum = 0;

    for (IndividualPtr i : population)
        sum += i->queen_pairs();

    for (IndividualPtr i : population)
        start = i->set_fitness(sum, start);
}

void Genetic::inbreed_check (Population & curr_gen, Population & next_gen, const int POP_SIZE) {

    static int count = 0;
    bool inbreed = *curr_gen[0] == *curr_gen[POP_SIZE - 1];

    if (count == 15) {
        cout << "Best: " << setw(10) << curr_gen[0]->queen_pairs() << ' ';
        count = 0;
    }

    if (inbreed) {
        for (IndividualPtr i : curr_gen)
            delete i;
        curr_gen.clear();
        init_population(curr_gen, POP_SIZE);
    }
    else
        curr_gen = next_gen;
    next_gen.clear();

    cout << "\t\r";
    count++;
}

IndividualPtr Genetic::reproduce (const Population & population) {
    IndividualPtr mother = population[0];
    IndividualPtr father = population[0];
    IndividualPtr child = nullptr;

    double threshold = fRand();
    for (IndividualPtr i : population)
        if ( i->fitness() > threshold)
            mother = i;

    threshold = fRand();
    for (IndividualPtr i : population)
        if ( i->fitness() > threshold)
            father = i;

    child = new Individual(*mother, *father);
    if (fRand() < 0.01)
        child->mutate();

    return child;
}

double Genetic::fRand(double fMin, double fMax) {
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
