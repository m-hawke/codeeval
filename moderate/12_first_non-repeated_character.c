#include <stdio.h>
#include <string.h>

#define LINE_SIZE   1024
#define MAX_CHARS   128

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];

    while (fgets(line, LINE_SIZE, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        int counts[MAX_CHARS] = {0};
        for (char *c=line; *c; c++)
            counts[*c]++;

        for (char *c=line; *c; c++) {
            if (counts[*c] == 1) {
                printf("%c\n", *c);
                break;
            }
        }
    }

    return 0;
}
