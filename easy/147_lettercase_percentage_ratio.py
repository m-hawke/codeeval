import sys

from collections import Counter

for line in open(sys.argv[1]):
    c = Counter('l' if c.islower() else 'U' for c in line.strip())
    pc_lowercase = (float(c['l']) / (c['l'] + c['U'])) * 100
    print('lowercase: {:.2f} uppercase: {:.2f}'.format(pc_lowercase, 100-pc_lowercase))


import sys

for line in open(sys.argv[1]):
    uppercase = lowercase = 0
    for c in line.strip():
        if c.islower():
            lowercase += 1
        else:       # assumes no digits, punctuation etc. in the input
            uppercase += 1
    pc_lowercase = (float(lowercase) / (lowercase + uppercase)) * 100
    print('lowercase: {:.2f} uppercase: {:.2f}'.format(pc_lowercase, 100-pc_lowercase))
