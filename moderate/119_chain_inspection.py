import sys

for line in open(sys.argv[1]):
    pairs = {'END': 'END'}
    for pair in line.strip().split(';'):
        name, next_pair = pair.split('-')
        pairs[name] = next_pair

    this_pair = 'BEGIN'
    try:
        while len(pairs) > 0:
            next_pair = pairs[this_pair]
            del pairs[this_pair]
            this_pair = next_pair
    except KeyError:
        print('BAD')
    else:
        print('GOOD')
