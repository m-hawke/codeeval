import sys

for line in open(sys.argv[1]):
    A, B = line.rstrip().split(',')
    print(int(A.endswith(B)))
