import sys
from collections import Counter

for line in open(sys.argv[1]):
    numbers = line.strip().split()
    candidates = [t[0] for t in Counter(numbers).items() if t[1] == 1]
    if candidates:
        print(numbers.index(min(candidates))+1)
    else:
        print("0")
