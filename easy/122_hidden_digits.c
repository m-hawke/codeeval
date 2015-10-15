#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token;
    int n;

    while (fgets(line, 1024, file)) {
        n = 0;
        for (char *p=line; *p; p++) {
            if (*p >= 'a' && *p <= 'j')
                n = printf("%c", (*p - 'a') + '0');
            else if (*p >= '0' && *p <= '9')
                n = printf("%c", *p);
        }
        if (n == 0)     /* nothing was printed */
            printf("NONE");
        printf("\n");
    }

    return 0;
}
