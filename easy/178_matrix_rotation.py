from __future__ import print_function
import sys
from math import sqrt

for line in open(sys.argv[1]):
    N = int(sqrt((len(line)+1)/2))
    for i in range(N):
        for j in range(N-1, -1, -1):
            print(line[(N*j+i)*2], end=' ')
    print('')

# fast but more memory
#for line in open(sys.argv[1]):
#    line = line.split()
#    N = int(sqrt(len(line)))
#    for col in zip(*reversed([line[i:i+N] for i in range(0, len(line), N)])):
#        print(' '.join(col), end=' ')
#    print("")
