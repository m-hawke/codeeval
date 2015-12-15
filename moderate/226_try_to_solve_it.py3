import sys

a = 'abcdefghijklm'
b = 'uvwxyznopqrst'
table = {ord(k):v for k,v in zip(a+b,b+a)}
table[ord('\n')] = None

for line in sys.stdin:
    print(line.translate(table))
