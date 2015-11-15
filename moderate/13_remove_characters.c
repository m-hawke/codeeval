#include <stdio.h>
#include <string.h>

#define LINE_LEN    1024

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    char *token;

    while (fgets(line, LINE_LEN, file)) {
        char *characters = strrchr(line, ',');
        *characters = '\0';
        characters += 2;                            /* skip over "\0 " */
        characters[strlen(characters)-1] = '\0';    /* ditch new line */

        for (token=strtok(line, characters);
                token!=NULL;
                token=strtok(NULL, characters)) {
            printf(token);
        }
        printf("\n");
    }

    return 0;
}
