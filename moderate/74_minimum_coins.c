#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE   1024

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];

    while (fgets(line, LINE_SIZE, file)) {
        int total = atoi(line);
        int coins = 0;

        coins += (total / 5);
        total %= 5;
        coins += total / 3;
        coins += total % 3;
        
        printf("%d\n", coins);
    }

    return 0;
}
