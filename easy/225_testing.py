import sys

priorities = {
    0: 'Done',
    1: 'Low',
    2: 'Low',
    3: 'Medium',
    4: 'Medium',
    5: 'High',
    6: 'High'
}

for line in sys.stdin:
    dev_string, design_string = line.strip().split(' | ')
    bug_count = sum(a!=b for a,b in zip(dev_string, design_string))
    print(priorities.get(bug_count, 'Critical'))
