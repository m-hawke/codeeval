import sys
for line in open(sys.argv[1]):
    print ' '.join(word[0].upper()+word[1:] for word in line.strip().split())
