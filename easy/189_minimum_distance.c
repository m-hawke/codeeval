#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_SIZE   1024
#define MAX_HOUSES  100

int cmp_ints(const void *i1, const void *i2) {
    return *(int *)i1 - *(int *)i2;
}

int sum_of_diffs(int ints[], int n_ints, int value) {
    int sum = 0;
    for (int i=0; i<n_ints; i++)
        sum += abs(value - ints[i]);
    return sum;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];
    char *token;
    int n_houses;
    int houses[MAX_HOUSES];
    int median;

    while (fgets(line, LINE_SIZE, file)) {
        n_houses = 0;
        strtok(line, " ");  /* first value is the number of houses, ignore */
        for (token=strtok(NULL, " "); token!=NULL; token=strtok(NULL, " ")) {
            houses[n_houses++] = atoi(token);
        }

        qsort((void *)houses, n_houses, sizeof(int), cmp_ints);

        /* Calculate the median house "address". It is assumed that the optimal
         * house is less than the median. */
        int mid = n_houses / 2;
        if (n_houses % 2)    /* odd */
            median = houses[mid];
        else
            median = (houses[mid-1] + houses[mid]) / 2;

        int diff = sum_of_diffs(houses, n_houses, median);
        int i = median - 1;
        while (i >= 0) {
            int next_diff = sum_of_diffs(houses, n_houses, i);
            if (diff < next_diff)
                break;
            diff = next_diff;
            i--;
        }

        printf("%d\n", diff);
    }

    return 0;
}
