#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char flag[3];
    char seq[50];

    while (fgets(line, 1024, file)) {
        char *p = line;
        unsigned int num = 0;
        while (sscanf(p, "%s %s", flag, seq) != EOF) {
            for (int i=0; i<strlen(seq); i++) {
                num <<= 1;
                if (strlen(flag) == 2)
                    num += 1;
            }
            p += strlen(flag) + strlen(seq) + 2;
        }
        printf("%ld\n", num);
    }

    return 0;
}
