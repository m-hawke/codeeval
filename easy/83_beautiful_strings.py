import sys

##31.013
#from collections import Counter
#
#for line in (l.strip() for l in open(sys.argv[1])):
#    c = Counter(c.lower() for c in line if c.isalpha())
#    print sum(a*b for a,b in zip((count for letter, count in c.most_common()), range(26,0,-1)))

##31.039
#from collections import defaultdict
#
#for line in (l.strip() for l in open(sys.argv[1])):
#    d = defaultdict(int)
#    for c in line:
#        if c.isalpha():
#            d[c.lower()] += 1
#    print sum(a*b for a,b in zip(sorted(d.values(), reverse=True), range(26,0,-1)))

#31.485
ORD_A = ord('a')

for line in (l.strip() for l in open(sys.argv[1])):
    counts = [0] * 26
    for c in line:
        if c.isalpha():
            counts[ord(c.lower())-ORD_A] += 1
    counts.sort(reverse=True)
    print(sum(a*b for a,b in zip(counts, range(26,0,-1))))
