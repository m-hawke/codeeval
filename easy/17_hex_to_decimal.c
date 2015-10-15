#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int n;

    while (fgets(line, 1024, file)) {
        sscanf(line, "%x", &n);
        printf("%d\n", n);
    }

    return 0;
}
