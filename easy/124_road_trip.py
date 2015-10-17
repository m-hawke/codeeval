import sys
import re

pattern = re.compile('[^0-9 ]')

for line in open(sys.argv[1]):
    route = sorted(int(x) for x in pattern.sub('', line).split())
    results = [str(route[0])]
    for i in range(1, len(route)):
        results.append(str(route[i] - route[i-1]))
    print(','.join(results))
