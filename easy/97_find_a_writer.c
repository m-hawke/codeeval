#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token, *key;

    while (fgets(line, 1024, file)) {
        key = index(line, '|') + 2;
        for (token=strtok(key, " "); token!=NULL; token=strtok(NULL, " ")) {
            printf("%c", line[atoi(token)-1]);
        }
        printf("\n");
    }

    return 0;
}
