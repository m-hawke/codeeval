#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];

    while (fgets(line, 1024, file)) {
        float degrees = atof(line);
        float minutes = (degrees - (int)degrees) * 60;
        float seconds = (minutes - (int)minutes) * 60;
        printf("%d.%02d'%02d\"\n", (int)degrees, (int)minutes, (int)seconds);
    }

    return 0;
}
