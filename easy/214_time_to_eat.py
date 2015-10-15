import sys

for line in open(sys.argv[1]):
    print(*sorted(line.split(), reverse=True), sep=' ')
#    print(' '.join(sorted(line.split(), reverse=True)))
