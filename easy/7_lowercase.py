import sys

#for line in open(sys.argv[1]):
#    print line.lower()

print ''.join(s.lower() for s in open(sys.argv[1])),
