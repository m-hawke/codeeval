#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];

    int sum = 0;
    while (fgets(line, 1024, file)) {
        sum += atoi(line);
    }
    printf("%d\n", sum);
    return 0;
}

