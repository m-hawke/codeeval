import sys

for line in open(sys.argv[1]):
    data = line.split()
    m = int(data.pop())
    if m <= len(data):
        print(data[-m])
