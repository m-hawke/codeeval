import sys

for line in open(sys.argv[1], 'U'):
    line = line.rstrip('\n')
    if len(line) > 55:
        line = line[:40]
        head, sep, tail = line.rpartition(' ')
        line = '{}... <Read More>'.format(head if head else tail)
    print(line)
