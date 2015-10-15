#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token;

    while (fgets(line, 1024, file)) {
        int n = atoi(strtok(line, " "));
        int diffs[n];           /* N.B. variable-sized array */
        int diff, current, previous;
        int is_jolly = 1;

        bzero(diffs, sizeof(diffs));
        previous = atoi(strtok(NULL, " "));

        for (token=strtok(NULL, " "); token!=NULL; token=strtok(NULL, " ")) {
            current = atoi(token);
            diff = abs(current - previous);
            if ((0 < diff && diff < n) && (!diffs[diff])) {
                diffs[diff] = 1;
                previous = current;
            } else {
                /* Either this difference is out of range, or we've seen it
                 * before */
                is_jolly = 0;
                break;
            }
        }

        /* Check that all differences are present */
        if (is_jolly) {
            for (int i=1; is_jolly && i<n; i++)
                is_jolly = diffs[i];
        }

        printf("%s\n", is_jolly ? "Jolly" : "Not jolly");
    }

    return 0;
}
