#include <stdio.h>
#include <string.h>

#define MAX_ITEMS   30

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token;
    int n_items;
    char *items[MAX_ITEMS];
    char *tmp;
    int a, b;

    while (fgets(line, 1024, file)) {
        n_items = 0;
        for (token=strtok(line, " "); token!=NULL; token=strtok(NULL, " ")) {
            if (token[0] == ':')
                break;

            items[n_items++] = token;
        }

        /* N.B. only the strtok() separator has changed. strtok() is still
         * working from the current position in the same buffer as above */
        for (token=strtok(NULL, ", "); token!=NULL; token=strtok(NULL, ", ")) {
            sscanf(token, "%d-%d", &a, &b);
            tmp = items[a];
            items[a] = items[b];
            items[b] = tmp;
        }

        for (int i=0; i<n_items; i++)
            printf("%s%s", (i==0) ? "" : " ", items[i]);
        printf("\n");
    }

    return 0;
}
