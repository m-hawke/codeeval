import sys

for line in open(sys.argv[1]):
    numbers = [int(x) for x in line.strip().split(',')]

    max_ = sum(numbers)
    for length in range(1, len(numbers), 2):    # N.B increment by 2
        sum_ = sum(numbers[:length])
        max_ = sum_ if sum_ > max_ else max_
        for i in range(len(numbers)-length):
            # N.B. the following sum is also a sum of contiguous numbers
            # for length + 1. We need calculate this once only, and
            # therefore the length loop (see above) is incremented by 2
            # each time. */
            sum_ += numbers[i+length]
            max_ = sum_ if sum_ > max_ else max_
            sum_ -= numbers[i]
            max_ = sum_ if sum_ > max_ else max_

    print(max_)

#for line in open(sys.argv[1]):
#    numbers = [int(x) for x in line.strip().split(',')]
#    print(max([sum(numbers[x:x+i])
#            for i in range(1,len(numbers)+1)
#                for x in range(len(numbers)-i+1)]))
