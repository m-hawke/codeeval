#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token;

    char *lookup[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    while (fgets(line, 1024, file)) {
        for (token=strtok(line, ";"); token!=NULL; token=strtok(NULL, ";")) {
            if (token[strlen(token)-1] == '\n')
                token[strlen(token)-1] = '\0';
            for (int i=0; i< 10; i++)
                if (!strcmp(token, lookup[i]))
                    printf("%d", i);
        }
        printf("\n");
    }

    return 0;
}
