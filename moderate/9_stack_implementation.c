#include <stdio.h>
#include <string.h>

#define LINE_LEN    1024
#define MAX_NUMBERS 100

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    char *token;
    char *numbers[MAX_NUMBERS];

    while (fgets(line, LINE_LEN, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        int n = 0;
        for (token=strtok(line, " "); token!=NULL; token=strtok(NULL, " ")) {
            numbers[n++] = token;
        }

        for (int i=n-1; i>=0; i-=2)
            printf("%s%s", (i<(n-1) ? " " : ""), numbers[i]);
        printf("\n");
    }

    return 0;
}
