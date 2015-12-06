import sys

alphabet = ''' !"#$%&'()*+,-./0123456789:<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'''
char_pos = dict(zip(alphabet, range(len(alphabet))))

for line in sys.stdin:
    key, message = line.rstrip('\n').split(';', 1)
    key = [int(x) for x in key]
    for i, char in enumerate(message):
        offset = key[i%len(key)]
        sys.stdout.write(alphabet[char_pos[char]-offset])
    sys.stdout.write('\n')

# Following ranks higher  in Python 3, but lower than the above in Python 2
#    print(''.join([alphabet[char_pos[char]-key[i%len(key)]] for i, char in enumerate(message)]))

## Uses a bit too much memory to get a good ranking.
#import sys
#import itertools
#
#alphabet = ''' !"#$%&'()*+,-./0123456789:<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz'''
#char_pos = dict(zip(alphabet, range(len(alphabet))))
#
#for line in sys.stdin:
#    key, message = line.rstrip('\n').split(';', 1)
#    for char, offset in zip(message, itertools.cycle(int(x) for x in key)):
#        sys.stdout.write(alphabet[char_pos[char]-offset])
#    sys.stdout.write('\n')
