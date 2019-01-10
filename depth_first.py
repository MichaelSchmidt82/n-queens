import sys

class DepthFirst:
    """

    """
    def __init__(self, N):
        """

        """
        self.N = N

        self.board = [[0 for _ in range(self.N)] for _ in range(self.N)]

    def __str__(self):
        """

        """
        s = ''

        for r in range(self.N):
            row = 'Q' if self.board[r][0] == 1 else '.'
            for c in range(1, self.N):
                if self.board[r][c] != 1:
                    row = '{} {}'.format(row, '.')
                else:
                    row = '{} {}'.format(row, 'Q')
            s = '{}{}\n'.format(s, row)

        s = s[:-1]
        return s



    def solve(self):
        """

        """

        if not self.solve_method(0):
            print("No solution possible for N queens!")

    def solve_method(self, col):
        if col == self.N:
            return True

        for row in range(self.N):
            if self.is_safe(row, col):
                self.board[row][col] = 1
                if self.solve_method(col + 1):
                    return True
                self.board[row][col] = 0

        return False

    def is_safe(self, row, col):
        for c in range(col):
            if self.board[row][c] == 1:
                return False

        for r, c in zip(range(row, -1, -1), range(col, -1, -1)):
            if self.board[r][c] == 1:
                return False

        for r, c in zip(range(row, self.N), range(col, -1, -1)):
            if self.board[r][c] == 1:
                return False

        return True


if __name__ == "__main__":
    df = DepthFirst(20)
    df.solve()
    print(df)
