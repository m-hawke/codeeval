import sys

for line in open(sys.argv[1]):
    N, M = (int(x) for x in line.split(','))
    print(N - ((N//M)*M))
