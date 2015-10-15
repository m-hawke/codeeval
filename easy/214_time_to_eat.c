#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_SIZE       1024
#define MAX_TIMESTAMPS  20

int strcmp_reverse(const void *s1, const void *s2) {
    return -(strcmp(*(char **)s1, *(char **)s2));
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];
    char *token;
    int n_timestamps;
    char *timestamps[MAX_TIMESTAMPS];

    while (fgets(line, LINE_SIZE, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';

        n_timestamps = 0;
        for (token=strtok(line, " "); token!=NULL; token=strtok(NULL, " "))
            timestamps[n_timestamps++] = token;

        qsort((void *)timestamps, n_timestamps, sizeof(char *), strcmp_reverse);

        for (int i=0; i<n_timestamps; i++)
            printf("%s%s", (i==0) ? "" : " ", timestamps[i]);
        printf("\n");
    }

    return 0;
}
