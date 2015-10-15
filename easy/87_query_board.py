import sys

BOARD_SIZE = 256

board = [[0]*BOARD_SIZE]*BOARD_SIZE

for line in open(sys.argv[1]):
    line = line.strip().split()
    if len(line) == 2:
        cmd, row_col = line
        row_col = int(row_col)
    else:
        cmd, row_col, x = line
        row_col = int(row_col)
        x = int(x)

    if cmd == 'SetRow':
        board[row_col] = [x] * BOARD_SIZE
    elif cmd == 'SetCol':
        for row in range(BOARD_SIZE):
            board[row][row_col] = x
    elif cmd == 'QueryRow':
        print(sum(board[row_col]))
    elif cmd == 'QueryCol':
        print(sum(board[row][row_col] for row in range(BOARD_SIZE)))
