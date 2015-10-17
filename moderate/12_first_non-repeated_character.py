import sys

# This O(n^2) solution gets the highest ranking on codeval.
for line in (l.strip() for l in open(sys.argv[1])):
    for c in line:
        if line.count(c) == 1:
            print(c)
            break

#from collections import defaultdict
#
#for line in (l.strip() for l in open(sys.argv[1])):
#    d = defaultdict(int)
#    for c in line:
#        d[c] += 1
#    for c in line:
#        if d[c] == 1:
#            print(c)
#            break

## You'd think that using collections.Counter would be better than a
## defaultdict, but it's not.
#from collections import Counter
#
#for line in (l.strip() for l in open(sys.argv[1])):
#    counter = Counter(line)
#    for c in line:
#        if counter[c] == 1:
#            print(c)
#            break
