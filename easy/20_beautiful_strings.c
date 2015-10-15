#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define N_ALPHAS    26

int reverse_cmp_ints(const void *i1, const void *i2) {
    int l, r;

    l = *(int *)i1;
    r = *(int *)i2;

    if (l < r)
        return 1;
    else if (l > r)
        return -1;
    else
        return 0;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int counts[N_ALPHAS+1];       /* last int is a sentinel */
    int values[N_ALPHAS];
    int sum = 0;

    for (int i=0; i<N_ALPHAS; i++)
        values[i] = N_ALPHAS-i;

    while (fgets(line, 1024, file)) {
        sum = 0;
        bzero(counts, sizeof(counts));

        for (int i=0; i<strlen(line); i++) {
            if (isalpha(line[i]))
                counts[tolower(line[i]) - 'a']++;
        }

        qsort((void *)counts, N_ALPHAS, sizeof(int), reverse_cmp_ints);

        for (int i=0; counts[i]; i++)
            sum += counts[i] * values[i];

        printf("%d\n", sum);
    }

    return 0;
}
