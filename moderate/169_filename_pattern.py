import sys
import ctypes

# On codeeval's platform this works in Python 2 only.
libc = ctypes.CDLL('libc.so.6')

for line in sys.stdin:
    l = line.strip().split()
    matches = [filename for filename in l[1:]
                    if libc.fnmatch(l[0], filename) == 0]
    print(' '.join(matches) if matches else '-')

## The following works in Python 2 & 3 but is memory hungry.
#import fnmatch
#
#for line in sys.stdin:
#    l = line.strip().split()
#    matches = fnmatch.filter(l[1:], l[0])
#    print(' '.join(matches) if matches else '-')
