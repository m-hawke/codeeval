import sys

for line in open(sys.argv[1]):
    l = line.split()
    lower = 0
    upper = int(l[0])
    for answer in l[1:]:
        guess = lower + ((upper - lower + 1) / 2)
        if answer == 'Lower':
            upper = guess - 1
        elif answer == 'Higher':
            lower = guess + 1
        else:
            print(guess)
