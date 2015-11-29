#include <stdio.h>
#include <string.h>
#include <fnmatch.h>

#define LINE_LEN    2048

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    char *token;

    while (fgets(line, LINE_LEN, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        int match = 0;
        char *pattern = strtok(line, " ");
        for (token=strtok(NULL, " "); token!=NULL; token=strtok(NULL, " ")) { 
            if (!fnmatch(pattern, token, 0)) {
                printf("%s%s", match ? " " : "", token);
                match = 1;
            }
        }
        if (!match)
            printf("-\n");
        else
            printf("\n");
    }

    return 0;
}
