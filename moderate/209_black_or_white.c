#include <stdio.h>
#include <string.h>
#include <math.h>

#define LINE_LEN        1024
#define MAX_MATRIX_SIZE 25

/* Iterate over all sub matrices of size n, checking that the number of ones
 * (blacks) is the same for all sub matrix. Assumes that matrix is a square
 * matrix. */
int check_sub_matrices(char matrix[], int matrix_size, int n) {
    int expected_blacks = -1;
    int n_blacks = 0;

    for (int i=0; i<matrix_size+1-n; i++)
        for (int j=0; j<matrix_size+1-n; j++) {
            for (int row=0; row<n; row++)
                for (int x=((i+row)*matrix_size+j);
                     x<(i+row)*matrix_size+j+n; x++) {
                    if (matrix[x] == '1')
                        n_blacks++;
                }
            if (expected_blacks == -1)            /* first time, set expected */
                expected_blacks = n_blacks;
            else if (n_blacks != expected_blacks) /* subsequent time, check */
                return -1;
            n_blacks = 0;
        }

    return expected_blacks;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    int n_blacks;
    int matrix_size;
    char matrix[MAX_MATRIX_SIZE*MAX_MATRIX_SIZE+1];

    while (fgets(line, LINE_LEN, file)) {
        int matrix_length = 0;
        for (int i=0; i<strlen(line); i++)
            if ((line[i] == '0') || (line[i] == '1'))
                matrix[matrix_length++] = line[i];
            matrix[matrix_length] = '\0';
        matrix_size = sqrt(matrix_length);
        for (int n=1; n<=matrix_size; n++)
            if ((n_blacks = check_sub_matrices(matrix, matrix_size, n)) != -1) {
                printf("%dx%d, %d\n", n, n, n_blacks);
                break;
            }
    }

    return 0;
}
