#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int multiplier;

    while (fgets(line, 1024, file)) {
        int x = atoi(line);
        int n = atoi(strchr(line, ',') + 1);

        multiplier = 1;
        while (n * multiplier < x)
            multiplier ++;

        printf("%d\n", n * multiplier);
    }
    return 0;
}

