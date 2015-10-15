#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];

    while (fgets(line, 1024, file)) {
        int is_first = 1;
        for (int i=0;i<strlen(line);i++) {
            if (is_first && (islower(line[i])))
                line[i] = toupper(line[i]);
            is_first = (line[i] == ' ');
        }
        printf("%s", line);
    }

    return 0;
}
