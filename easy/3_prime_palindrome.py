def is_prime(n):
    if n%2 == 0:
        return False
    for i in range(3,n//2+1,2):
        if n%i==0:
            return False
    return True

max_ = 999
for i in range(max_, 0, -1):
    if str(i) == str(i)[::-1] and is_prime(i):
        print(i)
        break
