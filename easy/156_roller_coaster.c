#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int (*funcs[2])() = {toupper, tolower};
    int func = 0;

    while (fgets(line, 1024, file)) {
        func = 0;
        for (int i=0; i<strlen(line); i++) {
            if (isalpha(line[i])) {
                printf("%c", funcs[func](line[i]));
                func ^= 1;
            } else
                printf("%c", line[i]);
        }
    }

    return 0;
}
