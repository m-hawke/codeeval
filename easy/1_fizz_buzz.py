import sys

with open(sys.argv[1]) as f:
    for line in f:
        line = line.strip()
        if not line:
            continue

        X, Y, n = (int(x) for x in line.split())
        for i in range(1, n+1):
            fizz = (i % X == 0)
            buzz = (i % Y == 0)

            if i > 1:
                sys.stdout.write(' ')
            if fizz:
                sys.stdout.write('F')
            if buzz:
                sys.stdout.write('B')
            if not (fizz or buzz):
                sys.stdout.write(str(i))
        print('')
