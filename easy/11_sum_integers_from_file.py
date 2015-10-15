import sys

print sum(int(s) for s in open(sys.argv[1]))
