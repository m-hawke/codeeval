#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_LEN    1024
#define MAX_NUMBERS 20

void stupid_sort(int numbers[], int n_numbers, int iterations) {
    for (int it=0; it<iterations; it++)
        for (int i=0; i<n_numbers-1; i++)
            if (numbers[i] > numbers[i+1]) {
                int tmp = numbers[i];
                numbers[i] = numbers[i+1];
                numbers[i+1] = tmp;
                break;
            }
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    char *token;
    int numbers[MAX_NUMBERS];

    while (fgets(line, LINE_LEN, file)) {
        char *p = strstr(line, " | ");
        int iterations = atoi(p+3);
        *p = '\0';

        int n = 0;
        for (token=strtok(line, " "); token!=NULL; token=strtok(NULL, " ")) {
            numbers[n++] = atoi(token);
        }

        stupid_sort(numbers, n, iterations);

        for (int i=0; i<n; i++)
            printf("%d ", numbers[i]);
        printf("\n");
    }

    return 0;
}
