#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE   8*1024
#define MAX_CITIES  600

int cmp_ints(const void *i1, const void *i2) {
    return *(int *)i1 - *(int *)i2;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];
    int route[MAX_CITIES];
    int n_cities;

    while (fgets(line, LINE_SIZE, file)) {
        n_cities = 0;
        for (char *p=line; *p; p++) {
            if (*p == ',') {
                route[n_cities++] = atoi(p+1);
            }
        }

        qsort((void *)route, n_cities, sizeof(int), cmp_ints);

        printf("%d", route[0]);
        for (int i=1; i<n_cities; i++)
            printf(",%d", route[i] - route[i-1]);
        printf("\n");
    }

    return 0;
}
