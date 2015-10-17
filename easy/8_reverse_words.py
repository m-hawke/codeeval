import sys

for line in open(sys.argv[1]):
#    print(' '.join(reversed(line.split())))
    # slice reverse slightly faster
    print(' '.join(line.strip().split()[::-1]))
