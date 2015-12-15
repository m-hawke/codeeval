import sys
import string

a = 'abcdefghijklm'
b = 'uvwxyznopqrst'
table = string.maketrans(a+b, b+a)

for line in sys.stdin:
    print(line.translate(table, '\n'))
