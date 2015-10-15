#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE       1024

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];

    int integers[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    while (fgets(line, LINE_SIZE, file)) {
        int n = atoi(line);
        for (int i=0; i < sizeof(integers)/sizeof(int); i++) {
            for (int j=0; j<n/integers[i]; j++)
                printf(symbols[i]);
            n %= integers[i];
        }
        printf("\n");
    }

    return 0;
}
