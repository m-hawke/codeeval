import sys

def stupid_sort(l, iterations):
    for _ in range(iterations):
        for i, v in enumerate(l[:-1]):
            if v > l[i+1]:
                l[i], l[i+1] = l[i+1], l[i]
                break

for line in open(sys.argv[1]):
    numbers, _, iterations = line.partition(' | ')
    numbers = [int(x) for x in numbers.split()]
    stupid_sort(numbers, int(iterations))
    print(' '.join(str(x) for x in numbers))
