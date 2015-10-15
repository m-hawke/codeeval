import sys

for line in open(sys.argv[1]):
    digits, pattern = line.split()
    pos = pattern.find('-')
    if pos != -1:
        print(int(digits[:pos]) - int(digits[pos:]))
    else:
        pos = pattern.find('+')
        print(int(digits[:pos]) + int(digits[pos:]))

#from operator import add, sub

#for line in open(sys.argv[1]):
#    digits, pattern = line.split()
#    pos = pattern.find('-')
#    if pos != -1:
#        op = sub
#    else:
#        pos = pattern.find('+')
#        op = add
#    print(op(int(digits[:pos]), int(digits[pos:])))
