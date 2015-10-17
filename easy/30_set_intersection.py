import sys

for line in open(sys.argv[1]):
    l1, l2 = line.strip().split(';')
    print(','.join(sorted(set(l1.split(',')).intersection(l2.split(',')))))
