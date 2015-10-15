#include <stdio.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int x1, y1, x2, y2;

    while (fgets(line, 1024, file)) {
        sscanf(line, "(%d, %d) (%d, %d)", &x1, &y1, &x2, &y2);
        printf("%g\n", sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2)));
    }

    return 0;
}
