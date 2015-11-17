#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_LEN    1024
#define MAX_NUMBERS 50

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    char *token;
    int numbers[MAX_NUMBERS];

    while (fgets(line, LINE_LEN, file)) {
        int N = atoi(line);
        memset(numbers, 0, sizeof(numbers));
        int i = 0;
        for (token=strtok(strchr(line, ';')+1, ",");
                token!=NULL; token=strtok(NULL, ",")) {
            int n = atoi(token);
            if (numbers[n] != 0) {
                printf("%d\n", n);
                break;
            }
            numbers[n] = 1;
        }
    }

    return 0;
}
