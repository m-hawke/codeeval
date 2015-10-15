from __future__ import print_function
import sys

for line in open(sys.argv[1]):
#    print(*('{}{}{}'.format(word[-1], word[1:-1], word[0]) for word in line.strip().split()), sep=' ')
    print(*(word[-1] + word[1:-1] + word[0] for word in line.strip().split()), sep=' ')
