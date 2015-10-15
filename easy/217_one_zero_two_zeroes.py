import sys

for line in open(sys.argv[1]):
    n_zeros, n = line.split()
    n_zeros = int(n_zeros)

    count = 0
    for i in range(1, int(n)+1):
        if bin(i).count('0')-1 == n_zeros:
            count += 1

    print(count)
