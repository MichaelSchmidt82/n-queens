import sys
import numpy as np


def solve(size):
    board = np.zeros((size, size), dtype=np.int8)

    if not solver(board, size, 0):
        print("No solution possible for N queens!")
    else:
        print(board)


def solver(board, size, col):
    if col == size:
        return True

    for r in range(size):
        if is_safe(board, size, r, col):
            board[r][col] = 1
            if solver(board, size, col + 1):
                return True
            board[r][col] = 0
    return False


def is_safe(board, size, row, col):
    for c in range(col):
        if board[row][c] == 1:
            return False

    for r, c in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[r][c] == 1:
            return False

    for r, c in zip(range(row, size), range(col, -1, -1)):
        if board[r][c] == 1:
            return False

    return True


if __name__ == "__main__":
    solve(int(sys.argv[1]))
