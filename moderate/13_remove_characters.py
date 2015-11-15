import sys
    
for line in sys.stdin:
    words, characters = line.split(', ')
#    print(words.translate(None, characters))                   # Python 2
    print(words.translate({ord(c):None for c in characters}))   # Python 3
