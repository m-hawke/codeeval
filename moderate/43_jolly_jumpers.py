import sys

for line in open(sys.argv[1]):
    g = (int(x) for x in line.split())
    n = next(g)
    diffs = [False] * n

    previous = next(g)
    for current in g:
        diff = abs(current - previous)
#        if (0 < diff < n) and (not diffs[diff]):
        if (0 < diff < n):  # for codeeval data, this is slightly faster
            diffs[diff] = True
            previous = current
        else:
            print("Not jolly")
            break
    else:
        # looks "jollyish", is it?
        print('Jolly' if all(diffs[1:]) else 'Not jolly')
