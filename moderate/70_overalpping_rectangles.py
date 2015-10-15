import sys

for line in open(sys.argv[1]):
    n5, r = divmod(int(line), 5)
    n3, n1 = divmod(r, 3)
    print(n5 + n3 + n1)
