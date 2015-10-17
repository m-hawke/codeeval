#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];

    while (fgets(line, 1024, file)) {
        for (int i=0; i<strlen(line); i++)
            line[i] = tolower(line[i]);
        printf("%s", line);
    }
    return 0;
}

