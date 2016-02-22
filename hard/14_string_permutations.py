import sys
from itertools import permutations

for line in sys.stdin:
    print(','.join(sorted(''.join(p) for p in permutations(line.strip()))))
