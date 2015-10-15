#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_DIGITS  10
#define MAX_PATTERN  MAX_DIGITS+1

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char digits[MAX_DIGITS+1];
    char pattern[MAX_PATTERN+1];
    char operand_1[MAX_DIGITS+1];
    int op_pos;

    while (fgets(line, 1024, file)) {
        if (line[strlen(line)-1] == '\n')   /* get rid of new line */
            line[strlen(line)-1] = '\0';

        sscanf(line, "%s %s", digits, pattern);
/*
        printf("digits '%s', pattern '%s'\n", digits, pattern);
*/

        op_pos = strcspn(pattern, "+-");
        strncpy(operand_1, digits, op_pos);
        operand_1[op_pos] = '\0';
/*
        printf("Got op = '%c', operand_1 = '%s' operand_2 = '%s'\n",
                    pattern[op_pos], operand_1, digits+op_pos);
*/
        if (pattern[op_pos] == '-')
            printf("%d\n", atol(operand_1) - atol(digits+op_pos));
        else
            printf("%d\n", atol(operand_1) + atol(digits+op_pos));
    }

    return 0;
}
