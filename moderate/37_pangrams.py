import sys
import string

all_letters = set(string.ascii_lowercase)

for line in open(sys.argv[1]):
    print(''.join(sorted(all_letters.difference(line.strip().lower()))) or 'NULL')
