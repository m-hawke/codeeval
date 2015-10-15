import sys
from collections import Counter

#for line in open(sys.argv[1]):
#    matches = []
#    wines, letters = line.strip().split(' | ')
#    letters = Counter(letters)
#    for wine in wines.split():
#        w = Counter(wine)
#        if all(w.get(letter, 0) >= frequency for letter, frequency in letters.items()):
#            matches.append(wine)
#    print(' '.join(matches) if matches else False)
            

#for line in open(sys.argv[1]):
#    matches = []
#    wines, letters = line.strip().split(' | ')
#    for wine in wines.split():
#        l = list(letters)
#        for c in wine:
#            try:
#                l.remove(c)
#                if len(l) == 0:
#                    matches.append(wine)
#                    break
#            except:
#                pass
#    print ' '.join(matches) if matches else False


#
#    for wines, letters in line.split(' | '):
#        if sorted(''.join([c for c in word if c in letters])) == sorted(letters)

for line in open(sys.argv[1]):
    matches = []
    wines, letters = line.strip().split(' | ')
    for wine in wines.split():
        w = list(wine)
        for l in letters:
            try:
                w.remove(l)
            except:
                break
        else:
            matches.append(wine)
    print(' '.join(matches) if matches else False)

#for line in open(sys.argv[1]):
#    matches = []
#    wines, letters = line.strip().split(' | ')
#    letters = ''.join(sorted(letters))
#    for wine in wines.split():
#        print letters
#        print sorted(wine, cmp=lambda a,b: letters.index(a) if a in letters else -1)
#        if letters in ''.join(sorted(wine, cmp=lambda a,b: -1 if a in letters else 1)):
#            matches.append(wine)
#    print ' '.join(matches) if matches else False
