import sys

def is_luhn_valid(card_number):
    digits = [int(d) for d in card_number]
    checksum = sum(digits[-1::-2])  # sum of odd digits

    for d in digits[-2::-2]:        # even digits
        checksum += sum(int(x) for x in str(d*2))
    return checksum % 10 == 0

for line in open(sys.argv[1]):
    print(int(is_luhn_valid(line.strip().replace(' ', ''))))
