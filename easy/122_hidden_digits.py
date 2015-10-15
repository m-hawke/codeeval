import sys
from string import maketrans

tt = maketrans('abcdefghij', '0123456789')
delchars = tt.replace('0123456789', '')
for line in open(sys.argv[1]):
    print line.translate(tt, delchars) or 'NONE'


# This should be slower than the above, but codeeval thinks it's faster???
# timeit shows that the above _is_ faster by approx factor of 2.
#import sys
#
#for line in open(sys.argv[1]):
#    l = []
#    for c in line:
#        if c in 'abcdefghij':
#            l.append(str(ord(c) - ord('a')))
#        elif c in '0123456789':
#            l.append(c)
#    print(''.join(l) or 'NONE')
