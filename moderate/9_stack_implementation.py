import sys

for line in open(sys.argv[1]):
    print(' '.join(line.split()[::-2]))
