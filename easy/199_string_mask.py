import sys

for line in open(sys.argv[1]):
    print(''.join([c.upper() if b=='1' else c for c, b in zip(*line.strip().split())]))
