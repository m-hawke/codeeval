import sys

#for line in open(sys.argv[1]):
#    it = iter(line.strip().split())
#    print(int(''.join(('1' if len(flag) == 2 else '0') * len(seq) for flag, seq in zip(it, it)), 2))

for line in open(sys.argv[1]):
    l = [len(s) for s in line.strip().split()]
    print(int(''.join(('0' if l[i] == 1 else '1') * l[i+1] for i in range(0, len(l), 2)), 2))
        
