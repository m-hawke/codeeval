#include <stdio.h>
#include <string.h>
#include <strings.h>

#define LINE_SIZE   1024

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_SIZE];

    while (fgets(line, LINE_SIZE, file)) {
        if (line[strlen(line)-1] == '\n')
            line[strlen(line)-1] = '\0';
        char *p = index(line, ',');
        int len_B = strlen(p+1);
        printf("%d\n", (strncmp(p-len_B, p+1, len_B) == 0));
    }

    return 0;
}
