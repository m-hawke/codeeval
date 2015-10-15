#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int x, y, n;
    bool fizz, buzz;

    while (fgets(line, 1024, file)) {
        sscanf(line, "%d %d %d\n", &x, &y, &n);
        for (int i=1; i<=n; i++) {
            fizz = (i % x == 0);
            buzz = (i % y == 0);

            if (i > 1)
                printf(" ");
            if (fizz)
                printf("F");
            if (buzz)
                printf("B");
            if (!(fizz || buzz))
                printf("%d", i);
        }
        printf("\n");
    }

    return 0;
}
