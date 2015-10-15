#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NUMBERS 100

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token;
    int n_days;
    int data[MAX_NUMBERS];
    int data_length;
    int max, total;

    while (fgets(line, 1024, file)) {
        n_days = atoi(line);

        for (data_length=0, token=strtok(index(line, ';') + 1, " ");
             token!=NULL;
             token=strtok(NULL, " "), data_length++) {
            data[data_length] = atoi(token);
        }

        max = 0;
        for (int i=0; i<n_days; i++)
            max += data[i];
        total = max;

        for (int i=1; (i+n_days-1)<data_length; i++) {
            total -= data[i-1];
            total += data[i+n_days-1];
            if (total > max)
                max = total;
        }

        printf("%d\n", (max > 0) ? max : 0);
    }

    return 0;
}
