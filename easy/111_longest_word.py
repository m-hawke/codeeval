import sys

for line in (l.strip() for l in open(sys.argv[1])):
    longest = ''
    longest_len = 0

    for word in line.split():
        if len(word) > longest_len:
            longest = word
            longest_len = len(word)
    print(longest)
