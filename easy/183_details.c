#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MIN(a, b)   ((a) < (b)) ? (a) : (b)

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token;

    while (fgets(line, 1024, file)) {
        int diff = INT_MAX;

        for (token=strtok(line, ","); token!=NULL; token=strtok(NULL, ",")) {
            /* The question guarantees that there is at least 1 X and Y in
             * every line, so boundary conditions are not considered here. */
            diff = MIN(diff, index(token, 'Y') - rindex(token, 'X') - 1);
        }
        printf("%d\n", diff);
    }

    return 0;
}
