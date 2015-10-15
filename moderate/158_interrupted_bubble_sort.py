import sys

def interrupted_bubble_sort(l, n):
    # once sorted further passes are futile, so cap it at the list length
    max_passes = min(len(l), n)
    for i in range(max_passes):
        for j in range(len(l)-i-1):
            if l[j] > l[j+1]:
                l[j], l[j+1] = l[j+1], l[j]
    return l

for line in open(sys.argv[1]):
    numbers, n = line.split('|')
    print(' '.join(str(x) for x in interrupted_bubble_sort([int(x) for x in numbers.split()], int(n))))
