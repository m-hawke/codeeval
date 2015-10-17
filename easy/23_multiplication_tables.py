MAX = 12

for row in range(1, MAX+1):
    vals = [row * unit for unit in range(1, MAX+1)]
    print(('{:2d}' + '{:4d}'*(MAX-1)).format(vals[0], *(vals[1:])))
