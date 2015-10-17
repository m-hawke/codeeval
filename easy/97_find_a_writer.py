import sys

for line in (l.strip() for l in open(sys.argv[1])):
    if line:
        text, key = line.split('|')
        print(''.join(text[int(i)-1] for i in key.split()))
