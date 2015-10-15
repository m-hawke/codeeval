#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_KEYS    101
#define LINE_SIZE   20*1024

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];
    char *token;

    while (fgets(line, LINE_SIZE, file)) {
        int counts[MAX_KEYS] = {0};
        int n_items = 0;

        for (token=strtok(line, ","); token!=NULL; token=strtok(NULL, ",")) {
            counts[atoi(token)]++;
            n_items++;
        }

        /* find the entry with the highest count */
        int max_count = 0;
        int major_element = -1;
        for (int i=0; i<MAX_KEYS; i++) {
            if (counts[i] > max_count) {
                max_count = counts[i];
                major_element = i;
            }
        }

        if (counts[major_element] > (n_items/2))
            printf("%d\n", major_element);
        else
            printf("None\n");
    }

    return 0;
}
