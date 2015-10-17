import sys

for line in open(sys.argv[1]):
    print((int(line) % 2) ^ 1)
#    print(int(line[-1] in ('2', '4', '6', '8', '0')))
