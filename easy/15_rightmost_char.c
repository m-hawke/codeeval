#include <stdio.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];

    int idx;
    char *p;
    char t;
    char *S;

    while (fgets(line, 1024, file)) {
        idx = -1;
        p = strchr(line, ',');
        *p = '\0';
        t = *(p+1);
        S = line;
        
        if ((p = rindex(S, t)) != NULL)
            idx = p-S;

        printf("%d\n", idx);
    }
    return 0;
}

