import sys

for line in open(sys.argv[1]):
    print(' | '.join((' '.join((str(x) for x in row)) for row in zip(*sorted(zip(*((int(x) for x in row.split()) for row in line.split(' | '))))))))

## Above is a one-liner generator expression version of this:
#    rows = zip(*sorted(zip(*[[int(x) for x in row.split()]
#                                for row in line.split(' | ')])))
#    print(' | '.join([' '.join([str(x) for x in row]) for row in rows]))
