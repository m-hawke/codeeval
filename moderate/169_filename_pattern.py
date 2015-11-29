import sys
import fnmatch

for line in sys.stdin:
    l = line.strip().split()
    matches = fnmatch.filter(l[1:], l[0])
    print(' '.join(matches) if matches else '-')
