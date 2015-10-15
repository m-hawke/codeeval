#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int O, P, Q, R;
    int dx, dy;

    while (fgets(line, 1024, file)) {
        sscanf(line, "%d %d %d %d", &O, &P, &Q, &R);
        dx = Q - O;
        dy = R - P;

        if (dy > 0)
            printf("N");
        else if (dy < 0)
            printf("S");

        if (dx > 0)
            printf("E");
        else if (dx < 0)
            printf("W");

        if (dx == 0 && dy == 0)
            printf("here");

        printf("\n");
    }

    return 0;
}
