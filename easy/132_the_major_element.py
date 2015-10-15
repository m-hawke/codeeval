import sys
from collections import defaultdict
from operator import itemgetter

count = itemgetter(1)

for line in open(sys.argv[1]):
    elements = line.strip().split(',')
    d = defaultdict(int)
    for e in elements:
        d[e] += 1
    major_element, n = max(d.items(), key=count)
    print(major_element if n > len(elements)/2 else 'None')
