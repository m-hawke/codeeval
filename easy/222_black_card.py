import sys

for line in sys.stdin:
    players, n = line.split(' | ')
    n = int(n)
    players = players.split()

    while len(players) > 1:
        players.remove(players[n%len(players)-1])
    print(players[0])
