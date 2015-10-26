#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define LINE_LEN    1024

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    char *token;

    while (fgets(line, LINE_LEN, file)) {
        char *p = rindex(line, ' ');
        int m = atoi(p+1);
        *p = '\0';
        for (; m>0 && p; m--) {
            if (p = rindex(line, ' '))
                *p = '\0';
        }

        if (m == 0)
            printf("%s\n", p ? p+1 : line);
    }

    return 0;
}
