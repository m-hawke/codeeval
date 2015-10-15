#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BOARD_SIZE  256

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    char *cmd;
    int row_col, x;
    int i;
    int sum;

    while (fgets(line, 1024, file)) {
        sum = 0;

        sscanf(line, "%ms ", &cmd);
        if (!strncmp(cmd, "Set", 3))
            sscanf(line, "%*s %d %d", &row_col, &x);
        else
            sscanf(line, "%*s %d", &row_col);

        if (!strcmp(cmd, "SetRow"))
            for (i=0; i<BOARD_SIZE; i++)
                board[row_col][i] = x;
        else if (!strcmp(cmd, "SetCol"))
            for (i=0; i<BOARD_SIZE; i++)
                board[i][row_col] = x;
        else if (!strcmp(cmd, "QueryRow")) {
            for (i=0; i<BOARD_SIZE; i++)
                sum += board[row_col][i];
            printf("%d\n", sum);
        }
        else if (!strcmp(cmd, "QueryCol")) {
            for (i=0; i<BOARD_SIZE; i++)
                sum += board[i][row_col];
            printf("%d\n", sum);
        }

        free(cmd);
    }

    return 0;
}
