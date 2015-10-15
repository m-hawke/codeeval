#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token;
    int longest_length;
    char *longest;
    int length;

    while (fgets(line, 1024, file)) {
        line[strlen(line)-1] = '\0';
        longest_length = 0;
        longest = "";

        for (token=strtok(line, " "); token!=NULL; token=strtok(NULL, " ")) {
            length = strlen(token);
            if (length > longest_length) {
                longest_length = length;
                longest = token;
            }
        }
        printf("%s\n", longest);
    }

    return 0;
}
