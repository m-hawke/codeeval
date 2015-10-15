import sys
from itertools import groupby

for line in open(sys.argv[1]):
    print(' '.join('{} {}'.format(len(list(v)), g)
                for g, v in groupby(line.split())))


# codeeval same time, but the following uses less memory, so it's higher ranked
#for line in open(sys.argv[1]):
#    line = line.split()
#    current = line[0]
#    count = 1
#    for s in line[1:]:
#        if s == current:
#            count += 1
#        else:
#            print count, current,
#            current = s
#            count = 1
#    print count, current
