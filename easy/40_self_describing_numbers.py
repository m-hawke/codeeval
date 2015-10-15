import sys

#for line in (l.strip() for l in open(sys.argv[1])):
#    print(int(all(line.count(str(i)) == int(c) for i, c in enumerate(line))))


for line in (l.strip() for l in open(sys.argv[1])):
    for i, c in enumerate(line):
        if line.count(str(i)) != int(c):
            print(0)
            break
    else:
        print(1)

#from collections import Counter
#
#for line in (l.strip() for l in open(sys.argv[1])):
#    print(int(all(int(line[int(i):int(i)+1] or 0) == v for i,v in Counter(line).items())))
