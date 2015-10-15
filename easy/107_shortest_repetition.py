import sys

for line in (l.strip() for l in open(sys.argv[1])):
    length = len(line)
    for k in range(1, length+1):
        if length % k == 0:     # optimisation: only try equal length segments
            if len(set([line[i:i+k] for i in range(length)[::k]])) == 1:
                print(k)
                break
