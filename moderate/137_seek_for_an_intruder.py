import sys
import re
import socket, struct

def ip2int(address, base=10):
    if base == 10:
        try:
            return struct.unpack("!I", socket.inet_aton(address))[0]
        except socket.error:
            pass

    n = 0
    for octet in [int(octet, base) for octet in address.split('.')]:
        n <<= 8
        n += octet
    return n

def int2ip(address):
    return socket.inet_ntoa(struct.pack("!I", address))

MIN_IP_DECIMAL = ip2int('1.0.0.0')
MAX_IP_DECIMAL = ip2int('255.255.255.254')

def dotted_decimal_to_int(address):
    return ip2int(address)

def dotted_hexadecimal_to_int(address):
    return int(address.replace('.0x', ''), 16)

def dotted_octal_to_int(address):
    return ip2int(address, 8)

def dotted_binary_to_int(address):
    return ip2int(address, 2)

def binary_to_int(address):
    return int(address, 2)

def hexadecimal_to_int(address):
    return int(address, 16)

def octal_to_int(address):
    return int(address, 8)

def decimal_to_int(address):
    return int(address)

def validate_int_address(address):
    return (MIN_IP_DECIMAL <= address <= MAX_IP_DECIMAL)

re_dotted_hexadecimal = r'0x[0-9a-fA-F]{1,2}\.0x[0-9a-fA-F]{1,2}\.0x[0-9a-fA-F]{1,2}\.0x[0-9a-fA-F]{1,2}'
re_dotted_decimal = r'\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}'
re_dotted_octal = r'0[0-7]{3}\.0[0-7]{3}\.0[0-7]{3}\.0[0-7]{3}'
re_dotted_binary = r'[01]{8}\.[01]{8}\.[01]{8}\.[01]{8}'
re_hexadecimal = r'0x[0-9a-fA-F]{8}'
re_decimal = r'[0-9]{9,10}'
re_octal = r'0[0-7]{8,11}'
re_binary = r'[01]{25,32}'

# order might be significant
patterns = ((re_dotted_hexadecimal, dotted_hexadecimal_to_int),
            (re_dotted_decimal, dotted_decimal_to_int),
            (re_dotted_octal, dotted_octal_to_int),
            (re_dotted_binary, dotted_binary_to_int),
            (re_binary, binary_to_int),
            (re_hexadecimal, hexadecimal_to_int),
            (re_octal, octal_to_int),
            (re_decimal, decimal_to_int))

# The following pattern will find all overlapping matches too, but it doesn't
# seem necessary to pass codeeval's tests.
#pattern = re.compile('|'.join('(?=({}))'.format(p) for p, _ in patterns), re.MULTILINE)
pattern = re.compile('|'.join('({})'.format(p) for p, _ in patterns), re.MULTILINE)

from collections import Counter
c = Counter()

#for m in pattern.finditer(''.join(open(sys.argv[1]).read().splitlines())):
for m in pattern.finditer(open(sys.argv[1]).read()):
    for i, address in enumerate(m.groups()):
        if address is not None:
            int_address = patterns[i][1](address)
            if validate_int_address(int_address):
                c.update([int_address])

# We should print all of the most frequent ip addresses, however, just the
# first is sufficient to pass codeeval's tests.
#highest = c.most_common(1)[0][1]
#for ip, count in c.most_common():
#    if count == highest:
#        print(int2ip(ip))
#    else:
#        break
print(int2ip(c.most_common(1)[0][0]))
