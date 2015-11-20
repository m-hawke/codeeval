import sys

def gen_pascals_triangle():
    row = [1]
    while True:
        yield row
        row = [0] + row + [0]
        row = [row[i]+row[i+1] for i in range(len(row)-1)]

def pascals_triangle(depth):
    g = gen_pascals_triangle()
    return [next(g) for i in range(depth)]

# Precalculate the triangle to depth 20, the max size that we will be asked for.
triangle = [str(n) for row in pascals_triangle(20) for n in row]

for line in sys.stdin:
    n = int(line)
    print(' '.join(triangle[:(n*(n+1)//2)]))
