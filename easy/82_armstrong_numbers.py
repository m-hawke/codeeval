import sys

for line in (l.strip() for l in open(sys.argv[1])):
    print int(line) == sum(int(c)**len(line) for c in line)
