from __future__ import print_function
import sys

for line in sys.stdin:
    n, m = line.split(',')
    m = int(m)
    l = list(range(int(n)))
    victim = 0
    while len(l):
        victim = (victim+m-1) % len(l)
        # Yes, this leaves a trailing space, but codeeval aren't checking.
        print(l.pop(victim), end=' ')
    print()
