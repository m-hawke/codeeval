#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token;

    while (fgets(line, 1024, file)) {
        int i, n = 0;
        int numbers[20] = {0};
        int produce_result = 0;
        for (i=0, token=strtok(line, " ");
             token!=NULL;
             i++, token=strtok(NULL, " ")) {
            if (token[0] == '|') {
                produce_result = 1;
                n = 0;
                continue;
            }
            if (produce_result) {     // multiply and output
                printf("%s%d", (n>0) ? " " : "", atoi(token) * numbers[n]);
                n++;
            }
            else                // store for later multiplication
                numbers[i] = atoi(token);
        }
        printf("\n");
    }

    return 0;
}
