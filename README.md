# n-queens
The classic problem of placing "queen" chess pieces on an N×N board such that no queen attacks any other queen.  Queen pieces move vertically, horizontally, and both diagonals.  This repo implements search algorithms to solve this problem in both C++ and Python programming languages.

- C++
    - Depth First Search
    - Greedy Local Search
    - Genetic Search
    - Simulated Annealing (under RESEARCH)


- Python  
    - Depth First Search
    - Greedy Local Search
    - Genetic Search (under development)

## C++
Currently, genetic search performs slower than both depth first and greedy local search algorithms.

#### Building:
the usual:  `make`

#### Usage:
`./n-queens <seed> <N>`, where seed is used to seed the random generator, and N is used to specify the board size.


## Python:
Currently, no main driver exists for Python classes.  A module will be created in the future with a driver script.

#### Usage:
`python3 depth_first.py`  
`python3 greedy_local.py`
