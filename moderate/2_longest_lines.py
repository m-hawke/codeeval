from __future__ import print_function
import sys

with open(sys.argv[1]) as f:
    n = int(next(f))
    print(*sorted(f, key=len, reverse=True)[:n], sep='', end='')
