#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *token;
    int N;

    while (fgets(line, 1024, file)) {
        if (line[strlen(line)-1] == '\n')   /* get rid of new line */
            line[strlen(line)-1] = '\0';
        N = sqrt((strlen(line)+1) / 2);
        for (int i=0; i<N; i++)
            for (int j=N-1; j>=0; j--)
                printf("%c ", line[(N*j+i)*2]);
        printf("\n");
    }

    return 0;
}
