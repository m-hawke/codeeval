import sys

for line in (l.strip() for l in open(sys.argv[1])):
    if line:
        S, t = line.split(',')
        print(S.rfind(t))
