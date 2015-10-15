import sys

for line in open(sys.argv[1]):
    print(bin(int(line)).count('1'))
