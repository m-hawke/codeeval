import sys

cache = [0, 1]
def fib(n):
    if n < len(cache):
        return cache[n]
    a = cache[-2]
    b = cache[-1]
    for i in range(n-len(cache)+1):
        cache.append(a + b)
        a = b
        b = cache[-1]
    return cache[-1]
        
for line in open(sys.argv[1]):
    print(fib(int(line)))
