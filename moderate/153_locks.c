#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE   1024

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];
    int N, M;

    while (fgets(line, LINE_SIZE, file)) {
        sscanf(line, "%d %d", &N, &M);

        int locked_doors = 0;
        int last_door_adjustment = +1;

        if (M > 1) {
            if ((M-1) % 2) {     // odd
                locked_doors = N/2 + N/3 - N/6 - N/6;
                if ((N%6) && ((N%2 == 0) || (N%3 == 0)))
                    last_door_adjustment = -1;
            }
            else {              // even
                locked_doors = N/2 - N/6;
                if ((N%6) && (N%2 == 0))
                    last_door_adjustment = -1;
            }
        }

        locked_doors += last_door_adjustment;
        printf("%d\n", N - locked_doors);
    }

    return 0;
}
