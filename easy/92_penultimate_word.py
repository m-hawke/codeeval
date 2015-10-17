import sys

for line in (l.strip() for l in open(sys.argv[1])):
    print(line.split()[-2])
