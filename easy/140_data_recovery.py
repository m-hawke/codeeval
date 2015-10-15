import sys

for line in open(sys.argv[1]):
    words, positions = [s.split() for s in line.strip().split(';')]

    reordered_words = [None] * len(words)

    for word, position in zip(words, positions):
        reordered_words[int(position)-1] = word
    reordered_words[reordered_words.index(None)] = words[-1]
    print(' '.join(reordered_words))
