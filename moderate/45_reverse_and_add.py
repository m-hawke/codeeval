import sys

for line in open(sys.argv[1]):
    n = int(line)
    i = 0;
    while str(n) != str(n)[::-1]:
        n += int(str(n)[::-1])
        i += 1

    print('{} {}'.format(i, n))
