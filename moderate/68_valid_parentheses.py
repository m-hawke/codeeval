import sys

# match closing and opening parens
PAREN_PAIRS = {')': '(', '}': '{', ']': '['}

for line in open(sys.argv[1]):
    valid = True
    stack = []
    for paren in line.strip():
        if paren in PAREN_PAIRS:
            try:
                if stack.pop() != PAREN_PAIRS[paren]:
                    valid = False
            except IndexError:
                valid = False   # attempt to pop an empty stack
            if not valid:
                break
        else:
            stack.append(paren)

    print(str(valid and len(stack) == 0))
