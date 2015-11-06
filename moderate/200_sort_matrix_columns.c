#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define LINE_LEN    1024
#define MAX_COL_LEN 15
#define MAX_ROW_LEN MAX_COL_LEN

typedef struct int_row {
    unsigned length;
    int values[MAX_ROW_LEN];
} INT_ROW;

int cmp_matrix_rows(const void *r1, const void *r2) {
    int *row1 = (int *)r1;
    int *row2 = (int *)r2;
    int rv;

    printf("cmp_matrix_rows(): comparing: row1 ");
    for (int i=0; i<matrix_size; i++)
        printf("%d ", row1[i]);
    printf(", row2 ");
    for (int i=0; i<matrix_size; i++)
        printf("%d ", row2[i]);
    printf("\n");

    for (int i=0; i<matrix_size; i++) {
        if ((rv = row1[i] - row2[i]) != 0)
            return rv;
    }

    return 0;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    int matrix_size;
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

//            printf("got segment '%s'\n", start);
            for (char *p=strtok(start, " "); p!=NULL; p=strtok(NULL, " ")) {
                matrix[row++][column] = atoi(p);    /* N.B. column-wise fill */
//                printf("set matrix[%d][%d] = %d\n", row-1, column, matrix[row-1][column]);
            }

            column++;
            start = end ? end + 3 : end;
        }
        matrix_size = column;

        printf("Got matrix of size %d\n", matrix_size);
        for (int i=0; i<matrix_size; i++) {
            for (int j=0; j<matrix_size; j++)
                printf("%d ", matrix[i][j]);
            printf("\n");
        }

        qsort(matrix, matrix_size, sizeof(int)*matrix_size, cmp_matrix_rows);

        printf("Sorted matrix of size %d\n", matrix_size);
        for (int i=0; i<matrix_size; i++) {
            for (int j=0; j<matrix_size; j++)
                printf("%d ", matrix[i][j]);
            printf("\n");
        }
    }

    return 0;
}
