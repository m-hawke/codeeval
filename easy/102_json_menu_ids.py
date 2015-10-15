import sys
import re

pattern = re.compile(r'"id": (\d+)[^}]+"label":')
for line in open(sys.argv[1]):
    print(sum([int(x) for x in pattern.findall(line)]))

# json module is obviously slower than a hacky custom regex
#import sys
#import json
#
#for line in open(sys.argv[1]):
#        print(sum(x['id'] for x in json.loads(line)['menu']['items']
#                        if x and x.get('label')))
