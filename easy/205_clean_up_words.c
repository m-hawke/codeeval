#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char cleaned_line[1024];
    bool in_word = false;
    int i, j;

    while (fgets(line, 1024, file)) {
        for (i=0,j=0; i<strlen(line); i++) {
            if (isalpha(line[i])) {
                if (!in_word && j>0)
                    cleaned_line[j++] = ' ';
                cleaned_line[j++] = tolower(line[i]);
                in_word = true;
            }
            else
                in_word = false;
        }
        cleaned_line[j] = '\0';
        printf("%s\n", cleaned_line);
    }

    return 0;
}
