#include "set_once.h"
#include "individual.h"

/* NOTE: this constructor may only be invoked once to set the static class variable N. */
Individual::Individual(int _n) : N(_n) {
    goal = (N * (N - 1)) / 2;

    for (int i = 0; i < N; i++)
        sequence.push_back(rand() % N);

    m_non_attacking = -1;
    m_fitness = -1;
    non_attacking();
}

Individual::Individual(int _n, const Sequence & s) : N(_n) {
    sequence = vector<Gene>(N);

    for (int i = 0; i < N; i++)
        sequence[i] = s[i];
}

/* Form a child from two parents */
Individual::Individual(int _n, const Individual & mother, const Individual & father)
    : N(_n) {
    int cutoff = rand() % N;
    bool order = rand() % 2;

    sequence = Sequence(N);

    if (cutoff == 0)
        cutoff++;
    else if (cutoff == N - 1)
        cutoff--;

    if (order) {
        for (int i = 0; i < cutoff; i++)
            sequence[i] = mother[i];
        for (int i = cutoff; i < N; i++)
            sequence[i] = father[i];
    } else {
        for (int i = 0; i < cutoff; i++)
            sequence[i] = father[i];
        for (int i = cutoff; i < N; i++)
            sequence[i] = mother[i];
    }

    m_non_attacking = -1;
    m_fitness = -1;
    non_attacking();
}

Individual::~Individual() {
    sequence.clear();
}

bool Individual::operator> (const Individual & rhs) const {
    return this->non_attacking() > rhs.non_attacking();
}

bool Individual::operator== (const Individual & rhs) const {
    bool same = true;

    for (int i = 0; i < N; i++)
        if ((*this)[i] != rhs[i]) {
            same = false;
            break;
        }

    return same;
}

int Individual::operator[] (int i) const {
    if (i >= 0 && i < N)
        return sequence[i];

    return -1;
}

int Individual::non_attacking() const {
    int attacks = 0;

    if (m_non_attacking == -1) {
        /* Down */
        for (int g = N - 1; g > 0; g--)
            for (int c = g - 1; c >= 0; c--)
                if (sequence[g] == sequence[c])
                    attacks++;
        /* Down & Left */
        for (int row = 1; row < N; row++)
            for (int col = sequence[row - 1] - 1, i = row; i < N && col >= 0; i++, col--)
                if (sequence[i] == col)
                    attacks++;
        /* Down & Right */
        for (int row = 1; row < N; row++)
            for (int col = sequence[row - 1] + 1, i = row; i < N && col < N; i++, col++)
                if (sequence[i] == col)
                    attacks++;

        m_non_attacking = goal - attacks;
    }
    return m_non_attacking;
}

double Individual::set_fitness(double sum, double start) {
    if (m_fitness == -1)
        m_fitness = start - (double(non_attacking()) / sum);
    return m_fitness;
}

void Individual::print() const {
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++)
            if (sequence[r] == c)
                cout << "Q ";
            else
                cout << ". ";
        cout << endl;
    }
}

void Individual::mutate() {
    sequence[rand() % N] = rand() % N;

    m_non_attacking = -1;
    m_fitness = -1;
    non_attacking();
}
