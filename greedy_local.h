#ifndef GREEDY_LOCAL_H
#define GREEDY_LOCAL_H

#include "globals.h"
#include "queens_base.h"

class GreedyLocal : public QueensBase {

public:
	GreedyLocal(int _n) : N(_n), board(nullptr) {
		initialize();
	};
	~GreedyLocal();

	void solve();
	void print() const;


private:
	/* variables */
	int N;
	Board board;
	Locations queens;
	Locations minimums;

	void initialize();
	void update();

	int findLowest();
	void placeLowest();

	int heuristicFunction(pair<int, int>);
	bool is_solution();
};
#endif
