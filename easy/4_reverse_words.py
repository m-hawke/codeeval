#107    3919316 31.541
import sys

for line in (l.strip() for l in open(sys.argv[1])):
    if line:
        print(' '.join(reversed(line.split())))
