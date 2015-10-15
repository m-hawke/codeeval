import sys

for line in open(sys.argv[1]):
    longest = ''
    for word in line.split():
       if len(word) > len(longest):
           longest = word

    for i, c in enumerate(longest):
        print '*' * i + c,
    print
