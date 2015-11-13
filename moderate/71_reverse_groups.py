import sys

for line in sys.stdin:
    items, k = line.rsplit(';')
    k = int(k)
    items = items.split(',')
    result = []
    for l in [items[i:i+k] for i in range(0, len(items), k)]:
        result.extend(l[::-1] if len(l) == k else l)
    print(','.join(result))
