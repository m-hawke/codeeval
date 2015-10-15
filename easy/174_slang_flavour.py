import sys
from itertools import cycle

phrases = cycle([', yeah!', ', this is crazy, I tell ya.', ', can U believe this?', ', eh?', ', aw yea.', ', yo.', '? No way!', '. Awesome!'])
replace = False

for line in open(sys.argv[1]):
    output = []
    for word in line.split():
        if word[-1] in ('.', '!', '?'):
            if replace:
                print(word[:-1] + next(phrases)),
            else:
                print(word),
            replace = not replace
        else:
            print(word),
    print("")

## The following is faster (and nicer), but uses slightly more memory, so lower
## ranking.
#for line in open(sys.argv[1]):
#    output = []
#    for word in line.split():
#        if word[-1] in ('.', '!', '?'):
#            if replace:
#                output.append(word[:-1] + next(phrases))
#            else:
#                output.append(word)
#            replace = not replace
#        else:
#            output.append(word)
#    print(' '.join(output))
