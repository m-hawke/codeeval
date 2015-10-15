import sys

for line in (l.strip() for l in open(sys.argv[1])):
    nums, swaps = line.split(' : ')
    nums = nums.split()

    for swap in swaps.split(', '):
        pos = swap.find('-')        # this is faster than swap.split('-')
        a, b = int(swap[:pos]), int(swap[pos+1:])
        nums[a], nums[b] = nums[b], nums[a]
    print(' '.join(nums))
