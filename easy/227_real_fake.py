import sys

for line in sys.stdin:
    digits = [int(d) for d in line.strip().replace(' ', '')]
    print('Fake' if (sum(digits) + sum(digits[::2])) % 10 else 'Real')
