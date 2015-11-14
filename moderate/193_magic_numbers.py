import sys

#def gen_magic_numbers(A, B):
#    for n in range(A, B+1):
#        digits = str(n)
#
#        # no repetition of digits permitted
#        if len(digits) > len(set(digits)):
#            continue
#
#        seen = [False] * len(digits)
#        pos = 0
#        while True:
#            pos = (pos + int(digits[pos])) % len(digits)
#            if seen[pos]:
#                break
#            seen[pos] = True
#            if pos == 0:
#                break
#        if (pos == 0) and all(seen):
#            yield n

# Since there are so few magic numbers (89 <= 10000) just precalculate them...
#magic_numbers = set(gen_magic_numbers(1, 10000))
# ... or even better, hard code them in the following list.
magic_numbers = [
    1, 2, 3, 4, 5, 6, 7, 8, 9, 13, 15, 17, 19, 31, 35, 37, 39, 51, 53, 57, 59,
    71, 73, 75, 79, 91, 93, 95, 97, 147, 174, 258, 285, 417, 471, 528, 582,
    714, 741, 825, 852, 1263, 1267, 1623, 1627, 2316, 2356, 2396, 2631, 2635,
    2639, 2671, 2675, 2679, 2716, 2756, 2796, 3126, 3162, 3526, 3562, 3926,
    3962, 5263, 5267, 5623, 5627, 6231, 6235, 6239, 6271, 6275, 6279, 6312,
    6352, 6392, 6712, 6752, 6792, 7126, 7162, 7526, 7562, 7926, 7962, 9263,
    9267, 9623, 9627
]

for line in sys.stdin:
    A, B = line.split()
    # It's faster to iterate over the magic numbers and check that they are in
    # range than the other way around.
    l = [n for n in magic_numbers if int(A) <= n <= int(B)]
    print(' '.join((str(x) for x in l)) if l else -1)
