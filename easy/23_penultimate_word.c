#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *p;

    while (fgets(line, 1024, file)) {
        p = rindex(line, ' ');
        if (p != (char *)NULL)
            *p = '\0';
        p = rindex(line, ' ');
        if (p != NULL)
        {
            printf("%s\n", p+1);
        }
        else
        {
            printf("%s\n", line);
        }
    }

    return 0;
}
