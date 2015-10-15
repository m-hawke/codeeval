#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include <math.h>

#define LINE_SIZE       1024
#define BUILDING_MARGIN 6

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];
    int l, d, n;

    while (fgets(line, LINE_SIZE, file)) {
        sscanf(line, "%d %d %d", &l, &d, &n);
        char *p = line;
        for (int i=0; i<3; i++) {
            /* skip the first 3 numbers already parsed above */
            p = index(p, ' ') + 1;
        }

        int n_bats = 0;
        int start = BUILDING_MARGIN;
        for (int i=0; i<n; i++) {
            int end = atoi(p);
            n_bats += (floor((end - start - d) / (float)d) + 1);
            start = end;
            p = index(p, ' ') + 1;
        }

        /* handle the final segment */
        int end = l - BUILDING_MARGIN;
        if (start <= end)
            n_bats += (floor((end - start) / (float)d) + 1);

        printf("%d\n", n_bats - n);
    }

    return 0;
}
