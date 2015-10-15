import sys

for line in (l.strip() for l in open(sys.argv[1])):
    if line:
        x, n = (int(x) for x in line.split(','))

        multiplier = 1
        while n * multiplier < x:
            multiplier += 1

        print n * multiplier
