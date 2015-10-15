import sys
from string import maketrans, lowercase, uppercase

swap_case = maketrans(uppercase+lowercase, lowercase+uppercase)

for line in (l.strip() for l in open(sys.argv[1])):
    print line.translate(swap_case)
