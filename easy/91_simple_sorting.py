import sys

for line in open(sys.argv[1]):
    print(' '.join('%.3f' % x for x in sorted(float(x) for x in line.split())))
