#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE   1024

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];

    while (fgets(line, LINE_SIZE, file)) {
        int count = 0;
        int n = atoi(line);
        while (n>0) {
            count += (n & 1);
            n >>= 1;
        }
        printf("%d\n", count);
    }

    return 0;
}
