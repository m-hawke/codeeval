#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int n, p1, p2;

    while (fgets(line, 1024, file)) {
        sscanf(line, "%d,%d,%d", &n, &p1, &p2);
        printf("%s\n",  ((n >> (p1-1) & 1) == (n >> (p2-1) & 1)) ? "true" : "false");
    }

    return 0;
}

