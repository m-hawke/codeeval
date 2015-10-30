import sys

ROMAN_BASE_VALUES = {
    'I' : 1,
    'V' : 5,
    'X' : 10,
    'L' : 50,
    'C' : 100,
    'D' : 500,
    'M' : 1000,
}


for line in open(sys.argv[1]):
    line = line.strip()
    pairs = [(int(line[i]), ROMAN_BASE_VALUES[line[i+1]])
                for i in range(0, len(line), 2)]

    total = pairs[-1][0] * pairs[-1][1]
    for i in range(len(pairs)-1):
        if pairs[i+1][1] > pairs[i][1]:
            total -= pairs[i][0] * pairs[i][1]
        else:
            total += pairs[i][0] * pairs[i][1]
    print(total)
