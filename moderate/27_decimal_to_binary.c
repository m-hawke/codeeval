#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LINE_SIZE   1024

char hex_digit_to_decimal(char digit) {
    digit = toupper(digit);
    if (digit >= '0' && digit <= '9')
        return digit - '0';
    else if (digit >= 'A' && digit <= 'F')
        return digit - 'A' + 10;
    else
        return (char)-1;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];
    char hex_buf[10+1];
    int hex_ints[] = {
           0,    1,   10,   11,  100,  101,  110, 111,
        1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111
    };

    while (fgets(line, LINE_SIZE, file)) {
        sprintf(hex_buf, "%X", atoi(line));
        for (char *p=hex_buf; *p; p++)
            printf((p == hex_buf) ? "%d" : "%04d",
                        hex_ints[hex_digit_to_decimal(*p)]);
        printf("\n");
    }

    return 0;
}
