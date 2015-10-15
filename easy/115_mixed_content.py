import sys


for line in open(sys.argv[1]):
    words = []
    digits = []
    for s in line.strip().split(','):
        if s[0].isdigit():
            digits.append(s)
        else:
            words.append(s)

    join_char = '|' if (words and digits) else ''
    print(join_char.join((','.join(words), ','.join(digits))))
    
        
