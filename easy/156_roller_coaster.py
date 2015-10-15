import sys

for line in open(sys.argv[1]):
    funcs = [str.upper, str.lower]
    func = 0
    for c in line:
        if c.isalpha():
            sys.stdout.write((funcs[func](c)))
            func ^= 1
        else:
            sys.stdout.write(c)
