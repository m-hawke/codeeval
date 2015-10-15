import sys

for line in open(sys.argv[1]):
    n_days, data = line.split(';')
    n_days = int(n_days)
    data = [int(x) for x in data.split()]

#    m = max([sum(data[i:i+n_days]) for i in range(len(data) - n_days + 1)])
#    print(m if m > 0 else 0)

#    totals = []
#    for i in range(0, len(data) - n_days + 1):
#        totals.append(sum(data[i:i+n_days]))
#    m = max(totals)
#    print m if m > 0 else 0

    max_ = sum(data[0:n_days])
    total = max_
    for i in range(1, len(data) - n_days + 1):
        total -= data[i-1]
        total += data[i+n_days-1]
        if total > max_:
            max_ = total
    print(max(max_, 0))
