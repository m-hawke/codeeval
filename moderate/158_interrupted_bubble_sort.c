#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_SIZE   1024
#define MAX_NUMBERS 30      /* a guestimate */

void interrupted_bubble_sort(int numbers[], int n_numbers, int passes) {
    int tmp;

    if (n_numbers < passes)
        passes = n_numbers;

    for (int i=0; i<passes; i++) {
        for (int j=0; j<n_numbers-i-1; j++) {
            if (numbers[j] > numbers[j+1]) {
                tmp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = tmp;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];
    char *token;
    int numbers[MAX_NUMBERS];

    while (fgets(line, LINE_SIZE, file)) {
        char *p = strrchr(line, '|');
        *p++ = '\0';
        int passes = atoi(p);

        int n_numbers = 0;
        for (token=strtok(line, " "); token!=NULL; token=strtok(NULL, " ")) {
            numbers[n_numbers++] = atoi(token);
        }

        interrupted_bubble_sort(numbers, n_numbers, passes);

        for (int i=0; i<n_numbers; i++)
            printf("%s%d", (i==0) ? "" : " ", numbers[i]);
        printf("\n");
    }

    return 0;
}
