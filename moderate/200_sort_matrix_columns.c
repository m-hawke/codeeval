#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_LEN    1024
#define MAX_COL_LEN 15
#define MAX_ROW_LEN MAX_COL_LEN

static int matrix_size;

int cmp_matrix_rows(const void *r1, const void *r2) {
    int *row1 = (int *)r1;
    int *row2 = (int *)r2;
    int rv;

    for (int i=0; i<matrix_size; i++) {
        if ((rv = row1[i] - row2[i]) != 0)
            return rv;
    }

    return 0;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    int matrix[MAX_ROW_LEN][MAX_COL_LEN];

    while (fgets(line, LINE_LEN, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        int row, column = 0;

        char *start = line;
        char *end;
        while (start) {
            row = 0;
            end = strstr(start, " | ");
            if (end)
                *end = '\0';

            for (char *p=strtok(start, " "); p!=NULL; p=strtok(NULL, " ")) {
                matrix[row++][column] = atoi(p);    /* N.B. column-wise fill */
            }

            column++;
            start = end ? end + 3 : end;
        }
        matrix_size = column;

        qsort(matrix, matrix_size, sizeof(int)*MAX_COL_LEN, cmp_matrix_rows);

        /* Display each column separated by " | " */
        for (column=0; column<matrix_size; column++) {
            if (column > 0)
                printf(" | ");
            for (row=0; row<matrix_size; row++)
                printf("%s%d", (row > 0) ? " " : "", matrix[row][column]);
        }
        printf("\n");
    }

    return 0;
}
