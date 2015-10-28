import sys

primes = [2,3,5,7,11,13,17,19,23]
def gen_primes(upper):
    for n in primes:
        if n <= upper:
            yield n
        else:
            break

    for n in range(n+1, upper+1):
        if n%2 == 0:
            continue
        for i in range(3, int(n**0.5)+1, 2):
            if n%i==0:
                break
        else:
            primes.append(n)
            yield n

for line in open(sys.argv[1]):
    upper = int(line)
    print(','.join(str(n) for n in gen_primes(upper-1)))
