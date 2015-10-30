#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_LEN    1024

int roman_numeral_value(char numeral) {
    if (numeral == 'I') return 1;
    if (numeral == 'V') return 5;
    if (numeral == 'X') return 10;
    if (numeral == 'L') return 50;
    if (numeral == 'C') return 100;
    if (numeral == 'D') return 500;
    if (numeral == 'M') return 1000;
    return 0;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];

    while (fgets(line, LINE_LEN, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        int len = strlen(line);
        char *last_pair = line + len - 2;
        int total = atoi(last_pair) * roman_numeral_value(last_pair[1]);

        for (int i=0; i<len-2; i+=2) {
            int value = (atoi(line+i) * roman_numeral_value(line[i+1]));
            if (roman_numeral_value(line[i+3]) > roman_numeral_value(line[i+1]))
                value *= -1;
            total += value;
        }

        printf("%d\n", total);
    }

    return 0;
}
