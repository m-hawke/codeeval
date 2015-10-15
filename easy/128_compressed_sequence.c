#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token;

    while (fgets(line, 1024, file)) {
        int previous = -1;      /* values can be 0-99 */
        int current;
        int count = 1;

        for (token=strtok(line, " "); token!=NULL; token=strtok(NULL, " ")) {
            current = atoi(token);
            if (current == previous)
                count++;
            else {
                if (previous != -1)
                    printf("%d %d ", count, previous);
                previous = current;
                count = 1;
            }
        }
        printf("%d %d\n", count, previous);
    }

    return 0;
}
