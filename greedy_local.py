import random
import numpy as np

class GreedyLocal:

    def __init__(self, N):
        self.N = N

        self.initialize()

    def __str__(self):
        pass

    def solve():
        """


        """
        pass

    def initialize(self):
        """

        """
        self.board = np.array([[0 for _ in range(9)] for _ in range(9)], dtype=np.int8)
        self.queens = []
        self.minimums = []

        for r in range(self.N):
            c = random.randint(0, N - 1)
            self.board[r][c] = -1
            queens.appned(tuple(r, c))

        self.update()

    def update(self):
        """

        """
        count = 0

        for r in range(N):
            self.board[queens[r][0]][queens[r][1]] = 0
            for c in range(N):
                self.board[r][c] = -1
                for k in range(N):
                    if k != r:
                        count += self.heuristic(queens[k])

                count += self.heuristic(tuple(r, c))
                board[r][c] = -1 if (queens[r][0] == r && queens[r][1] == c) else count
                count = 0

    def find_lowest(self):
        """

        """
        min = self.board[0][0] if self.board[0][0] != -1 else self.board[0][1]
        self.minimums = []

        for r in range(self.N):
            for c in range(self.N):
                if self.board[r][c] < min and self.board[r][c] != -1:
                    min = self.board[r][c]

        for r in range(self.N):
            for c in range(self.N):
                if self.board[r][c] == min:
                    self.minimums.append(tuple(r, c))

        return min

    def place_lowest(self):
        """

        """
        move = random.randint(0, len(self.minimums) - 1)
        row, col = minimum[move][0], minimum[move][1]

        for c in range(self.N):
            if self.board[row][c] == -1:
                self.board[row][col] = -1
                queens[row][0], queens[row][1] = row, col

                self.board[row][c] = 0
                break

    def heuristic(self, queen):
        """

        """
        count = 0
        for r, c in zip(range(queen[0]+1, self.N), range(queen[1]+1, self.N))):
            if self.board[r][c] == -1:
                count += 1

        for r, c in zip(range(queen[0]+1, self.N), range(queen[1]-1, -1, -1))):
            if self.board[r][c] == -1:
                count += 1

        for r in range(queen[0]+1, self.N):
            if self.board[r][queen[1]] == -1:
                count += 1

        return count

    def is_solution(self):
        """

        """
        for i in range(self.N):
            if self.heuristic(self.queens[i]):
                return False

        return True
