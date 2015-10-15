from __future__ import print_function
import sys

for line in open(sys.argv[1]):
    C = ord(line[0]) - ord('a')
    N = int(line[1])

    for c, n in (C-2, N-1), (C-2, N+1), (C-1, N-2), (C-1, N+2), (C+1, N-2), (C+1, N+2), (C+2, N-1), (C+2, N+1):
        if (0 <= c < 8) and (0 < n <= 8):
            print('{}{}'.format(chr(c + ord('a')), n), end=' ')
    print("")
