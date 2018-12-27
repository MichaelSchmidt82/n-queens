#include "globals.h"
#include "recursive.h"

/* Constructor/Destructor */

Recursive::~Recursive() {
    /* Cleanup heap allocations */
	for (int i = 0; i < n; i++)
		delete [] board[i];
	delete [] board;
}

/* public */
void Recursive::solve() {
    if (!solver(0))
		solvable = false;
}

void Recursive::print() const {

    if (!solvable) {
        cout << "This board is unsolvable." << endl;
        return;
    }

	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++)
			if (board[r][c] == 0)
                cout << "- ";
            else
                cout << "Q ";
		cout << endl;
	}
}

/* private */

void Recursive::initialize() {
    if (!board) {
        board = new Tile*[n];
        for (int r = 0, i; r < n; r++)
            board[r] = new Tile[n];
    }

    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            board[r][c] = 0;
}


bool Recursive::checkSafe(int row, int col) {
	int c, r;

	/* Check current column */
	for (c = 0; c < col; c++)
		if (board[row][c] == 1)
			return false;

	/* Check diagonal (up/left) */
	for (r = row, c = col; r > -1 && c > -1; r--, c--)
		if (board[r][c] == 1)
			return false;

	/* Check diagonal (down/left) */
	for (r = row, c = col; c > -1 && r < n; r++, c--)
		if (board[r][c] == 1)
			return false;

	return true;
}


bool Recursive::solver(int col) {
	/* Base case */
	if (col == n)
		return true;

	/* Recursive case */
	for (int r = 0; r < n; r++) {
		if (checkSafe(r, col)) {
			board[r][col] = 1;
			if (solver(col + 1))
				return true;
			board[r][col] = 0;
		}
	}
	return false;
}
