import sys

for line in open(sys.argv[1]):
    hex_bits, bin_bits = [s.split() for s in line.split(' | ')]
    print(sum(int(s, 2) for s in bin_bits) >= sum(int(s, 16) for s in hex_bits))
