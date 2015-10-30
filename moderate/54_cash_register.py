import sys

AMOUNT_NAMES  = {
    1 : 'PENNY',
    5 : 'NICKEL',
    10 : 'DIME',
    25 : 'QUARTER',
    50 : 'HALF DOLLAR',
    100 : 'ONE',
    200 : 'TWO',
    500 : 'FIVE',
    1000 : 'TEN',
    2000 : 'TWENTY',
    5000 : 'FIFTY',
    10000 : 'ONE HUNDRED'
}
AMOUNTS = sorted(AMOUNT_NAMES, reverse=True)

for line in open(sys.argv[1]):
    price, tendered = line.split(';')
    change = int(round(float(tendered) * 100)) - int(round(float(price) * 100))

    if change < 0:
        print('ERROR')
    elif change == 0:
        print('ZERO')
    else:
        money = []
        for amount in AMOUNTS:
            n, change = divmod(change, amount)
            if n > 0:
                money.extend([AMOUNT_NAMES[amount]] * int(n))
        print(','.join(money))
