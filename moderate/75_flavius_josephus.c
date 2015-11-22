#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_LEN  1024

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];
    int n, m;

    while (fgets(line, LINE_LEN, file)) {
        sscanf(line, "%d,%d", &n, &m);
        int victims[n];     /* variable-sized array */
        for (int i=0; i<n; i++)
            victims[i] = i;

        int victim = 0;
        while (n > 0) {
            victim = (victim+m-1) % n;
            printf("%d ", victims[victim]);
            memmove(victims+victim, victims+(victim+1), (n-victim)*sizeof(int));
            n--;
        }
        printf("\n");
    }

    return 0;
}
