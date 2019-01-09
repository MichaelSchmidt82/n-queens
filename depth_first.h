#ifndef DEPTH_FIRST_H
#define DEPTH_FIRST_H

#include "globals.h"
#include "queens_base.h"

class DepthFirstSearch : public QueensBase {

public:
	DepthFirstSearch(int _n) : n(_n), board(nullptr) {
		initialize();
		solvable = true;
	}
	~DepthFirstSearch();

	void solve();
	void print() const;

private:
	int n;
	bool solvable;
	Board board;

	void initialize();
	bool checkSafe(int row, int col);
	bool solver(int col);
};

#endif
