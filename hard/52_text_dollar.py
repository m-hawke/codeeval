import sys

d = {
    0: 'Zero',
    1: 'One',
    2: 'Two',
    3: 'Three',
    4: 'Four',
    5: 'Five',
    6: 'Six',
    7: 'Seven',
    8: 'Eight',
    9: 'Nine',
    10: 'Ten',
    11: 'Eleven',
    12: 'Twelve',
    13: 'Thirteen',
    14: 'Fourteen',
    15: 'Fifteen',
    16: 'Sixteen',
    17: 'Seventeen',
    18: 'Eighteen',
    19: 'Nineteen',
    20: 'Twenty',
    30: 'Thirty',
    40: 'Forty',
    50: 'Fifty',
    60: 'Sixty',
    70: 'Seventy',
    80: 'Eighty',
    90: 'Ninety',
}

def text_amount(amount):
    '''Convert amount < 1000 to text'''
    result = []

    hundreds = amount // 100
    if hundreds:
        result.append(d[hundreds])
        result.append('Hundred')
    amount %= 100

    if amount:
        if amount in d:
            # this handles multiples of ten and 11 <= n <= 19
            result.append(d[amount])
        else:
            tens = amount // 10
            result.append(d[tens*10])
            amount %= 10
            result.append(d[amount])

    return result

def amount_to_text(amount):
    if amount == 0:
        return 'ZeroDollars'

    millions = amount // 1000000
    amount %= 1000000
    thousands = amount // 1000
    amount %= 1000

    result = []
    if millions:
        result.extend(text_amount(millions))
        result.append('Million')
    if thousands:
        result.extend(text_amount(thousands))
        result.append('Thousand')
    if amount:
        result.extend(text_amount(amount))
    result.append('Dollars')

    return ''.join(result)



if __name__ == '__main__':
    for line in open(sys.argv[1]):
        print(amount_to_text(int(line)))
