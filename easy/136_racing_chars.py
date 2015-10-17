import sys

prev_pos = None
for line in (l.strip() for l in open(sys.argv[1])):
    pos = line.find('C')
    if pos == -1:
        pos = line.find('_')
    if prev_pos == pos or prev_pos is None:
        char = '|'
    elif prev_pos < pos:
        char = '\\'
    else:
        char = '/'
    print(line[:pos] + char + line[pos+1:])
    prev_pos = pos
