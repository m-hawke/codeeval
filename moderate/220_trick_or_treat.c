#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

#define LINE_LEN    1024

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[LINE_LEN];

    while (fgets(line, LINE_LEN, file)) {
        char *p = index(line, ':'); p+=2;
        int vampires = atoi(p);
        p = index(p, ':'); p+=2;
        int zombies = atoi(p);
        p = index(p, ':'); p+=2;
        int witches = atoi(p);
        p = index(p, ':'); p+=2;
        int houses = atoi(p);

        printf("%d\n", (vampires*3 + zombies*4 + witches*5) * houses /
                            (vampires + zombies + witches));
    }

    return 0;
}
