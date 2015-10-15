#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];

    while (fgets(line, 1024, file)) {
        int n = atoi(line);
        int p1 = atoi(strchr(line, ',') + 1);
        int p2 = atoi(strchr((strchr(line, ',') + 1), ',') + 1);
        printf("%s\n",  ((n >> (p1-1) & 1) == (n >> (p2-1) & 1)) ? "true" : "false");

    }
    return 0;
}

