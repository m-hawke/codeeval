import sys

for line in open(sys.argv[1]):
    i = 0
    current = line[0]
    while i < len(line):
        if line[i] != current:
            sys.stdout.write(current)
            current = line[i]
        i += 1
    sys.stdout.write(current)

# The following re solution runs faster, but uses more memory and so gets a
# lower codeeval score than does the eyesore above.
#import sys
#import re
#
#for line in open(sys.argv[1]):
#    sys.stdout.write(re.sub(r'(.)\1+', r'\1', line))
