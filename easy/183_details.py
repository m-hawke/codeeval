import sys

for line in (l.strip() for l in open(sys.argv[1])):
    print(min([s.find('Y') - s.rfind('X') - 1 for s in line.split(',')]))
