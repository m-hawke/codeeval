# Best for Python 2
import sys
from urlparse import urlparse, unquote

for line in sys.stdin:
    uri_1, uri_2 = [urlparse(unquote(uri)) for uri in line.strip().split(';')]

    host_1, _, port_1 = uri_1.netloc.partition(':')
    host_2, _, port_2 = uri_1.netloc.partition(':')

    print((uri_1.scheme == uri_2.scheme) and
          (host_1 == host_2) and
          ((port_1 if port_1 else '80') == (port_2 if port_2 else '80')) and
          (uri_1.path == uri_2.path) and
          (uri_1.params == uri_2.params) and
          (uri_1.query == uri_2.query) and
          (uri_1.fragment == uri_2.fragment))


## Best for Python 3, but not as robust as above.
#import sys 
#from urllib.parse import unquote
#
#for line in sys.stdin:
#    uri_1, uri_2 = [unquote(uri) for uri in line.strip().split(';')]
#
#    scheme_1, _, rest = uri_1.partition('://') 
#    host_1, sep, rest = rest.partition(':')
#    if not sep:
#        host_1, sep, rest = host_1.partition('/')
#        port_1 = '80'
#    else:
#        port_1, sep, rest = rest.partition('/')
#    path_1 = rest
#
#    scheme_2, _, rest = uri_2.partition('://')
#    host_2, sep, rest = rest.partition(':')
#    if not sep:
#        host_2, sep, rest = host_2.partition('/')
#        port_2 = '80'
#    else:
#        port_2, sep, rest = rest.partition('/')
#    path_2 = rest
#
#    print((scheme_1.lower() == scheme_2.lower()) and
#          (host_1.lower() == host_2.lower()) and
#          (port_1 == port_2) and
#          (path_1 == path_2))


## My preference, but not codeeval's 
#import re
#from urlparse import unquote
#
#pattern = re.compile(r'(?P<scheme>.+)://(?P<host>[^:/]+):?(?P<port>\d*)(?P<path>.*$)')
#
#for line in sys.stdin:
#    uri_1, uri_2 = [unquote(uri) for uri in line.strip().split(';')]
#
#    m1 = pattern.match(uri_1)
#    m2 = pattern.match(uri_2)
#    if m1 and m2:
#        d1 = m1.groupdict()
#        d2 = m2.groupdict()
#        print((d1['scheme'].lower() == d2['scheme'].lower()) and
#              (d1['host'].lower() == d2['host'].lower()) and
#              (d1['port'] if d1['port'] else '80' ==
#                  d2['port'] if d2['port'] else '80') and
#              (d1['path'] == d2['path']))
#    else:
#        print(False)
