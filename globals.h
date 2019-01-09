#ifndef GLOBALS_H
#define GLOBALS_H

/* Includes */
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

/* Using Statements */
using std::atoi;
using std::cout;
using std::endl;
using std::make_pair;
using std::move;
using std::pair;
using std::setprecision;
using std::setw;
using std::sort;
using std::vector;

/* Forward Declarations */
class Individual;

/* Typedefs */
typedef int Tile;
typedef Tile** Board;
typedef vector< pair<int, int> > Locations;

typedef int Gene;
typedef vector<Gene> Sequence;
typedef Individual* IndividualPtr;
typedef vector<IndividualPtr> Population;

#endif // !GLOBALS_H
