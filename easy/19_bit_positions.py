import sys

for line in open(sys.argv[1]):
    n, p1, p2 = (int(x) for x in line.split(','))
    print('true' if ((n >> (p1-1) & 1) == (n >> (p2-1) & 1)) else 'false')
