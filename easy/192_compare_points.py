import sys

for line in open(sys.argv[1]):
    O, P, Q, R = [int(x) for x in line.split()]
    dx, dy = (Q - O, R - P)
    direction = []

    if dy > 0:
        direction.append('N')
    elif dy < 0:
        direction.append('S')

    if dx > 0:
        direction.append('E')
    elif dx < 0:
        direction.append('W')

    if len(direction):
        print(''.join(direction))
    else:
        print('here')

# above is slightly faster according to codeeval
#from __future__ import print_function
#for line in open(sys.argv[1]):
#    O, P, Q, R = [int(x) for x in line.split()]
#    dx, dy = (Q - O, R - P)
#
#    if dy > 0:
#        print('N', end='')
#    elif dy < 0:
#        print('S', end='')
#
#    if dx > 0:
#        print('E', end='')
#    elif dx < 0:
#        print('W', end='')
#
#    if dx == dy == 0:
#        print('here', end='')
#
#    print('')
