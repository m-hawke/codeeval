import sys

trans_table = '                                                                 abcdefghijklmnopqrstuvwxyz      abcdefghijklmnopqrstuvwxyz                                                                                                                                     '
# uncomment following line for Python 3
#trans_table = {i:c for i,c in enumerate(trans_table)}

for line in open(sys.argv[1]):
    print(' '.join(line.translate(trans_table).split()))
