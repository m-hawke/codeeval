import sys
import re
import math

pattern = re.compile(r'\((?P<x1>-?\d+),\s*(?P<y1>-?\d+)\)\s*\((?P<x2>-?\d+),\s*(?P<y2>-?\d+)')

for line in open(sys.argv[1]):
    d = pattern.match(line).groupdict()
    print(int(math.sqrt(((int(d['x1']) - int(d['x2'])) ** 2) + ((int(d['y1']) - int(d['y2'])) ** 2))))


#import sys
#import math
#import string
#
#for line in open(sys.argv[1]):
##    x1, y1, x2, y2 = (int(x) for x in line.translate(string.maketrans('(,)','   ')).split())
#    x1, y1, x2, y2 = (int(x) for x in line.translate({ord(c):None for c in '(),'}).split())
#    print(int(math.sqrt((x1-x2)**2 + (y1-y2)**2)))
