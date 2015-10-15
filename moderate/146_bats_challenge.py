import sys

BUILDING_MARGIN = 6

for line in open(sys.argv[1]):
    data = [int(s) for s in line.split()]
    l, d, n, bats = data[0], data[1], data[2], sorted(data[3:])

    n_bats = 0
    start = BUILDING_MARGIN
    for end in bats:
        n_bats += ((end-start-d)//d + 1)
        start = end

    # handle the final segment
    end = l - BUILDING_MARGIN
    if start <= end:
        n_bats += ((end-start)//d + 1)

    print(n_bats - len(bats))
