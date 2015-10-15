#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int i;
    char current;

    while (fgets(line, 1024, file)) {
        i = 0;
        current = line[0];

        while (i < strlen(line)) {
            if (line[i] != current) {
                printf("%c", current);
                current = line[i];
            }
            i++;
        }
        printf("%c", current);
    }

    return 0;
}
