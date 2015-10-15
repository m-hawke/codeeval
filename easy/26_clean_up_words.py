import sys
import re

#31.046/30.316
#pattern = re.compile(r'[a-z]+')
#for line in open(sys.argv[1]):
#    print(' '.join(pattern.findall(line.lower())))

pattern = re.compile(r'[A-Za-z]+')
for line in open(sys.argv[1]):
    print(' '.join(pattern.findall(line)).lower())
