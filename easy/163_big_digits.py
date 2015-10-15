import sys

CHAR_WIDTH = 5

font = '''\
-**----*--***--***---*---****--**--****--**---**--
*--*--**-----*----*-*--*-*----*-------*-*--*-*--*-
*--*---*---**---**--****-***--***----*---**---***-
*--*---*--*-------*----*----*-*--*--*---*--*----*-
-**---***-****-***-----*-***---**---*----**---**--
--------------------------------------------------
'''.split()

for line in open(sys.argv[1]):
    digits = [int(c) for c in line if '0' <= c <= '9']
    for row in font:
        for digit in digits:
            sys.stdout.write(row[digit*CHAR_WIDTH:digit*CHAR_WIDTH+CHAR_WIDTH])
        print("")
