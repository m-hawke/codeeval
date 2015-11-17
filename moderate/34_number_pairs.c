#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_LEN    1024
#define MAX_NUMBERS 30      /* a bit of a guess */

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    char *token;
    int numbers[MAX_NUMBERS];

    while (fgets(line, LINE_LEN, file)) {
        char *p = strrchr(line, ';');
        *p = '\0';
        int target_sum = atoi(p+1);

        int n_numbers = 0;
        for (token=strtok(line, ","); token!=NULL; token=strtok(NULL, ",")) {
            numbers[n_numbers++] = atoi(token);
        }

        int print_delim = 0;
        for (int i=0; i<n_numbers-1; i++) {
            if (numbers[i] + numbers[i+1] > target_sum) {
            /* Because the number list is already sorted there is no point in
             * continuing if the sum of any 2 consecutive numbers exceeds the
             * target sum.
             */
                break;
            }

            for (int j=i+1; j<n_numbers; j++) {
                if (numbers[i] + numbers[j] == target_sum) {
                    print_delim = printf("%s%d,%d",
                                            print_delim ? ";" : "",
                                            numbers[i], numbers[j]);
                    break;
                }
            }
        }
        if (!print_delim)
            printf("NULL");
        printf("\n");
    }

    return 0;
}
