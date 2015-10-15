from __future__ import print_function
import sys

for line in open(sys.argv[1]):
    print(*[max(t, key=lambda x: int(x)) for t in zip(*(s.split() for s in line.split(' | ')))])
