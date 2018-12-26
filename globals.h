#ifndef GLOBALS_H
#define GLOBALS_H

/* Includes */
//#include <algorithm>
#include <cassert>
//#include <mutex>
#include <vector>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

/* Using Statements */
using std::atoi;
using std::cout;
using std::endl;
using std::make_pair;
using std::pair;
using std::setprecision;
using std::setw;
using std::vector;

/* Forward Declarations */
class Individual;

/* Typedefs */
typedef int Tile;
typedef Tile** Board;
typedef vector< pair<int, int> > Locations;

typedef int Gene;
typedef Gene* Sequence;
typedef Individual* IndividualPtr;
typedef vector<IndividualPtr> Population;

#endif // !GLOBALS_H
