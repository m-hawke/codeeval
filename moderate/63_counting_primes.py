import sys

#def is_prime(n):
#    if n <= 1:
#        return False
#    if n <= 3:
#        return True
#    if n%2 == 0 or n%3 == 0:
#        return False
#    if n < 25:
#        return True
#    for i in range(3, int(n**0.5)+1, 2):
#        if n%i==0:
#            return False
#    return True

def count_primes(lower, upper):
#    return len([n for n in range(lower, upper+1) if is_prime(n)])
    count = 0
    for n in range(lower, upper+1):
        if n <= 1:
            continue
        if n <= 3:
            count += 1
            continue
        if n%2 == 0 or n%3 == 0:
            continue
        if n < 25:
            count += 1
            continue
        for i in range(3, int(n**0.5)+1, 2):
            if n%i==0:
                break
        else:
            count += 1

    return count
        

for line in open(sys.argv[1]):
    lower, upper = line.split(',')
    print(count_primes(int(lower), int(upper)))
