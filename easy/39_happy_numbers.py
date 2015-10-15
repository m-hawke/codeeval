import sys

for line in open(sys.argv[1]):
    history = []
    n = int(line)
    while True:
        history.append(n)
        n = sum(int(c)**2 for c in str(n))

        if n == 1:
            print(1)
            break

        if n in history:
            print(0)
            break
