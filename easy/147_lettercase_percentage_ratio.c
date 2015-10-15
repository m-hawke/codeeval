#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int uppercase, lowercase;
    float pc_lowercase;

    while (fgets(line, 1024, file)) {
        uppercase = lowercase = 0;
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';    // get rid of new line

        for (char *p=line; *p; p++) {
            if (islower(*p))
                lowercase++;
            else
                uppercase++;
        }
        pc_lowercase = ((float)lowercase / (lowercase + uppercase)) * 100;
        printf("lowercase: %.2f uppercase: %.2f\n", pc_lowercase, 100-pc_lowercase);
    }

    return 0;
}
