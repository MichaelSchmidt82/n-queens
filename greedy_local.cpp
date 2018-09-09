#include "greedy_local.h"
#include "globals.h"

/* Constructor & Destructor */

GreedyLocal::~GreedyLocal() {
    for (int i = 0; i < n; i++)
        delete [] board[i];
    delete [] board;
}

/* Public */

void GreedyLocal::solve() {

    int tries = n / 2;
    int curr = findLowest();
    int last;

    do {
        placeLowest();
        update();

        last = curr;
        curr = findLowest();

        if (curr >= last)
            tries--;

        /* If we can't improve after N / 2 attempts, try a new random board. */
        if (!tries) {
            initialize();
            tries = n / 2;
        }

    } while (!is_solution());
}


void GreedyLocal::print() {
    /* Print the board: -1 are queens, everything else is blank */
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++)
            if (board[r][c] == -1)
                cout <<"Q ";
            else
                cout << "- ";
        cout << endl;
    }
}

/* Private */

void GreedyLocal::initialize () {
    /* Create a board if it doesn't exist */
    if (!board) {
        board = new Tile*[n];
        for (int r = 0, i; r < n; r++)
            board[r] = new Tile[n];
    }

    /* Zero out old board */
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            board[r][c] = 0;

    /* Clear the queens list */
    queens.clear();

    /* Assign queens 1 per column randomly */
    for (int r = 0, c; r < n; r++) {
        c = rand() % n;
        board[r][c] = -1;
        queens.push_back(make_pair(r, c));
    }

    update();
}


void GreedyLocal::update() {
    int count = 0;

    /* For ever row, calculate the heuristic value as if the queen was moved
       to every sqaure in that row */
    for (int r = 0; r < n; r++) {
        board[queens[r].first][queens[r].second] = 0;
        for (int c = 0; c < n; c++) {
            board[r][c] = -1;
            for (int k = 0; k < n; k++)
                if (k != r)
                    count += heuristicFunction(queens[k]);
            count += heuristicFunction(make_pair(r, c));
            board[r][c] = (queens[r].first == r && queens[r].second == c) ? -1 : count;
            count = 0;
        }
    }
}


int GreedyLocal::findLowest() {
    int min = (board[0][0] != -1) ? board[0][0] : board[0][1];
    minimums.clear();

    /* Find the minimum value on the board */
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            if (board[r][c] < min && board[r][c] != -1)
                min = board[r][c];

    /* Find all the mimimums values */
    for (int r = 0; r < n; r++)
        for (int c = 0; c < n; c++)
            if (board[r][c] == min)
                minimums.push_back(make_pair(r, c));

    return min;
}


void GreedyLocal::placeLowest () {
    /* Pick a random minimum location */
    int move = rand() % minimums.size();
    int row = minimums[move].first;
    int col = minimums[move].second;

    /* Find the queen and replace it with a heuristic value */
    for (int c = 0; c < n; c++)
        if (board[row][c] == -1) {
            board[row][col] = -1;           // Put new queen
            queens[row].first = row;
            queens[row].second = col;

            board[row][c] = 0;              // Remove old queen
            break;
        }
}


/* Number of colliding queens */
int GreedyLocal::heuristicFunction(pair<int, int> queen) {
    int count = 0;

    /* down & right */
    for (int r = queen.first + 1, c = queen.second + 1; r < n && c < n; r++, c++)
           if (board[r][c] == -1)
               count++;

    /* down & left */
    for (int r = queen.first + 1, c = queen.second - 1; r < n && c > -1; r++, c--)
           if (board[r][c] == -1)
               count++;

    /* down */
    for (int r = queen.first + 1, c = queen.second; r < n; r++)
        if (board[r][c] == -1)
            count++;

    return count;
}


bool GreedyLocal::is_solution () {
    /* Check the heuristic for each queen */
    for (int i = 0; i < n; i++)
        if (heuristicFunction(queens[i]))
            return false;

    return true;
}
