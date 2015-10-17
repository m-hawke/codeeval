import sys

for line in open(sys.argv[1]):
    print sum(int(c) for c in line.strip())
