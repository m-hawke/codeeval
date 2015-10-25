#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_LEN    1024
#define MAX_NUMBERS 100      /* guess based on sample input */

int sum(int *numbers, int n) {
    int sum_ = 0;
    for (int i=0; i<n; i++)
        sum_ += numbers[i];
    return sum_;
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    char *token;
    int numbers[MAX_NUMBERS];

    while (fgets(line, LINE_LEN, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        int n_numbers = 0;
        for (token=strtok(line, ","); token!=NULL; token=strtok(NULL, ",")) {
            numbers[n_numbers++] = atoi(token);
        }

        int max = sum(numbers, n_numbers);
        for (int length=1; length<n_numbers; length+=2) {   /* N.B. += 2 */
            int sum_ = sum(numbers, length);
            max = sum_ > max ? sum_ : max;
            for (int i=0; i<n_numbers-length; i++) {
                /* N.B. the following sum is also a sum of contiguous numbers
                 * for length + 1. We need calculate this once only, and
                 * therefore the length loop (see above) is incremented by 2
                 * each time. */
                sum_ += numbers[i+length];
                max = sum_ > max ? sum_ : max;
                sum_ -= numbers[i];
                max = sum_ > max ? sum_ : max;
            }
        }

        printf("%d\n", max);
    }

    return 0;
}
