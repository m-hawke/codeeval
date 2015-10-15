#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token;

    while (fgets(line, 1024, file)) {
        char *digits[50];
        int digit_count = 0;
        int n = 0;

        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';    // get rid of new line

        for (token=strtok(line, ","); token!=NULL; token=strtok(NULL, ",")) {
            if (isdigit(token[0]))
                digits[digit_count++] = token;
            else
                n = printf("%s%s", (n>0) ? "," : "", token);
        }

        if (digit_count > 0) {
            if (n>0)        // at least 1 word was printed
                printf("|");
            n = 0;
            for (int i=0; i<digit_count; i++)
                n = printf("%s%s", (n>0) ? "," : "", digits[i]);
        }
        printf("\n");
    }

    return 0;
}
