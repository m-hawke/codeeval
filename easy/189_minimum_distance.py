import sys

# Start from the median position and check backwards until the sum of
# differences starts increasing (minima found). This assumes that the median is
# *always* greater than the optimal position... not sure whether this is always
# true, however, it is for all tests seen.
for line in open(sys.argv[1]):
    houses = [int(x) for x in line.split()[1:]]

    # Sort required for calculating the median, not sum of differences, but
    # doesn't hurt.
    houses.sort()
    mid, odd = divmod(len(houses), 2)
    if odd:
        median = houses[mid]
    else:
        median = (houses[mid-1] + houses[mid]) // 2

    diff = sum(abs(median-x) for x in houses)
    i = median-1
    while i >= 0:
        next_diff = sum(abs(i-x) for x in houses)
        if diff < next_diff:
            break
        diff = next_diff
        i -= 1

    print(diff)

## Start from the minimum position and check until sum of differences starts
## increasing (minima found).
#for line in open(sys.argv[1]):
#    houses = [int(x) for x in line.split()[1:]]
#    min_house = min(houses)
#
#    diff = sys.maxsize
#    i = min_house
#    while i < 10000:
#        this_diff = sum(abs(i-x) for x in houses)
#        if this_diff > diff:
#            break
#        diff = this_diff
#        i += 1
#
#    print(diff)
