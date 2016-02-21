import sys

face_value = {str(i):i for i in range(1,11)}
face_value.update({'J': 11, 'Q': 12, 'K': 13, 'A': 14})

#for line in sys.stdin:
for line in open(sys.argv[1]):
    card1, card2, _, trumps = line.split()
    c1 = (face_value[card1[:-1]], card1[-1])
    c2 = (face_value[card2[:-1]], card2[-1])

    output = []

    if c1[1] == c2[1]:    # same suit, trumps don't matter
        output.append(card1 if c1[0] >= c2[0]  else card2)
        if c1[0] == c2[0]:
            output.append(card2)
    else:
        if c1[1] == trumps:
            output.append(card1)
        elif c2[1] == trumps:
            output.append(card2)
        else:
            output.append(card1 if c1[0] >= c2[0] else card2)
            if c1[0] == c2[0]:
                output.append(card2)

    print(' '.join(output))
