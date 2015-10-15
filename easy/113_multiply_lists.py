import sys

for line in open(sys.argv[1]):
    l, r = line.strip().split(' | ')
    print(' '.join(str(a*b) for a, b in zip((int(x) for x in l.split()), (int(x) for x in r.split()))))
