import sys

for line in open(sys.argv[1]):
    print(','.join(str(x) for x in sorted(set(int(x) for x in line.split(',')))))
