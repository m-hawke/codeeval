import sys

# LCD segments for each digit with decimal point off
segments = {
    '0': 0b11111100,
    '1': 0b01100000,
    '2': 0b11011010,
    '3': 0b11110010,
    '4': 0b01100110,
    '5': 0b10110110,
    '6': 0b10111110,
    '7': 0b11100000,
    '8': 0b11111110,
    '9': 0b11110110,
}

for line in sys.stdin:
    lcd_segments, number = line.strip().split(';')
    lcd_segments = [int(x, 2) for x in lcd_segments.split()]

    digits = []
    for digit in number:
        if digit == '.':
            digits[-1] += 1     # turn on decimal point for preceding digit
        else:
            digits.append(segments[digit])

    for i in range(len(lcd_segments)-len(digits)+1):
        if all(digit & lcd_segment == digit
                    for digit, lcd_segment in zip(digits, lcd_segments[i:])):
            print(1)
            break
    else:
        print(0)
