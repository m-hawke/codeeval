import sys

def is_prime(n):
    if n <= 1:
        return False
    if n <= 3:
        return True
    if n%2 == 0 or n%3 == 0:
        return False
    if n < 25:
        return True
    for i in range(3, int(n**0.5)+1, 2):
        if n%i==0:
            return False
    return True

from itertools import count
def gen_mersennes():
    c = count()
    while True:
        x = 2**next(c) - 1
        if is_prime(x):
            yield x

g = gen_mersennes()
mersennes = list(next(g) for i in range(5))

# Don't even need any of the above...  the 5th mersenne number is 8191, well
# over the constraint of 3000  in the question.
# The following comprehension is not efficient as it always traverses the whole
# list, however, it's so short that it's not going to matter.
    
for line in open(sys.argv[1]):
    print(', '.join(str(mersenne) for mersenne in mersennes if mersenne < int(line)))
