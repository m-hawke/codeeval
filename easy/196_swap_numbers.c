#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token;

    while (fgets(line, 1024, file)) {
        int last_pos;
        char tmp;
        int first = 1;
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';    // get rid of new line
        for (token=strtok(line, " "); token!=NULL; token=strtok(NULL, " ")) {
            tmp = token[0];
            last_pos = strlen(token) - 1;
            token[0] = token[last_pos];
            token[last_pos] = tmp;
            printf("%s%s", (first) ? "" : " ", token);
            first = 0;
        }
        printf("\n");
    }

    return 0;
}
