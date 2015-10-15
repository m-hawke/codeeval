import sys
try:
    from string import maketrans
    codel_to_english = maketrans('abcdefghijklmnopqrstuvwxyz',
                                 'yhesocvxduiglbkrztnwjpfmaq')
except ImportError:
    # assume Python 3
    codel_to_english = { 97: 'y',  98: 'h',  99: 'e', 100: 's', 101: 'o',
                        102: 'c', 103: 'v', 104: 'x', 105: 'd', 106: 'u',
                        107: 'i', 108: 'g', 109: 'l', 110: 'b', 111: 'k',
                        112: 'r', 113: 'z', 114: 't', 115: 'n', 116: 'w',
                        117: 'j', 118: 'p', 119: 'f', 120: 'm', 121: 'a',
                        122: 'q'}

for line in open(sys.argv[1]):
    print(line.rstrip().translate(codel_to_english))
