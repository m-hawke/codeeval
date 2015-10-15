import sys
import re

pattern = re.compile(r'''^("?[a-zA-Z0-9+\\!#$%&'*+-/=? ^_`.{|}~]+"?|"[a-zA-Z0-9+@\\!#$%&'*+-/=? ^_`.{|}~]+"?)@[a-zA-Z0-9+]+(\.[a-zA-Z0-9+]+)*$''')

for line in open(sys.argv[1]):
    print(str(pattern.match(line.strip()) != None).lower())

## The following is more readable, but codeeval ranks it lower due to higher
## execution time and memory usage.
#local_pattern = re.compile(r'''^"?[a-zA-Z0-9+\\!#$%&'*+-/=? ^_`.{|}~]+"?$|^"[a-zA-Z0-9+@\\!#$%&'*+-/=? ^_`.{|}~]+"?$''')
#domain_pattern = re.compile(r'^[a-zA-Z0-9+]+(\.[a-zA-Z0-9+]+)*$')

#for line in open(sys.argv[1]):
#    valid = False
#    local_part, _, domain_part = line.strip().rpartition('@')
#
#    if (domain_pattern.match(domain_part) and
#        local_pattern.match(local_part)):
#        valid = True
#
#    print(str(valid).lower())
