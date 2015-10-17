#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS   20

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token;
    bool first;
    char *previous_num;

    while (fgets(line, 1024, file)) {
        first = true;
        previous_num = "";

        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        for (token=strtok(line, ","); token!=NULL; token=strtok(NULL, ",")) {
            if (strcmp(token, previous_num)){
                if (first)
                    first = false;
                else
                    printf(",");

                printf("%s", token);
                previous_num = token;
            }
        }
        printf("\n");
    }

    return 0;
}
