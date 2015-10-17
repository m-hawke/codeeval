import sys
from string import ascii_lowercase, ascii_uppercase

swap_case = dict(zip((ord(c) for c in ascii_uppercase+ascii_lowercase),
                    ascii_lowercase+ascii_uppercase))

for line in (l.strip() for l in open(sys.argv[1])):
    print(line.translate(swap_case))
