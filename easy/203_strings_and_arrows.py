import sys

arrow_length = 5
arrow_left = '<--<<'
arrow_right = '>>-->'

for line in (l.strip() for l in open(sys.argv[1])):
    count = 0
    i = 0
    while i < len(line) - arrow_length + 1:
        if line[i:i+arrow_length] in (arrow_left, arrow_right):
            count += 1
            i += (arrow_length - 1)
        else:
            i += 1
    print(count)

#for line in (l.strip() for l in open(sys.argv[1])):
#    count = 0
#    for i in range(len(line)-arrow_length+1):
#        if line[i:i+arrow_length] in (arrow_left, arrow_right):
#            count += 1
#    print count

