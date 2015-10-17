def is_prime(n):
    for i in range(2,n/2+1):
        if n%i==0:
            return False
    return True

primes = []
n_primes = 1000
n = 2
while n_primes > 0:
    if is_prime(n):
        primes.append(n)
        n_primes -= 1
    n += 1
print(sum(primes))
