#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];

    while (fgets(line, 1024, file)) {
        int N = atoi(line);
        int M = atoi(strchr(line, ',') + 1);

        printf("%d\n", (N - (N/M)*M));
    }

    return 0;
}
