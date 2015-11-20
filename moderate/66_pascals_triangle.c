#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_LEN  1024
#define MAX_DEPTH 20
#define MAX_NUMBERS (MAX_DEPTH * (MAX_DEPTH + 1) / 2)

void get_pascals_triangle(int depth, int triangle[]) {
    /* Generate Pascal's triangle sequence from depth 1 to `depth`.
     * `triangle` will contain the triangle in row major form.
     * It is assumed that `triangle` is of adequate size which can be
     * calculated using n(n+1)/2 where n = depth.
     */
    int row[MAX_DEPTH+2] = {0};
    row[1] = 1;
    for (int d=1; d<=depth; d++) {
        memcpy(triangle, row+1, sizeof(int)*d);
        triangle += d;

        int tmp_row[MAX_DEPTH+2] = {0};
        for (int i=0; i<=d; i++) {
            tmp_row[i+1] = row[i] + row[i+1];
        }
        memcpy(row, tmp_row, sizeof(int)*(d+2));
    }
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    int triangle[MAX_NUMBERS];

    /* Precalculate the triangle to depth 20, the maximum size that we will be
       asked for. */
    get_pascals_triangle(MAX_DEPTH, triangle);

    while (fgets(line, LINE_LEN, file)) {
        int depth = atoi(line);
        for (int i=0; i<(depth*(depth+1)/2); i++)
            printf("%d ", triangle[i]);
        printf("\n");
    }

    return 0;
}
