import sys

def rotate(s, n=1):
    n = n % len(s)
    return s[-n:] + s[:-n]

for line in open(sys.argv[1], 'rU'):
    # Open file in universal new line mode. Take care not to remove other
    # whitespace at the end of each line, e.g. some lines might end in a space.
    a, b = line.rstrip('\n').split(',')
    initial_rotation = b.find(a[0])
    if len(a) == len(b) and initial_rotation != -1:
        a = rotate(a, initial_rotation)
        for i in range(len(a)-initial_rotation):
            if a == b:
                print('True')
                break
            a = rotate(a)
        else:
            print('False')
    else:
        print('False')

#from collections import deque
#
#for line in open(sys.argv[1], 'rU'):
#    # Open file in universal new line mode. Take care not to remove other
#    # whitespace at the end of each line, e.g. some lines might end in a space.
#    a, b = line.rstrip('\n').split(',')
#    initial_rotation = b.find(a[0])
#    if len(a) == len(b) and initial_rotation != -1:
#        a = deque(a)
#        b = deque(b)
#
#        a.rotate(initial_rotation)
#        for i in range(len(a)-initial_rotation):
#            if a == b:
#                print('True')
#                break
#            a.rotate(1)
#        else:
#            print('False')
#    else:
#        print('False')
