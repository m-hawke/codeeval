import sys

morse_decode_dict = {
    ' ': ' ',
    '-': 'T',
    '--': 'M',
    '---': 'O',
    '-----': '0',
    '----.': '9',
    '---..': '8',
    '---...': ':',
    '--.': 'G',
    '--.-': 'Q',
    '--..': 'Z',
    '--..--': ',',
    '--...': '7',
    '-.': 'N',
    '-.-': 'K',
    '-.--': 'Y',
    '-.--.-': '(',
    '-.-.': 'C',
    '-.-.-.': ';',
    '-..': 'D',
    '-..-': 'X',
    '-..-.': '/',
    '-...': 'B',
    '-....': '6',
    '-....-': '-',
    '.': 'E',
    '.-': 'A',
    '.--': 'W',
    '.---': 'J',
    '.----': '1',
    '.----.': "'",
    '.--.': 'P',
    '.-.': 'R',
    '.-.-.-': '.',
    '.-..': 'L',
    '..': 'I',
    '..-': 'U',
    '..---': '2',
    '..--.-': '_',
    '..--..': '?',
    '..-.': 'F',
    '...': 'S',
    '...-': 'V',
    '...--': '3',
    '....': 'H',
    '....-': '4',
    '.....': '5'
}

# handle word separator (double space) which is '' after splitting the input
# line on a single space
morse_decode_dict[''] = ' ' 

# In Python 3 the following is slower and uses more memory.
#for line in open(sys.argv[1]):
#    for morse in line.strip().split(' '):   # '  ' -> ''
#        sys.stdout.write(morse_decode_dict[morse])
#    sys.stdout.write('\n')

# In Python 2 the following is faster, but uses more memory so its ranking is
# lower. But this is better in Python 3.
for line in open(sys.argv[1]):
    msg = []
    for morse in line.strip().split(' '):   # '  ' -> ''
        msg.append(morse_decode_dict[morse])
    print(''.join(msg))
