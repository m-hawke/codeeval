import sys

for line in open(sys.argv[1]):
    line = line.split()
    N, M = int(line[0]), int(line[1])

    locked_doors = 0
    last_door_adjustment = +1

    if M > 1:
        if (M-1) % 2:     # odd
            locked_doors = N//2 + N//3 - N//6 - N//6
            if (N%6) and ((N%2 == 0) or (N%3 == 0)):
                last_door_adjustment = -1
        else:               # even
            locked_doors = N//2 - N//6
            if (N%6) and (N%2 == 0):
                last_door_adjustment = -1

    locked_doors += last_door_adjustment
    print(N - locked_doors)

## Slow, iterative method...
#UNLOCKED = 0
#LOCKED = 1
#
#for line in open(sys.argv[1]):
#    line = line.split()
#    N, M = int(line[0]), int(line[1])
#
#    doors = [UNLOCKED] * N
#
#    for m in range(M-1):
#        for n in range(1, N, 2):
#            doors[n] = LOCKED
#        for n in range(2, N, 3):
#            doors[n] ^= 1
#
#    doors[N-1] ^= 1
#
#    print(doors.count(UNLOCKED))
