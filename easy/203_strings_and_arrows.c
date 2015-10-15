#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define ARROW_LENGTH    5
#define ARROW_LEFT      "<--<<"
#define ARROW_RIGHT     ">>-->"

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];

    while (fgets(line, 1024, file)) {
        int count = 0;
        int i = 0;

        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';    // get rid of new line

        while (i < (strlen(line) - ARROW_LENGTH + 1)) {
            if ((!strncmp(&line[i], ARROW_LEFT, ARROW_LENGTH)) ||
                (!strncmp(&line[i], ARROW_RIGHT, ARROW_LENGTH))) {
                count++;
                i += (ARROW_LENGTH - 1);
            }
            else
                i++;
        }

        printf("%d\n", count);
    }

    return 0;
}
