import sys
    
for line in sys.stdin:
    numbers, target_sum = line.split(';')
    numbers = [int(x) for x in numbers.split(',')]
    target_sum = int(target_sum)

    pairs = []
    for i_pos, i in enumerate(numbers[:-1]):
        if i + numbers[i_pos+1] > target_sum:
            # Because the number list is sorted there is no point in continuing
            # if the sum of any 2 consecutive numbers exceeds the target sum.
            break
        for j in numbers[i_pos+1:]:
            if i + j == target_sum:
                pairs.append((i,j))
                break

    print(';'.join('{},{}'.format(*pair) for pair in pairs) if pairs else 'NULL')
