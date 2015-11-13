import sys

def sub_matrices(matrix, matrix_size, n):
    """Yield sub-matrices of size n for the given matrix.

    matrix is a 1D string representation of a 2D matrix.
    """
    for i in range(matrix_size + 1 - n):
        for j in range(matrix_size + 1 - n):
            yield ''.join(matrix[(i+x)*matrix_size+j:(i+x)*matrix_size+j+n]
                            for x in range(n))

for line in open(sys.argv[1]):
    matrix = line.strip().split(' | ')
    matrix_size = len(matrix)
    matrix = ''.join(matrix)    # convert to 1D representation
    for n in range(1, matrix_size+1):
        g = sub_matrices(matrix, matrix_size, n)
        first = next(g).count('1')
        for m in g:
            if m.count('1') != first:
                break
        else:
            print('{0}x{0}, {1}'.format(n, first))
            break
