import sys

for line in open(sys.argv[1]):
    print(' '.join(sorted(line.split(), reverse=True)))
#    print(*sorted(line.split(), reverse=True), sep=' ')
