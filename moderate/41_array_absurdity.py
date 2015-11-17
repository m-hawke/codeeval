import sys

#Bit twiddling is slightly slower (and less readable) than the list
#implemenation below, but uses slightly less memory, so its codeeval rank is
#slightly better.
for line in sys.stdin:
    N, numbers = line.rstrip().split(';')
    counter = 0L
    for s in numbers.split(','):
        n = int(s)
        if counter & (1 << n):
            print(n)
        counter |= (1 << n)

#for line in sys.stdin:
#    N, numbers = line.rstrip().split(';')
#    counter = [0] * 50
#    for s in numbers.split(','):
#        n = int(s)
#        if counter[n]:
#            print(n)
#        counter[n] = 1

##codeeval rates the following poorly.
#from collections import Counter
#
#for line in sys.stdin:
#    N, numbers = line.rstrip().split(';')
#    print(Counter(numbers.split(',')).most_common(1)[0][0])
