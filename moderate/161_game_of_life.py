import sys

def next_gen(matrix):
    new_matrix = [[0] * len(matrix[0]) for i in range(len(matrix))]
    for i in range(1, len(matrix)-1):
        for j in range(1, len(matrix)-1):
            n_neighbours = (sum(sum(matrix[row][j-1:j+2])
                                for row in range(i-1,i+2)) - matrix[i][j])
            if matrix[i][j]:        # cell is alive
                new_matrix[i][j] = int(2 <= n_neighbours <=3)
            else:
                new_matrix[i][j] = int(n_neighbours == 3)
    return new_matrix

matrix = []
for line in open(sys.argv[1]):
    matrix.append([0] + [int(cell == '*') for cell in line.strip()] + [0])

matrix.insert(0, [0] * len(matrix[0]))
matrix.append([0] * len(matrix[0]))

for i in range(10):
    matrix = next_gen(matrix)

for line in matrix[1:-1]:
    print(''.join('*' if cell else '.' for cell in line[1:-1]))
